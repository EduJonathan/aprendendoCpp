#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::weibull_distribution
 * --------------------------
 * Usada para modelar tempos de vida ou falhas.
 *
 * Dependendo dos parâmetros, pode representar diferentes comportamentos:
 * - Taxa de falha constante, crescente ou decrescente.
 *
 * Ideal para:
 * - Análise de confiabilidade e durabilidade
 * - Simulações de tempo de vida de componentes
 */

static std::mt19937 motor(std::random_device{}());

double tempoAteFalha(double forma, double escala)
{
    std::weibull_distribution<double> dist(forma, escala);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::weibull_distribution<double> dist(2.0, 1.0);

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const double forma = 1.5;  // k → define o formato da curva (k>1: falhas crescentes)
    const double escala = 100; // λ → escala média de vida

    double tempo = tempoAteFalha(forma, escala);
    std::cout << std::fixed << std::setprecision(2)
              << "Tempo simulado até a falha: " << tempo
              << " (forma=" << forma << ", escala=" << escala << ")\n";
    return 0;
}
