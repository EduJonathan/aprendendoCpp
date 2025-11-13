#include <iostream>
#include <iomanip>
#include <random>

/**
 * std::student_t_distribution
 * ----------------------------
 * Parecida com a normal, mas com caudas, caudas são valores extremos mais prováveis.
 *
 * É usada quando o tamanho da amostra é pequeno.
 *
 * Ideal para:
 * - Testes estatísticos com poucos dados
 * - Estimativas de médias com incerteza
 */

static std::mt19937 motor(std::random_device{}());

double gerarStudentT(int grausLiberdade)
{
    std::student_t_distribution<double> dist(grausLiberdade);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::student_t_distribution<double> dist(10.0); // 10 graus de liberdade

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const int df = 10;

    double valor = gerarStudentT(df);
    std::cout << std::fixed << std::setprecision(3)
              << "Valor t de Student simulado: " << valor
              << " (df=" << df << ")\n";
    return 0;
}
