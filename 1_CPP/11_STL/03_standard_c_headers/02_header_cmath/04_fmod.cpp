#include <iostream>
#include <cmath>

// std::fmod(): Calcula o módulo (%) de dois valores.

int main(int argc, char **argv)
{
    std::cout << std::fmod(2, 4) << '\n';          /* std::fmod => Para tipos double */
    std::cout << std::fmodf(3.5F, 3.0F) << '\n';   /* std::fmodf => Para tipos float */
    std::cout << std::fmodl(40.1L, 40.1L) << '\n'; /* std::fmodl => Para tipos lond double */
    return 0;
}
