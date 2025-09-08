#include <iostream>
#include <cmath>

// std::pow(): Realiza a pontenciação de um valor.

int main(int argc, char **argv)
{
    std::cout << std::pow(40.0, 2) << '\n';   /* std::pow => Para tipos double */
    std::cout << std::powf(40.0f, 2) << '\n'; /* std::powf => Para tipos float */
    std::cout << std::powl(40.0l, 4) << '\n'; /* std::powl => Para tipos lond double */
    return 0;
}
