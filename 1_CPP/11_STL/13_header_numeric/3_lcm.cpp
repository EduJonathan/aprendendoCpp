#include <iostream>
#include <numeric>
#include <algorithm>

// std::lcm(param x, param y): Calcula o Mínimo Múltiplo Comum entre dois números.

int main(int argc, char **argv)
{
    int a = 12, b = 15;
    int lcm = std::lcm(a, b);

    std::cout << "O LMC de " << a << " e " << b << " é: " << lcm << '\n';
    return 0;
}
