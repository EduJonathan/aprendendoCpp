#include <iostream>
#include <cstdlib>

// std::strtof(): Função de conversão para ponto flutuante.

int main(int argc, char **argv)
{
    const char *str_float = "123.45";
    const char *str_double = "9876.54321";
    const char *str_long_double = "1234567.1234567";

    // Usando strtof para converter para float
    float f = std::strtof(str_float, nullptr);
    std::cout << "strtof: " << f << '\n';

    // Usando strtod para converter para double
    double d = std::strtod(str_double, nullptr);
    std::cout << "strtod: " << d << '\n';

    // Usando strtold para converter para long double
    long double ld = std::strtold(str_long_double, nullptr);
    std::cout << "strtold: " << ld << '\n';

    return 0;
}
