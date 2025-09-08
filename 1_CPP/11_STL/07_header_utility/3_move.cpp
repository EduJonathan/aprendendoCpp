#include <iostream>
#include <string>
#include <utility>

/**
 * std::move(): É utilizado para transferir a posse de recursos entre objetos de forma
 * eficiente, sem copiar os dados, eficiente ao evitar cópias desnecessárias, funciona
 * com objetos que podem ser movidos, como strings, vetores, etc.
 */

int main(int argc, char **argv)
{
    std::string original = "Texto original";
    std::string moved = std::move(original);

    std::cout << "Movido: " << moved << '\n';
    std::cout << "Original (após mover): " << original << '\n';
    return 0;
}
