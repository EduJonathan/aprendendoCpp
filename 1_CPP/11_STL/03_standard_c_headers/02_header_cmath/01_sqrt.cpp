#include <iostream>
#include <cmath>

// std::sqrt(): Encontra a raiz quadrada de um valor.

int main(int argc, char **argv)
{
    std::cout << std::sqrt(40.0) << '\n';   /* std::sqrt => Para tipos double */
    std::cout << std::sqrtf(40.0f) << '\n'; /* std::sqrtf => Para tipos float */
    std::cout << std::sqrtl(40.0l) << '\n'; /* std::sqrtl => Para tipos lond double */
    return 0;
}
