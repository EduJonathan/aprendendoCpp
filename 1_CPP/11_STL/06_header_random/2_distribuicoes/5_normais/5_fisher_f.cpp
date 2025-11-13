#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::fisher_f_distribution
 * ---------------------------
 * Modela a razão entre duas variâncias.
 *
 * É usada em análises estatísticas como ANOVA.
 *
 * Ideal para:
 * - Testar igualdade de variâncias
 * - Modelos de regressão e variância
 */

static std::mt19937 motor(std::random_device{}());

double gerarFisherF(int df1, int df2)
{
    std::fisher_f_distribution<double> dist(df1, df2);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::fisher_f_distribution<double> dist(5.0, 2.0);

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const int df1 = 5;  // graus de liberdade do numerador
    const int df2 = 10; // graus de liberdade do denominador

    double valor = gerarFisherF(df1, df2);
    std::cout << std::fixed << std::setprecision(3)
              << "Valor F simulado: " << valor
              << " (df1=" << df1 << ", df2=" << df2 << ")\n";
    return 0;
}
