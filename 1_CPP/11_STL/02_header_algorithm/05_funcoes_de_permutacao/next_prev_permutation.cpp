#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Gera permutações lexicográficas crescentes ou decrescentes de um vetor de caracteres.
 *
 * - std::next_permutation(begin, end)
 *   → Gera a próxima permutação lexicográfica crescente.
 *
 * - std::prev_permutation(begin, end)
 *   → Gera a permutação lexicográfica anterior.
 *
 * @param vec Vetor de caracteres a ser permutado.
 * @param crescente Indica se a ordem será crescente (true) ou decrescente (false).
 */
void gerarPermutacoes(std::vector<char> &vec, bool crescente)
{
    // Lambda para imprimir o vetor
    auto imprimirVetor = [](const std::vector<char> &v)
    {
        for (char c : v)
        {
            std::cout << c << ' ';
        }
        std::cout << '\n';
    };

    if (crescente)
    {
        std::cout << "Permutações em ordem crescente:\n";

        std::sort(vec.begin(), vec.end()); // Garante a ordem inicial

        do
        {
            imprimirVetor(vec);
        } while (std::next_permutation(vec.begin(), vec.end()));
    }
    else
    {
        std::cout << "Permutações em ordem decrescente:\n";

        std::sort(vec.begin(), vec.end(), std::greater<>()); // Ordena decrescentemente

        do
        {
            imprimirVetor(vec);
        } while (std::prev_permutation(vec.begin(), vec.end()));
    }
}

int main(int argc, char **argv)
{
    std::vector<char> v = {'a', 'b', 'c'};

    gerarPermutacoes(v, true); // Permutações crescentes
    std::cout << '\n';
    gerarPermutacoes(v, false); // Permutações decrescentes

    std::cout << "----------------------------------------------\n";

    std::vector<int> vec = {1, 2, 3};

    std::cout << "Permutações crescentes (números):\n";
    std::sort(vec.begin(), vec.end()); // Ordem inicial

    do
    {
        for (int n : vec)
        {
            std::cout << n << ' ';
        }
        std::cout << '\n';
    } while (std::next_permutation(vec.begin(), vec.end()));

    std::cout << "\nPermutações decrescentes (números):\n";
    std::sort(vec.begin(), vec.end(), std::greater<>());

    do
    {
        for (int n : vec)
        {
            std::cout << n << ' ';
        }
        std::cout << '\n';
    } while (std::prev_permutation(vec.begin(), vec.end()));

    return 0;
}
