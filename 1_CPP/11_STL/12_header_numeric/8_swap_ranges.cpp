#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

// std::swap_ranges(param x, param y, param z): Troca os elementos de dois intervalos de containers.

/**
 * @brief Troca os elementos de dois vetores usando std::swap_ranges.
 *
 * Esta função lambda troca os valores de dois vetores de mesmo tamanho,
 * elemento por elemento.
 *
 * @param a Vetor A (será modificado).
 * @param b Vetor B (será modificado).
 */
std::function<void(std::vector<int> &, std::vector<int> &)> lambda_swap_ranges =
    [](std::vector<int> &a, std::vector<int> &b)
{
    std::swap_ranges(a.begin(), a.end(), b.begin());
};

int main(int argc, char **argv)
{
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};

    std::swap_ranges(v1.begin(), v1.end(), v2.begin());

    std::cout << "Elementos de v1 após troca: ";
    for (int n : v1)
    {
        std::cout << n << ' ';
    }

    std::cout << "\nElementos de v2 após troca: ";
    for (int n : v2)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {10, 20, 30};

    lambda_swap_ranges(v1, v2);

    std::cout << "v1: ";
    for (int n : v1)
        std::cout << n << ' ';
    std::cout << "\nv2: ";

    for (int n : v2)
        std::cout << n << ' ';
    std::cout << '\n';
    return 0;
}
