#include <iostream>
#include <cmath>

// std::sqrt(): Encontra a raiz quadrada de um valor.

int main(int argc, char **argv)
{
    std::cout << std::sqrt(40.0) << '\n'; /* std::sqrt => Para tipos double */
    std::cout << sqrtf(40.0f) << '\n';    /* sqrtf => Para tipos float */
    std::cout << sqrtl(40.0l) << '\n';    /* sqrtl => Para tipos lond double */
    return 0;
}
