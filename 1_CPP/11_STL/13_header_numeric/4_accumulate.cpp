#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * std::accumulate(param x, param y, param z): Permite acumular valores, como somar
 * todos os elementos de um vetor.
 */

int main(int argc, char **argv)
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "A soma é: " << sum << '\n';
    return 0;
}
