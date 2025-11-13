#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::exponential_distribution
 * ------------------------------
 * Modela o tempo entre dois eventos que seguem uma taxa constante.
 *
 * Exemplo: tempo até o próximo cliente chegar.
 *
 * Ideal para:
 * - Simular tempos de espera
 * - Modelar intervalos entre eventos raros
 */

static std::mt19937 motor(std::random_device{}());

double gerarTempoExponencial(double taxaLambda)
{
    std::exponential_distribution<double> dist(taxaLambda);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<double> dist(1.5); // λ = 1.5

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const double lambda = 1.5; // taxa média de 1.5 eventos por unidade de tempo

    double tempo = gerarTempoExponencial(lambda);
    std::cout << std::fixed << std::setprecision(3)
              << "Tempo até o próximo evento: " << tempo << " (λ = " << lambda << ")\n";

    return 0;
}
