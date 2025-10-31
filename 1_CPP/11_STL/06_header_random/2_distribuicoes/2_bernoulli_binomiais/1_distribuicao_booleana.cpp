#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <random>

enum class Feriado
{
    HALLOWEEN,
    NATAL,
    CARNAVAL,
    DIA_DAS_MAES,
    DIA_DOS_PAIS,
    ANO_NOVO,
    PASCOA
};

struct Holiday
{
    Feriado festividade;
    int month; // 1 a 12
    int day;   // dia aproximado (ou médio)
    std::string name;
    double prob_acontecer; // 0.0 a 1.0
};

// Lista de feriados (com datas aproximadas)
const std::vector<Holiday> holidays = {
    {Feriado::HALLOWEEN, 10, 31, "Halloween", 1.0},
    {Feriado::NATAL, 12, 25, "Natal", 1.0},
    {Feriado::CARNAVAL, 2, 13, "Carnaval", 0.9},         // pode ser adiado
    {Feriado::DIA_DAS_MAES, 5, 8, "Dia das Mães", 1.0},  // 2º domingo de maio
    {Feriado::DIA_DOS_PAIS, 8, 11, "Dia dos Pais", 1.0}, // 2º domingo de agosto
    {Feriado::ANO_NOVO, 1, 1, "Ano Novo", 1.0},
    {Feriado::PASCOA, 4, 5, "Páscoa", 0.95} // varia, mas abril
};

// 1. Escolher feriado aleatoriamente
Holiday escolherFeriado()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, static_cast<int>(holidays.size()) - 1);
    return holidays[dist(gen)];
}

// 2. Probabilidade de acontecer este ano
bool vaiAcontecer(const Holiday &h)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dist(h.prob_acontecer);
    return dist(gen);
}

// 3. Calcular data do feriado no ano atual ou próximo
std::tm criarDataFeriado(const Holiday &h, int ano)
{
    std::tm data = {};
    data.tm_year = ano - 1900;
    data.tm_mon = h.month - 1;
    data.tm_mday = h.day;
    data.tm_hour = 12; // meio-dia
    data.tm_min = 0;
    data.tm_sec = 0;
    data.tm_isdst = -1;

    // Normaliza com mktime
    std::mktime(&data);
    return data;
}

// 4. Calcular dias até o feriado
int diasAteFeriado(const Holiday &h)
{
    auto agora = std::chrono::system_clock::now();
    auto tp_agora = std::chrono::time_point_cast<std::chrono::hours>(agora);
    auto tt_agora = std::chrono::system_clock::to_time_t(tp_agora);
    std::tm local_agora = *std::localtime(&tt_agora);

    int ano_atual = local_agora.tm_year + 1900;

    // Tenta este ano
    std::tm data_este_ano = criarDataFeriado(h, ano_atual);
    auto tp_este_ano = std::chrono::system_clock::from_time_t(std::mktime(&data_este_ano));

    if (tp_este_ano > agora)
    {
        auto diff = tp_este_ano - agora;
        return std::chrono::duration_cast<std::chrono::hours>(diff).count() / 24;
    }

    // Senão, próximo ano
    std::tm data_prox_ano = criarDataFeriado(h, ano_atual + 1);
    auto tp_prox_ano = std::chrono::system_clock::from_time_t(std::mktime(&data_prox_ano));
    auto diff = tp_prox_ano - agora;
    return std::chrono::duration_cast<std::chrono::hours>(diff).count() / 24;
}

// 5. Exibir data no formato dd/mm/aaaa
std::string formatarData(const std::tm &data)
{
    std::ostringstream oss;
    oss << std::put_time(&data, "%d/%m/%Y");
    return oss.str();
}

int main(int argc, char **argv)
{
    std::cout << "=== SORTEIO DE FERIADO ===\n\n";

    // 1. Escolher feriado
    Holiday selected = escolherFeriado();
    std::cout << "Feriado sorteado: " << selected.name << '\n';

    // 2. Probabilidade de acontecer
    bool acontece = vaiAcontecer(selected);
    if (!acontece)
    {
        std::cout << "Este ano não vai rolar! (azar...)\n\n";
        return 0;
    }
    std::cout << "Vai acontecer este ano!\n";

    // 3. Calcular dias restantes
    int dias_restantes = diasAteFeriado(selected);
    std::cout << "Faltam " << dias_restantes << " dias!\n";

    // 4. Mostrar data estimada
    auto agora = std::chrono::system_clock::now();
    auto tt = std::chrono::system_clock::to_time_t(agora);
    std::tm local = *std::localtime(&tt);
    int ano = local.tm_year + 1900;

    std::tm data_feriado = criarDataFeriado(selected, ano);
    auto tp_feriado = std::chrono::system_clock::from_time_t(std::mktime(&data_feriado));

    if (tp_feriado < agora)
    {
        data_feriado = criarDataFeriado(selected, ano + 1);
    }

    std::cout << "Data estimada: " << formatarData(data_feriado) << '\n';

    // 5. É em dezembro?
    bool em_dezembro = (selected.month == 12);
    std::cout << "É em dezembro? " << (em_dezembro ? "Sim" : "Não") << "\n\n";

    // Mensagem final divertida
    if (dias_restantes <= 7)
    {
        std::cout << "CORRA! Tá chegando!\n";
    }
    else if (dias_restantes <= 30)
    {
        std::cout << "Já pode ir planejando!\n";
    }
    else
    {
        std::cout << "Calma, tem tempo...\n";
    }

    return 0;
}
