#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * std::inclusive_scan(param x, param y, param z): Similar ao std::exclusive_scan,
 * mas inclui o elemento atual no cálculo da soma.
 */

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

    return 0;
}
