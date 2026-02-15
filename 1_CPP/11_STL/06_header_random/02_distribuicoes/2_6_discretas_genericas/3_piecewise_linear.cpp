#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

/**
 * std::piecewise_linear_distribution
 * -----------------------------------
 * Semelhante à anterior, mas os pesos variam de forma **linear**.
 *
 * Os intervalos são definidos com probabilidades que mudam de um ponto a outro.
 *
 * Ideal para:
 * - Simular curvas de probabilidade personalizadas
 * - Criar distribuições com tendências suaves
 */

static std::mt19937 motor(std::random_device{}());

double gerarPiecewiseLinear(const std::vector<double> &x,
                            const std::vector<double> &y)
{
    std::piecewise_linear_distribution<double> dist(x.begin(), x.end(), y.begin());
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<double> intervals{0.0, 1.0, 2.0, 3.0};
    std::vector<double> weights{0.0, 1.0, 0.0};

    std::piecewise_linear_distribution<double> dist(intervals.begin(), intervals.end(), weights.begin());

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';
        
    std::cout << "============================================" << '\n';

    // Pontos x definem limites; y define o peso relativo em cada ponto
    std::vector<double> x = {0.0, 2.0, 5.0, 8.0};
    std::vector<double> y = {1.0, 3.0, 2.0, 0.5};

    double valor = gerarPiecewiseLinear(x, y);
    std::cout << std::fixed << std::setprecision(2)
              << "Valor piecewise linear: " << valor << '\n';
    return 0;
}
