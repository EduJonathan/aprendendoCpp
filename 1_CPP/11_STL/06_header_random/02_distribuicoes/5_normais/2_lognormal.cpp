#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::lognormal_distribution
 * ----------------------------
 * Os logaritmos dos valores seguem uma distribuição normal.
 *
 * Os valores são sempre positivos e têm uma cauda longa à direita.
 *
 * Ideal para:
 * - Modelar rendas, preços, tempos de execução
 * - Situações onde o crescimento é multiplicativo
 */

static std::mt19937 motor(std::random_device{}());

double gerarLogNormal(double media, double desvio)
{
    std::lognormal_distribution<double> dist(media, desvio);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::lognormal_distribution<double> dist(0.0, 0.25);

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const double media = 0.0;
    const double desvio = 0.25;

    double valor = gerarLogNormal(media, desvio);
    std::cout << std::fixed << std::setprecision(3)
              << "Valor lognormal simulado: " << valor
              << " (média=" << media << ", desvio=" << desvio << ")\n";
    return 0;
}
