#include <iostream>
#include <cmath>

// std::copysign(): Copia o sinal de um número e atribui à magnitude de outro.

int main(int argc, char **argv)
{
    std::cout << "copysign(5.5, -3.2): " << std::copysign(5.5, -3.2) << '\n';       // Para tipo double
    std::cout << "copysignf(5.5F, -3.2F): " << std::copysignf(5.5F, -3.2F) << '\n'; // Para tipo float
    std::cout << "copysignl(5.5L, -3.2L): " << std::copysignl(5.5L, -3.2L) << '\n'; // Para tipo long double

    // Exemplos com sinal positivo
    std::cout << "copysign(5.5, 3.2): " << std::copysign(5.5, 3.2) << '\n';       // Para tipo double
    std::cout << "copysignf(5.5F, 3.2F): " << std::copysignf(5.5F, 3.2F) << '\n'; // Para tipo float
    std::cout << "copysignl(5.5L, 3.2L): " << std::copysignl(5.5L, 3.2L) << '\n'; // Para tipo long double

    return 0;
}
