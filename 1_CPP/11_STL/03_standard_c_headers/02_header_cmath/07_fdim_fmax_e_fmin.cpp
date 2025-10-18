#include <iostream>
#include <cmath>

/**
 * Operações com valores de ponto flutuante
 * 
 * std::fdim(): Retorna a diferença x - y, mas somente se x > y.
 * std::fmax(): Retorna o maior valor entre x e y.
 * std::fmin(): Retorna o menor valor entre x e y
 */

int main(int argc, char **argv)
{
    // Usando std::fdim
    std::cout << "fdim(5.5, 3.2): " << std::fdim(5.5, 3.2) << '\n';       // Para tipo double
    std::cout << "fdimf(5.5F, 3.2F): " << std::fdimf(5.5F, 3.2F) << '\n'; // Para tipo float
    std::cout << "fdiml(5.5L, 3.2L): " << std::fdiml(5.5L, 3.2L) << '\n'; // Para tipo long double

    // Usando std::fmax
    std::cout << "\nfmax(5.5, 3.2): " << std::fmax(5.5, 3.2) << '\n';     // Para tipo double
    std::cout << "fmaxf(5.5F, 3.2F): " << std::fmaxf(5.5F, 3.2F) << '\n'; // Para tipo float
    std::cout << "fmaxl(5.5L, 3.2L): " << std::fmaxl(5.5L, 3.2L) << '\n'; // Para tipo long double

    // Usando std::fmin
    std::cout << "\nfmin(5.5, 3.2): " << std::fmin(5.5, 3.2) << '\n';     // Para tipo double
    std::cout << "fminf(5.5F, 3.2F): " << std::fminf(5.5F, 3.2F) << '\n'; // Para tipo float
    std::cout << "fminl(5.5L, 3.2L): " << std::fminl(5.5L, 3.2L) << '\n'; // Para tipo long double

    return 0;
}
