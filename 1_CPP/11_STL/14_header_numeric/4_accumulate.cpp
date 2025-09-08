#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

/**
 * std::accumulate(param x, param y, param z): Permite acumular valores, como somar
 * todos os elementos de um vetor.
 */

/**
 * @brief Lambda que acumula o somatório dos quadrados dos elementos de um vetor
 *
 * @param v Vetor de inteiros
 * @return int Somatório dos quadrados dos elementos
 */
std::function<int(const std::vector<int> &)> lambda_sum_of_squares = [](const std::vector<int> &v) -> int
{
    return std::accumulate(v.begin(), v.end(), 0, [](int acc, int val)
    {
        return acc + val * val;
    });
};

int main(int argc, char **argv)
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "A soma é: " << sum << '\n';

    std::vector<int> nums = {1, 2, 3, 4};

    std::cout << "Soma dos quadrados: " << lambda_sum_of_squares(nums) << std::endl; // Output: 30 (1^2 + 2^2 + 3^2 + 4^2)

    return 0;
}
