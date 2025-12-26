#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

/**
 * std::ranges::sort: É uma função de ordenação introduzida no C++20, parte da biblioteca
 * `<algorithm>`, mas pensada para funcionar com o novo sistema de *ranges* (intervalos).
 *
 * - Funciona com qualquer container que satisfaça o conceito de `random_access_range` e `sortable`.
 * - Ordena os elementos **in-place** (modificando o container original).
 * - A sintaxe é mais limpa e direta: não precisa passar iteradores como em `std::sort`.
 *
 * Vantagens sobre `std::sort`:
 * - Mais legível.
 * - Compatível com conceitos modernos (`ranges`, `views`).
 * - Menor risco de erro por não precisar usar `begin()`/`end()`.
 */

int main(int argc, char **argv)
{
    std::vector<int> myVec{-3, 5, 0, 7, -4};
    std::ranges::sort(myVec);

    // Ordena o vetor de forma crescente
    for (auto v : myVec)
    {
        std::cout << v << ' '; // -4, -3, 0, 5, 7
    }

    /**
     * Se caso seu editor de código ou terminal estiver apresentando a seguinte mensagem:
     * "error: name followed by '::' must be a class or namespace name"
     * Isso pode ser resolvido adicionando a flag de compilação:
     *
     * > g++ -std=c++20 main.cpp -o main
     * > .\main.exe
     *
     * O -std=c++20/std:c++20 => Flags de compilação do g++ que ativa o suporte e recursos,
     * dizendo ao compilador qual versão do C++ usar, neste caso, C++20 ou superior
     * versão que se encontra os recursos de (ranges, views, concepts).
     *
     * Lembrete de realizar esta compilação para todos os códigos que utilizam recursos do C++20 ou superior.
     */
    return 0;
}
