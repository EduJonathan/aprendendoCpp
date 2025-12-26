#include <iostream>
#include <type_traits>

/**
 * decltype é uma keyword do C++ que permite deduzir o tipo de uma expressão em tempo de compilação.
 * Diferente de typeid, que retorna informações sobre o tipo em tempo de execução,
 * decltype é avaliado em tempo de compilação.
 */

int main(int argc, char **argv)
{
    int x = 42;
    decltype(x) y = x + 1; // y é do mesmo tipo que x, ou seja, int
    std::cout << "Valor de y: " << y << '\n';

    double a = 3.14;
    decltype(a) b = a * 2.0; // b é do mesmo tipo que a, ou seja, double
    std::cout << "Valor de b: " << b << '\n';

    decltype(x + a) c = x + a; // c é do tipo da expressão x + a, que é double
    std::cout << "Valor de c: " << c << '\n';

    return 0;
}
