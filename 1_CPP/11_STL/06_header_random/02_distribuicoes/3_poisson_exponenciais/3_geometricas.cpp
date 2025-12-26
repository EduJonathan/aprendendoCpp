#include <iostream>
#include <random>

/**
 * std::geometric_distribution
 * ----------------------------
 * Gera o número de tentativas até o primeiro sucesso,
 * em ensaios independentes com uma probabilidade fixa.
 *
 * Exemplo: quantas vezes jogar uma moeda até sair cara.
 *
 * Ideal para:
 * - Simular repetições até o sucesso
 * - Processos que “reiniciam” até algo acontecer
 */

static std::mt19937 motor(std::random_device{}());

int tentativasAteSucesso(double p)
{
    std::geometric_distribution<int> dist(p);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::geometric_distribution<int> dist(0.25); // p = 0.25

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const double p = 0.3; // probabilidade de sucesso em cada tentativa

    int tentativas = tentativasAteSucesso(p);
    std::cout << "Tentativas até o primeiro sucesso: " << tentativas
              << " (p = " << p << ")\n";
    return 0;
}
