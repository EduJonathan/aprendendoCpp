#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::extreme_value_distribution
 * --------------------------------
 * Modela o valor máximo (ou mínimo) entre várias observações.
 *
 * Exemplo: temperatura mais alta do ano ou maior nível de enchente.
 *
 * Ideal para:
 * - Estudos de valores extremos (meteorologia, engenharia)
 * - Simular “picos” ou “eventos raros” muito altos
 */

static std::mt19937 motor(std::random_device{}());

double valorExtremo(double media, double escala)
{
    std::extreme_value_distribution<double> dist(media, escala);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::extreme_value_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const double media = 50.0; // valor central esperado
    const double escala = 5.0; // controla dispersão

    double valor = valorExtremo(media, escala);
    std::cout << std::fixed << std::setprecision(2)
              << "Valor extremo simulado: " << valor
              << " (média=" << media << ", escala=" << escala << ")\n";
    return 0;
}
