#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/*
 * std::iota(param x, param y, param z): Preenchimento de Intervalo, preenche
 * um intervalo com valores consecutivos.
 */

int main(int argc, char **argv)
{
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 1); // Preenche com valores de 1 a 10

    std::cout << "Valores preenchidos com std::iota: ";
    for (int n : v)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    return 0;
}
