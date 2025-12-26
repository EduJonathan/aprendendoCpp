#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <random>

/**
 * std::bernoulli_distribution
 * ----------------------------
 * Gera valores booleanos (true ou false) baseados em uma probabilidade.
 *
 * Exemplo: se a probabilidade for 0.3, há 30% de chance de sair "true".
 *
 * Ideal para:
 * - Simular eventos de sucesso/fracasso
 * - Decisões aleatórias com base em chance
 */

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

struct ProximoFeriado
{
    int dias_restantes;
    std::tm data;
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
ProximoFeriado diasAteFeriado(const Holiday &h)
{
    using namespace std::chrono;

    auto agora = system_clock::now();
    auto tt_agora = system_clock::to_time_t(agora);
    std::tm local_agora = *std::localtime(&tt_agora);
    int ano_atual = local_agora.tm_year + 1900;

    std::tm data_este_ano = criarDataFeriado(h, ano_atual);
    auto tp_este_ano = system_clock::from_time_t(std::mktime(&data_este_ano));

    // Se ainda vai acontecer este ano
    if (tp_este_ano > agora)
    {
        auto diff = duration_cast<hours>(tp_este_ano - agora).count() / 24;
        return {static_cast<int>(diff), data_este_ano};
    }

    // Caso contrário, próximo ano
    std::tm data_prox_ano = criarDataFeriado(h, ano_atual + 1);
    auto tp_prox_ano = system_clock::from_time_t(std::mktime(&data_prox_ano));
    auto diff = duration_cast<hours>(tp_prox_ano - agora).count() / 24;
    return {static_cast<int>(diff), data_prox_ano};
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

    Holiday selected = escolherFeriado();
    std::cout << "Feriado sorteado: " << selected.name << '\n';

    if (!vaiAcontecer(selected))
    {
        std::cout << "Este ano não vai rolar! (azar...)\n";
        return 0;
    }

    ProximoFeriado info = diasAteFeriado(selected);

    std::cout << "Vai acontecer em " << (info.data.tm_year + 1900) << "!\n";
    std::cout << "Faltam " << info.dias_restantes << " dias!\n";
    std::cout << "Data estimada: " << formatarData(info.data) << '\n';
    std::cout << "É em dezembro? " << (selected.month == 12 ? "Sim" : "Não") << "\n\n";

    if (info.dias_restantes <= 7)
        std::cout << "CORRA! Tá chegando!\n";
    else if (info.dias_restantes <= 30)
        std::cout << "Já pode ir planejando!\n";
    else
        std::cout << "Calma, tem tempo...\n";

    return 0;
}
