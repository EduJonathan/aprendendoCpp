#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::max(a, b, ...)
 *   → Retorna o maior valor entre dois ou mais valores.
 *
 * - std::min(a, b, ...)
 *   → Retorna o menor valor entre dois ou mais valores.
 */

/**
 * @brief Retorna o maior entre três números inteiros.
 *
 * @param num1 Primeiro número.
 * @param num2 Segundo número.
 * @param num3 Terceiro número.
 * @return O maior valor entre os três.
 */
auto maiorDeTresNumeros(int num1, int num2, int num3) -> int
{
    return std::max({num1, num2, num3});
}

/**
 * @brief Retorna o menor entre dois números reais.
 *
 * @param num1 Primeiro número.
 * @param num2 Segundo número.
 * @return O menor valor entre os dois.
 */
double menorDeDoisNumeros(double num1, double num2) { return std::min(num1, num2); }

/**
 * @brief Retorna o menor valor presente em um vetor de inteiros.
 *
 * @param v Vetor de inteiros.
 * @return Menor valor do vetor.
 */
int encontrarMenorValor(const std::vector<int> &v)
{
    return *std::min_element(v.begin(), v.end());
}

/**
 * @brief Retorna o maior valor presente em um vetor de inteiros.
 *
 * @param v Vetor de inteiros.
 * @return Maior valor do vetor.
 */
int encontrarMaiorValor(const std::vector<int> &v)
{
    return *std::max_element(v.begin(), v.end());
}

int main(int argc, char **argv)
{
    std::cout << ">>> Funções clássicas:\n";
    std::cout << "Maior número (10, 20, 5): " << maiorDeTresNumeros(10, 20, 5) << '\n';
    std::cout << "Menor número (10, 5): " << menorDeDoisNumeros(10, 5) << '\n';

    std::vector<int> v = {3, 1, 7, 2};
    std::cout << "Menor valor no vetor: " << encontrarMenorValor(v) << '\n';
    std::cout << "Maior valor no vetor: " << encontrarMaiorValor(v) << '\n';

    std::cout << "\n>>> Versões com lambdas:\n";

    auto lambdaMaiorDeTres = [](int a, int b, int c)
    {
        return std::max({a, b, c});
    };

    auto lambdaMenorDeDois = [](double a, double b)
    {
        return std::min(a, b);
    };

    auto lambdaMenorValor = [](const std::vector<int> &vec)
    {
        return *std::min_element(vec.begin(), vec.end());
    };

    auto lambdaMaiorValor = [](const std::vector<int> &vec)
    {
        return *std::max_element(vec.begin(), vec.end());
    };

    std::vector<int> valores = {3, 8, 1, 5, 10, 6};

    std::cout << "Maior de três (10, 20, 15): " << lambdaMaiorDeTres(10, 20, 15) << '\n';
    std::cout << "Menor de dois (3.5, 2.8): " << lambdaMenorDeDois(3.5, 2.8) << '\n';
    std::cout << "Menor valor no vetor: " << lambdaMenorValor(valores) << '\n';
    std::cout << "Maior valor no vetor: " << lambdaMaiorValor(valores) << '\n';

    return 0;
}
