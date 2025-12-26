#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::gamma_distribution
 * ------------------------
 * Representa o tempo até a ocorrência de vários eventos.
 *
 * É uma soma de variáveis exponenciais — generaliza a distribuição exponencial.
 *
 * Ideal para:
 * - Simular tempos acumulados até N eventos
 * - Modelos de espera e risco
 */

static std::mt19937 motor(std::random_device{}());

double tempoAcumulado(double forma, double escala)
{
    std::gamma_distribution<double> dist(forma, escala);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::gamma_distribution<double> dist(2.0, 2.0); // α=2, β=2

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const double forma = 3.0;  // número médio de eventos acumulados
    const double escala = 2.0; // tempo médio por evento

    double tempo = tempoAcumulado(forma, escala);
    std::cout << std::fixed << std::setprecision(3)
              << "Tempo total acumulado: " << tempo
              << " (forma=" << forma << ", escala=" << escala << ")\n";
    return 0;
}
