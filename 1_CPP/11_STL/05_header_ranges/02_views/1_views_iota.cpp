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

    return 0;
}
