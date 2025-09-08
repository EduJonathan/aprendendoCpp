#include <iostream>
#include <numeric>
#include <algorithm>

// std::clamp(param x, param y, param z): Limita um valor dentro de um intervalo especificado.

int main(int argc, char **argv)
{
    int value = 15;
    int clampedValue = std::clamp(value, 10, 20);

    // O valor está dentro do intervalo [10, 20], então a função std::clamp retorna o próprio valor 15.
    std::cout << "Valor dentro do intervalo [10, 20]: " << clampedValue << '\n';

    int valor = 21;
    int cValue = std::clamp(valor, 10, 20);

    /**
     * O valor 21 está fora do intervalo [10, 20], portanto, a função std::clamp
     * retorna o valor máximo do intervalo, que é 20.
     */
    std::cout << "Valor dentro do intervalo [10, 20]: " << cValue << '\n';
    return 0;
}
