#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

/**
 * std::exclusive_scan(param x, param y, param z): Realiza um prefixo exclusivo,
 * produzindo somas parciais que não incluem o elemento atual. Introduzido no C++17.
 */

/**
 * @brief Realiza uma soma acumulada exclusiva em um vetor de inteiros.
 *
 * A soma acumulada exclusiva não inclui o elemento atual. Por exemplo, para
 * entrada {1, 2, 3}, a saída será {0, 1, 3}.
 *
 * @param v Vetor de inteiros de entrada.
 * @return std::vector<int> Vetor com os valores acumulados.
 */
std::function<std::vector<int>(const std::vector<int> &)> lambda_exclusive_scan =
    [](const std::vector<int> &v) -> std::vector<int>
{
    std::vector<int> result(v.size());
    std::exclusive_scan(v.begin(), v.end(), result.begin(), 0);
    return result;
};

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

    std::vector<int> input = {1, 2, 3, 4};
    std::vector<int> scanned = lambda_exclusive_scan(input);

    std::cout << "Exclusive scan: ";
    for (int n : scanned)
        std::cout << n << ' ';
    std::cout << '\n';
    return 0;
}
