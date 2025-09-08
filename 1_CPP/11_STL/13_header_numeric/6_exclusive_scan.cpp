#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * std::exclusive_scan(param x, param y, param z): Realiza um prefixo exclusivo,
 * produzindo somas parciais que não incluem o elemento atual. Introduzido no C++17.
 */

int main(int argc, char **argv)
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result(v.size());

    std::exclusive_scan(v.begin(), v.end(), result.begin(), 0);

    std::cout << "Prefixo exclusivo: ";
    for (int n : result)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}
