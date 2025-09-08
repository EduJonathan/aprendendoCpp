#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>

// std::gcd(param x, param y): Calcula o Maior Divisor Comum (MDC) entre dois números.

/**
 * @brief Função lambda para calcular o GCD (Greatest Common Divisor)
 * usando o Algoritmo de Euclides.
 * 
 * @param a Primeiro número
 * @param b Segundo número
 * @return int O GCD de a e b
 */
std::function<int(int, int)> lambda_gcd = [](int a, int b) -> int
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
};

int main(int argc, char **argv)
{
    std::cout << "O resultado entre 4 e 10 de acordo com std::gcd é: " << std::gcd(4, 10) << '\n';
    std::cout << "O resultado entre 5 e 20 de acordo com lambda é: " << lambda_gcd(5, 20) << '\n';
    return 0;
}
