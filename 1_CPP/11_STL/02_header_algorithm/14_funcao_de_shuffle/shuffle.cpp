#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>

/**
 * - std::shuffle(begin, end, engine)
 *   → Embaralha aleatoriamente os elementos do intervalo (begin, end).
 *
 * - std::random_device
 *   → Fonte de sementes aleatórias reais para inicializar geradores.
 *
 * - std::mt19937
 *   → Gerador de números pseudoaleatórios de alta qualidade (Mersenne Twister).
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

    // Gerador aleatório estático
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // Escolhe aleatoriamente a carta a ser "encontrada"
    std::uniform_int_distribution<> dis(0, cartas.size() - 1);
    int indiceCartaSecreta = dis(gen);
    std::string cartaSecreta = cartas[indiceCartaSecreta];

    // Embaralha as cartas
    std::shuffle(cartas.begin(), cartas.end(), gen);

    // Mostra apenas posições (sem revelar cartas)
    std::cout << "As cartas foram embaralhadas!\n";
    std::cout << "Tente adivinhar em qual posição está a carta \"" << cartaSecreta << "\".\n";
    std::cout << "Escolha um número de 1 a 4: ";

    int escolha = 0;
    while (true)
    {
        if (std::cin >> escolha && escolha >= 1 && escolha <= 4)
            break;
        std::cerr << "Escolha inválida! Digite um número de 1 a 4: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Verifica se acertou
    if (cartas[escolha - 1] == cartaSecreta)
    {
        std::cout << "Parabéns! Você encontrou a carta \"" << cartaSecreta << "\"!\n";
    }
    else
    {
        std::cout << "Errado! A carta \"" << cartaSecreta << "\" estava na posição "
                  << (std::find(cartas.begin(), cartas.end(), cartaSecreta) - cartas.begin() + 1)
                  << ".\n";
    }

    // Mostra a ordem final das cartas
    std::cout << "Cartas embaralhadas: ";
    for (auto &c : cartas)
        std::cout << c << ' ';
    std::cout << '\n';
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
