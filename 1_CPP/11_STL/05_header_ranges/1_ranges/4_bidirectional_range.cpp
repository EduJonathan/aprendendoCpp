#include <iostream>
#include <list>
#include <type_traits>
#include <ranges>

/**
 * std::ranges::bidirectional_range(): Um *bidirectional_range* permite iterar seus elementos
 * tanto para frente quanto para trás. Ele é uma extensão de `forward_range`, oferecendo também
 * operadores de decremento (como `--it`).
 *
 * Características:
 * - Permite iteração para frente e para trás.
 * - Pode ser usado com listas encadeadas e outras estruturas que suportam ambos os tipos de iteração.
 *
 * Exemplo: `std::list` é um exemplo de `bidirectional_range`.
 */

int main(int argc, char **argv)
{
    std::list<int> lista = {1, 2, 3, 4, 5};

    // Verificação de bidirectional_range
    static_assert(std::ranges::bidirectional_range<decltype(lista)>, "O intervalo não é bidirectional_range!");

    // Iterando para frente
    std::cout << "Iterando para frente: ";
    for (auto it = lista.begin(); it != lista.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // Iterando para trás
    std::cout << "Iterando para trás: ";
    for (auto it = lista.rbegin(); it != lista.rend(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    return 0;
}
