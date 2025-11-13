#include <iostream>
#include <vector>
#include <random>

/**
 * std::discrete_distribution
 * ---------------------------
 * Gera valores inteiros com probabilidades personalizadas.
 *
 * Cada número tem uma chance específica definida por você.
 *
 * Ideal para:
 * - Sortear itens com pesos diferentes
 * - Simular escolhas com chances desiguais
 */

static std::mt19937 motor(std::random_device{}());

int gerarValorDiscreto(const std::vector<double> &pesos)
{
    std::discrete_distribution<int> dist(pesos.begin(), pesos.end());
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<int> dist({10, 20, 30, 40}); // pesos

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';
        
    std::cout << "============================================" << '\n';

    // Pesos indicam a chance relativa de cada valor (0, 1, 2, 3)
    std::vector<double> pesos = {0.5, 0.3, 0.15, 0.05};

    int valor = gerarValorDiscreto(pesos);
    std::cout << "Valor discreto sorteado: " << valor << "\n";
    return 0;
}
