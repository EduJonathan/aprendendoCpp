#include <iostream>
#include <vector>
#include <type_traits>
#include <cassert>
#include <ranges>

/**
 * std::ranges::contiguous_range(): Um *contiguous_range* é uma extensão de `random_access_range`
 * onde os elementos estão garantidamente armazenados de forma **contígua na memória**, como em
 * arrays C.
 *
 * Características:
 * - Permite acesso aleatório com `[]`, `it + n`, etc.
 * - Garante que `&container[0]` aponte para um bloco contíguo de memória.
 * - Compatível com APIs de baixo nível que exigem ponteiros (como OpenGL, C-style libs).
 *
 * Exemplo de tipos que são `contiguous_range`:
 * - `std::vector`
 * - `std::array`
 * - C-style arrays (`int[]`)
 */

void imprimir(auto &contiguo)
{
    for (int valor : contiguo)
    {
        std::cout << valor << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    std::vector<int> numeros = {1, 2, 3, 4, 5};

    // Verificação em tempo de compilação
    static_assert(std::ranges::contiguous_range<decltype(numeros)>, "O intervalo não é contíguo!");

    std::cout << "Elementos no intervalo contíguo: ";
    imprimir(numeros);

    // Demonstração adicional: acesso via ponteiros
    std::cout << "Endereço do primeiro elemento: " << &numeros[0] << '\n';
    std::cout << "Endereço do segundo elemento:  " << &numeros[1] << '\n';

    return 0;
}
