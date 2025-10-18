#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

/**
 * std::inclusive_scan(param x, param y, param z): Similar ao std::exclusive_scan,
 * mas inclui o elemento atual no cálculo da soma.
 */

/**
 * @brief Realiza uma soma acumulada inclusiva em um vetor de inteiros.
 *
 * A soma acumulada inclusiva inclui o elemento atual. Por exemplo, para
 * entrada {1, 2, 3}, a saída será {1, 3, 6}.
 *
 * @param v Vetor de inteiros de entrada.
 * @return std::vector<int> Vetor com os valores acumulados.
 */
std::function<std::vector<int>(const std::vector<int> &)> lambda_inclusive_scan =
    [](const std::vector<int> &v) -> std::vector<int>
{
    std::vector<int> result(v.size());
    std::inclusive_scan(v.begin(), v.end(), result.begin());
    return result;
};

int main(int argc, char **argv)
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result(v.size());

    std::inclusive_scan(v.begin(), v.end(), result.begin());

    std::cout << "Prefixo inclusivo: ";
    for (int n : result)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::vector<int> input = {1, 2, 3, 4};
    std::vector<int> scanned = lambda_inclusive_scan(input);

    std::cout << "Inclusive scan: ";
    for (int n : scanned)
        std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}
