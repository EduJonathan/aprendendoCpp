#include <iostream>
#include <cmath>

/**
 * std::nearbyint(): Realiza o arredondamento do valor flutuante que esteja mais
 * próximo ao inteiro.
 */

int main(int argc, char **argv)
{
    std::cout << std::nearbyint(2.3) << '\n';     /* std::nearbyint => Para tipos double */
    std::cout << std::nearbyintf(3.5F) << '\n';   /* std::nearbyintf => Para tipos float */
    std::cout << std::nearbyintl(-40.1L) << '\n'; /* std::nearbyintl => Para tipos lond double */
    return 0;
}
