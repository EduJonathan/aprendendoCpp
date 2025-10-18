#include <iostream>
#include <ranges>

/**
 * std::views::iota(): É um *range factory* que cria uma sequência de elementos gerados por
 * incrementos sucessivos a partir de um valor inicial. A sequência pode ser finita (com valor
 * final especificado) ou infinita (quando apenas o valor inicial é fornecido).
 */

int main(int argc, char **argv)
{
    // Cria uma sequência de números inteiros a partir de 0 até 9
    auto seq = std::views::iota(0, 10); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    std::cout << "Sequência 0 a 9: ";

    for (int i : seq)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // Cria uma sequência de números inteiros a partir de 0 até 9, com incremento de 2
    auto seq2 = std::views::iota(0, 10, 2); // [0, 2, 4, 6, 8]
    std::cout << "Sequência 0 a 9 com incremento de 2: ";

    for (int i : seq2)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    /**
     * Se caso seu editor de código ou terminal estiver apresentando a seguinte mensagem:
     * "error: name followed by '::' must be a class or namespace name"
     * Isso pode ser resolvido adicionando a flag de compilação:
     *
     * > g++ -std=c++20 main.cpp -o main
     * > .\main.exe
     *
     * Ou, se você estiver usando o Visual Studio, adicione a seguinte linha de código de compilação:
     *
     * > cl /std:c++20 main.cpp
     * > .\main.exe
     *
     * O -std=c++20/std:c++20 => Flags de compilação do g++ que ativa o suporte e recursos,
     * dizendo ao compilador qual versão do C++ usar, neste caso, C++20 ou superior
     * versão que se encontra os recursos de (ranges, views, concepts).
     */
    return 0;
}
