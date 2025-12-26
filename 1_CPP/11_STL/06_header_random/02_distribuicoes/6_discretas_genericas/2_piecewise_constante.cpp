#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

/**
 * std::piecewise_constant_distribution
 * -------------------------------------
 * Define intervalos de valores contínuos, onde cada intervalo tem
 * uma probabilidade constante (peso fixo).
 *
 * Ideal para:
 * - Criar distribuições não uniformes simples
 * - Simulações onde certos intervalos são mais prováveis
 */

static std::mt19937 motor(std::random_device{}());

double gerarPiecewiseConstante(const std::vector<double> &limites, const std::vector<double> &pesos)
{
    std::piecewise_constant_distribution<double> dist(
        limites.begin(), limites.end(), pesos.begin());
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<double> intervals{0.0, 1.0, 2.0, 3.0};
    std::vector<double> weights{1.0, 2.0, 3.0};

    std::piecewise_constant_distribution<double> dist(intervals.begin(), intervals.end(), weights.begin());

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    // Três intervalos: [0,1), [1,3), [3,5) com pesos diferentes
    std::vector<double> limites = {0.0, 1.0, 3.0, 5.0};
    std::vector<double> pesos = {2.0, 1.0, 3.0};

    double valor = gerarPiecewiseConstante(limites, pesos);
    std::cout << std::fixed << std::setprecision(2)
              << "Valor piecewise constante: " << valor << "\n";
    return 0;
}
