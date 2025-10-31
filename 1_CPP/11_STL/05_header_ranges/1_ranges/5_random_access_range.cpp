#include <iostream>
#include <vector>
#include <type_traits>
#include <ranges>

/**
 * std::ranges::random_access_range(): Um *random_access_range* permite acesso rápido e direto
 * a qualquer elemento, seja por índice (`[]`) ou por operações aritméticas com iteradores (`it + n`).
 *
 * - Estende as capacidades de `bidirectional_range`.
 * - Permite iteração em qualquer direção e acesso aleatório.
 * - Ideal para estruturas com acesso por índice eficiente.
 *
 * Exemplo: `std::vector`, `std::deque`, `std::array` são `random_access_range`.
 */

int main(int argc, char **argv)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Verificação em tempo de compilação
    static_assert(std::ranges::random_access_range<decltype(vec)>, "Não é um random_access_range!");

    std::cout << "Vetor de elementos: ";

    // Acesso sequencial por índice
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';

    // Acesso aleatório usando índice
    std::cout << "Acesso aleatório aos elementos:\n";
    std::cout << "Elemento no indíce 2: " << vec[2] << '\n'; // Acesso aleatório (índice 2 -> 3)
    std::cout << "Elemento no indíce 4: " << vec[4] << '\n'; // Acesso aleatório (índice 4 -> 5)

    return 0;
}
