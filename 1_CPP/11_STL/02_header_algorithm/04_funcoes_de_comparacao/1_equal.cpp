#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

/**
 * - std::equal(begin1, end1, begin2)
 *   → Verifica se dois intervalos são iguais elemento a elemento.
 *
 * - std::equal_to<T>
 *   → Predicado binário para testar igualdade entre dois valores do tipo T.
 *
 * @note std::equal_range() não compara intervalos; retorna o intervalo onde um valor
 * pode ser inserido em um range ordenado.
 */

/**
 * @brief Retorna uma expressão lambda para comparação de igualdade entre inteiros.
 *
 * @return std::function<bool(int, int)> Lambda que compara dois inteiros.
 */
auto isEqual() -> std::function<bool(int, int)>
{
    return [](int a, int b)
    {
        return a == b;
    };
}

int main(int argc, char **argv)
{
    std::vector<char> vec1 = {'A', 'B', 'C'};
    std::vector<char> vec2 = {'D', 'E', 'F'};

    // Comparação padrão entre dois ranges
    if (std::equal(vec1.begin(), vec1.end(), vec2.begin()))
    {
        std::cout << "Os ranges são iguais (comparação padrão).\n";
    }
    else
    {
        std::cout << "Os ranges NÃO são iguais (comparação padrão).\n";
    }

    // Comparação personalizada usando lambda
    auto Equality = isEqual();

    // vec1 = {'A', 'B', 'C'} → ASCII = {65, 66, 67}
    std::vector<int> vec3 = {65, 66, 67};
    if (std::equal(vec1.begin(), vec1.end(), vec3.begin(), Equality))
    {
        std::cout << "Os ranges são iguais (usando lambda de comparação).\n";
    }
    else
    {
        std::cout << "Os ranges NÃO são iguais (usando lambda de comparação).\n";
    }

    return 0;
}
