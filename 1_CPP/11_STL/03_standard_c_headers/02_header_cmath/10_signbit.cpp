#include <iostream>
#include <limits>
#include <cmath>

/**
 * A função std::signbit(x) verifica se um número possui sinal negativo, retornando:
 * true → se x for negativo, mesmo que seja -0.0, -inf ou -NaN
 * false → se x for positivo, incluindo +0.0, +inf ou +NaN
 * Importante: std::signbit não testa o valor numérico (se é maior que 0 ou menor que 0), apenas o bit de sinal.
 */

int main(int argc, char **argv)
{
    std::cout << "Demonstração do std::signbit:\n\n";

    // Exemplos de valores com sinal positivo
    double positivos[] = {
        1.0,
        +0.0,
        std::numeric_limits<double>::infinity(),
        std::nan(""), // NaN positivo
    };

    // Exemplos de valores com sinal negativo
    double negativos[] = {
        -1.0,
        -0.0,
        -std::numeric_limits<double>::infinity(),
        -std::nan(""), // NaN negativo
    };

    std::cout << "Valores positivos:\n";
    for (double val : positivos)
    {
        std::cout << "  Valor: " << val
                  << " | sinal negativo? " << std::boolalpha << std::signbit(val) << '\n';
    }

    std::cout << "\nValores negativos:\n";
    for (double val : negativos)
    {
        std::cout << "  Valor: " << val
                  << " | sinal negativo? " << std::boolalpha << std::signbit(val) << '\n';
    }

    return 0;
}
