#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::normal_distribution
 * -------------------------
 * Gera números com distribuição normal (curva de sino).
 *
 * A maioria dos valores fica próxima da média, e poucos são extremos.
 *
 * Ideal para:
 * - Simular medições reais (erros, alturas, pesos)
 * - Modelos estatísticos e aprendizado de máquina
 */

static std::mt19937 motor(std::random_device{}());

double gerarNormal(double media, double desvio)
{
    std::normal_distribution<double> dist(media, desvio);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const double media = 0.0;
    const double desvio = 1.0;

    double valor = gerarNormal(media, desvio);
    std::cout << std::fixed << std::setprecision(3)
              << "Valor normal simulado: " << valor
              << " (média=" << media << ", desvio=" << desvio << ")\n";
    return 0;
}
