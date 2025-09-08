#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>

/**
 * - `std::shuffle()`: Embaralha elementos em um intervalo aleatoriamente.
 * - `std::random_device`: Gera sementes aleatórias reais.
 * - `std::mt19937`: Gerador de números pseudoaleatórios de alta qualidade (Mersenne Twister).
 */

/**
 * @brief Embaralha os elementos de um vetor de inteiros.
 *
 * @param v Vetor a ser embaralhado.
 */
void embaralharVetor(std::vector<int> &v)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::shuffle(v.begin(), v.end(), gen);
}

/**
 * @brief Embaralha as cartas e executa uma rodada de jogo.
 */
void jogoCartas(void)
{
    std::vector<std::string> cartas = {"AS", "JACK", "DIAMOND", "JOKER"};

    // Gerador aleatório estático para manter estado
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // Embaralha as cartas
    std::shuffle(cartas.begin(), cartas.end(), gen);

    // Solicita escolha do usuário
    int escolha = 0;
    std::cout << "\nEscolha um número de 1 a 4 para pegar a carta: ";
    std::cin >> escolha;

    if (escolha < 1 || escolha > 4)
    {
        std::cerr << "Escolha inválida! O número deve ser entre 1 e 4.\n";
        return;
    }

    std::string cartaEscolhida = cartas[escolha - 1];

    // Verifica resultado
    if (cartaEscolhida == "JOKER")
    {
        std::cout << "Você pegou o JOKER! Perdeu o jogo!\n";
    }
    else
    {
        std::cout << "Você pegou a carta \"" << cartaEscolhida << "\". Você venceu!\n";
    }
}

int main(int argc, char **argv)
{
    // Demonstração de embaralhamento de inteiros
    std::vector<int> numeros = {1, 2, 3, 4, 5};
    embaralharVetor(numeros);

    std::cout << "Vetor embaralhado: ";
    for (int n : numeros)
    {
        std::cout << n << ' ';
    }

    std::cout << "\n=================================\n";

    // Executa o jogo das cartas
    jogoCartas();

    return 0;
}
