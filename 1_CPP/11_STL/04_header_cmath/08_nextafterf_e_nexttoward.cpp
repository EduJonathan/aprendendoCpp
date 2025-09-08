#include <iostream>
#include <cmath>

/**
 * std::nextafter, std::nexttoward(): Calcula o próximo valor representável em direção a outro valor.
 */

int main(int argc, char **argv)
{
    // Usando std::nextafter
    std::cout << "nextafter(5.5, 3.2): " << std::nextafter(5.5, 3.2) << '\n';       // Para tipo double
    std::cout << "nextafterf(5.5F, 3.2F): " << std::nextafterf(5.5F, 3.2F) << '\n'; // Para tipo float
    std::cout << "nextafterl(5.5L, 3.2L): " << std::nextafterl(5.5L, 3.2L) << '\n'; // Para tipo long double

    // Usando std::nexttoward
    std::cout << "nexttoward(5.5, 3.2L): " << std::nexttoward(5.5, 3.2L) << '\n';     // Para tipo double com long double
    std::cout << "nexttowardf(5.5F, 3.2L): " << std::nexttowardf(5.5F, 3.2L) << '\n'; // Para tipo float com long double
    std::cout << "nexttowardl(5.5L, 3.2L): " << std::nexttowardl(5.5L, 3.2L) << '\n'; // Para tipo long double

    return 0;
}
