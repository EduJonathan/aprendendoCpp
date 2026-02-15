#include <iostream>
#include <random>

/**
 * std::binomial_distribution
 * ---------------------------
 * Modela o número de sucessos em um certo número de tentativas,
 * onde cada tentativa tem a mesma probabilidade de sucesso.
 *
 * Exemplo: número de caras ao jogar uma moeda 10 vezes.
 *
 * Ideal para:
 * - Simular resultados de vários testes independentes
 * - Modelar eventos que ocorrem com probabilidade constante
 */

static std::mt19937 motor(std::random_device{}());

int simularEventosRaros(int n, double p)
{
    std::binomial_distribution<int> dist(n, p);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::binomial_distribution<int> dist(10, 0.5); // 10 tentativas, p=0.5

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const int n = 10000;     // muitas tentativas
    const double p = 0.0003; // baixa probabilidade

    int eventos = simularEventosRaros(n, p);
    std::cout << "Eventos raros observados: " << eventos << " (λ ≈ " << n * p << ")\n";
    return 0;
}
