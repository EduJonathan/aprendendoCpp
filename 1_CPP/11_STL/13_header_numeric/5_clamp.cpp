#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>

// std::clamp(param x, param y, param z): Limita um valor dentro de um intervalo especificado.

/**
 * @brief Lambda que aplica std::clamp em todos os elementos do vetor.
 *
 * @param v Vetor de inteiros a ser processado.
 * @param min_val Valor mínimo do intervalo.
 * @param max_val Valor máximo do intervalo.
 * @return std::vector<int> Novo vetor com os valores limitados dentro do intervalo [min_val, max_val].
 */
std::function<std::vector<int>(const std::vector<int> &, int, int)> lambda_clamp_vector =
    [](const std::vector<int> &v, int min_val, int max_val) -> std::vector<int>
{
    std::vector<int> result;
    result.reserve(v.size());

    for (int val : v)
    {
        result.push_back(std::clamp(val, min_val, max_val));
    }
    return result;
};

int main(int argc, char **argv)
{
    int value = 15;
    int clampedValue = std::clamp(value, 10, 20);

    // O valor está dentro do intervalo [10, 20], então a função std::clamp retorna o próprio valor 15.
    std::cout << "Valor dentro do intervalo [10, 20]: " << clampedValue << '\n';

    int valor = 21;
    int cValue = std::clamp(valor, 10, 20);

    /**
     * O valor 21 está fora do intervalo [10, 20], portanto, a função std::clamp
     * retorna o valor máximo do intervalo, que é 20.
     */
    std::cout << "Valor dentro do intervalo [10, 20]: " << cValue << '\n';

    std::vector<int> input = {-10, 0, 5, 15, 30};
    int min_limit = 0;
    int max_limit = 20;

    std::vector<int> clamped = lambda_clamp_vector(input, min_limit, max_limit);

    std::cout << "Valores clampados: ";
    for (int val : clamped)
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    return 0;
}
