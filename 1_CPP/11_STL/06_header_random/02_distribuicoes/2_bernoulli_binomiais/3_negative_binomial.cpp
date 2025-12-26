#include <iostream>
#include <random>

/**
 * std::negative_binomial_distribution
 * -----------------------------------
 * Gera o número de falhas antes de ocorrer um certo número de sucessos.
 *
 * Exemplo: quantas vezes um jogador erra antes de acertar 3 vezes.
 *
 * Ideal para:
 * - Simulações com eventos repetidos até atingir uma meta
 * - Modelar tempo até o sucesso em processos aleatórios
 */

static std::mt19937 motor(std::random_device{}());

int simularFalhasAteSucesso(int r, double p)
{
    std::negative_binomial_distribution<int> dist(r, p);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::negative_binomial_distribution<int> dist(5, 0.4);

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const int r = 5;      // sucessos desejados
    const double p = 0.7; // probabilidade de sucesso

    int falhas = simularFalhasAteSucesso(r, p);
    std::cout << "Falhas antes de " << r << " sucessos: " << falhas << '\n';
    return 0;
}
