#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// std::swap_ranges(param x, param y, param z): Troca os elementos de dois intervalos de containers.

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
    return 0;
}
