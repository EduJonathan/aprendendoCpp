#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * - std::swap(): Troca dois elementos individualmente.
 * - std::swap_ranges(): Troca intervalos (ranges) inteiros entre containers.
 */

/**
 * @brief Troca os elementos entre dois vetores de strings, se forem do mesmo tamanho.
 *
 * @param vec1 Primeiro vetor de strings.
 * @param vec2 Segundo vetor de strings.
 */
void swapStrings(std::vector<std::string> &vec1, std::vector<std::string> &vec2)
{
    if (vec1.size() != vec2.size())
    {
        std::cout << "Os vetores não têm o mesmo tamanho.\n";
        return;
    }

    // Realiza a troca usando std::swap_ranges (mais idiomático do que um loop manual)
    std::swap_ranges(vec1.begin(), vec1.end(), vec2.begin());
}

int main(int argc, char **argv)
{
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};

    if (v1.size() == v2.size())
    {
        std::swap_ranges(v1.begin(), v1.end(), v2.begin());

        std::cout << "v1: ";

        for (int val : v1)
        {
            std::cout << val << ' ';
        }

        std::cout << "\nv2: ";

        for (int val : v2)
        {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }
    else
    {
        std::cout << "Os vetores não têm o mesmo tamanho.\n";
    }

    std::cout << "======================================" << '\n';

    std::vector<std::string> vector1 = {"apple", "banana", "cherry"};
    std::vector<std::string> vector2 = {"dog", "elephant", "frog"};

    swapStrings(vector1, vector2);

    std::cout << "vector1: ";
    for (const auto &val : vector1)
    {
        std::cout << val << ' ';
    }

    std::cout << "\nvector2: ";
    for (const auto &val : vector2)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    return 0;
}
