#include <iostream>
#include <cmath>

// std::pow(): Realiza a pontenciação de um valor.

int main(int argc, char **argv)
{
    std::cout << std::pow(40.0, 2) << '\n'; /* std::pow => Para tipos double */
    std::cout << powf(5.0f, 4) << '\n';     /* powf => Para tipos float */
    std::cout << powl(40.0l, 3) << '\n';    /* powl => Para tipos lond double */
    return 0;
}
