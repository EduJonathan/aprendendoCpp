#include <iostream>
#include <cmath>

/*
 * std::scalbn(): Multiplica o número de ponto flutuante por uma potência de 2.
 *
 * std::scalbln(): Multiplica o número de ponto flutuante por uma potência de 2, 
 * baseado no expoente `n`
 */

int main(int argc, char **argv)
{
    std::cout << std::scalbn(2.3, 3) << '\n';      /* std::scalbn => Para tipos double */
    std::cout << std::scalbnf(3.5F, 4) << '\n';    /* std::scalbnf => Para tipos float */
    std::cout << std::scalbnl(-40.1L, -2) << '\n'; /* std::scalbnl => Para tipos long double */

    std::cout << '\n';
    std::cout << std::scalbln(2.3, 3) << '\n';      /* std::scalbln => Para tipos double */
    std::cout << std::scalblnf(3.5F, 4) << '\n';    /* std::scalblnf => Para tipos float */
    std::cout << std::scalblnl(-40.1L, -2) << '\n'; /* std::scalblnl => Para tipos long double */
    return 0;
}
