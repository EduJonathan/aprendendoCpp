#include <iostream>
#include <cmath>

// std::nan(): Gera um valor NaN (Not a Number).

int main(int argc, char **argv)
{
    // Usando std::nan para tipos double, float e long double
    std::cout << "nan() (double): " << std::nan("") << '\n';        // Para tipo double
    std::cout << "nanf() (float): " << std::nanf("") << '\n';       // Para tipo float
    std::cout << "nanl() (long double): " << std::nanl("") << '\n'; // Para tipo long double

    // Verificando se é NaN usando std::isnan
    double nan_value = std::nan("");
    if (std::isnan(nan_value))
    {
        std::cout << "nan_value é NaN!\n";
    }
    return 0;
}
