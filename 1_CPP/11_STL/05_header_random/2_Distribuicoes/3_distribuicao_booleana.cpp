#include <iostream>
#include <random>
#include <vector>
#include <string>

struct Holiday
{
    std::string name;
    int month; // 1 = janeiro, 12 = dezembro
};

int main(int argc, char **argv)
{
    // Lista de feriados (exemplo)
    std::vector<Holiday> holidays = {
        {"Natal", 12},          // Dezembro
        {"Páscoa", 4},          // Abril (aproximado)
        {"Dia do Trabalho", 5}, // Maio
        {"Independência", 9},   // Setembro
        {"Ano Novo", 1}         // Janeiro
    };

    // Configurar gerador de números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, holidays.size() - 1);

    // Escolher um feriado aleatoriamente
    int index = dist(gen);
    const Holiday &selected_holiday = holidays[index];

    // Verificar se o feriado está em dezembro
    bool is_in_december = (selected_holiday.month == 12);

    // Exibir resultado
    std::cout << "Feriado selecionado: " << selected_holiday.name << '\n';
    std::cout << "É em dezembro? " << (is_in_december ? "Sim" : "Não") << '\n';

    // Usar distribuição booleana para uma decisão adicional (exemplo)
    std::bernoulli_distribution bool_dist(0.5); // 50% de chance
    bool celebrate = bool_dist(gen);
    std::cout << "Vamos celebrar este feriado? "
              << (celebrate ? "Sim" : "Não") << '\n';

    return 0;
}
