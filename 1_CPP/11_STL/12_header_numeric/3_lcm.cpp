#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

// std::lcm(param x, param y): Calcula o Mínimo Múltiplo Comum entre dois números.

/**
 * @brief Função lambda para calcular o LCM (Least Common Multiple)
 * usando a relação entre LCM e GCD (Greatest Common Divisor).
 * 
 * @param a Primeiro número
 * @param b Segundo número
 * @return int O LCM de a e b
 */
std::function<int(int, int)> lambda_lcm = [](int a, int b) -> int
{
    return (a / std::gcd(a, b)) * b;
};

int main(int argc, char **argv)
{
    int a = 12, b = 15;
    int lcm = std::lcm(a, b);

    std::cout << "O LMC de " << a << " e " << b << " é: " << lcm << '\n';

    a = 5, b = 7;
    lcm = lambda_lcm(a, b);
    std::cout << "O LMC de " << a << " e " << b << " é: " << lcm << '\n';
    return 0;
}
