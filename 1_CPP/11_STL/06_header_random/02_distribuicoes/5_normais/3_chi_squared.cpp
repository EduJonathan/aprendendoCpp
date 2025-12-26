#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::chi_squared_distribution
 * ------------------------------
 * Usada em estatística para medir a variação entre dados observados e esperados.
 *
 * É a soma dos quadrados de variáveis normais.
 *
 * Ideal para:
 * - Testes de hipóteses (qui-quadrado)
 * - Análise de variância
 */

static std::mt19937 motor(std::random_device{}());

double gerarChiQuadrado(int grausLiberdade)
{
    std::chi_squared_distribution<double> dist(grausLiberdade);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::chi_squared_distribution<double> dist(4.0);

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const int df = 5; // graus de liberdade

    double valor = gerarChiQuadrado(df);
    std::cout << std::fixed << std::setprecision(3)
              << "Valor qui-quadrado simulado: " << valor
              << " (df=" << df << ")\n";
    return 0;
}
