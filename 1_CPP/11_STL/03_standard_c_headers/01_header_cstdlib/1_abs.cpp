#include <iostream>
#include <cstdlib>

// std::abs(): Retorna o valor absoluto de um número.

int main(int argc, char **argv)
{
    long num = -457874l;
    long long n = -5684ll;

    std::cout << std::abs(-6) << '\n';   /* abs: Valor absoluto para tipos int */
    std::cout << std::labs(num) << '\n'; /* labs: Valor absoluto para tipos long */
    std::cout << std::llabs(n) << '\n';  /* llabs: Valor absoluto para tipos long long */

    return 0;
}
