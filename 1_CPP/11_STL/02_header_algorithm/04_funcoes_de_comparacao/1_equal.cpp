#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

/**
 * @brief Demonstra o uso de funções de comparação da STL.
 *
 * - std::equal(): Compara dois intervalos para verificar se são iguais elemento a elemento.
 * - std::equal_to: Usado como predicado binário para verificar igualdade.
 *
 * @note `std::equal_range()` não é para comparação de ranges! Ela retorna o intervalo onde
 * um valor pode ser inserido em um range ordenado. Foi confundida na explicação anterior.
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
