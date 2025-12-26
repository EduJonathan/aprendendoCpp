#include <iostream>
#include <forward_list>
#include <ranges>

/**
 * std::ranges::forward_range(): Um *forward_range* permite ler seus elementos **múltiplas vezes
 * na ordem correta**. Ele avança apenas para frente (como uma lista encadeada), mas garante que
 * cada elemento pode ser acessado novamente (diferente de input_range).
 *
 * Características:
 * - Suporta múltiplas iterações (reiterável).
 * - Suporta pré-incremento (++it), mas não decremento (--it).
 * - Não garante acesso por índice.
 *
 * Exemplo: `std::forward_list` é um `forward_range`.
 */

void imprimir(auto &intervalo)
{
    for (int &valor : intervalo) // Passa por referência para modificar
    {
        valor *= 2; // Dobra o valor
        std::cout << valor << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    std::forward_list<int> numeros = {1, 2, 3, 4, 5};

    // Verificação estática: confirma que a lista é um forward_range
    static_assert(std::ranges::forward_range<decltype(numeros)>, "O intervalo não é um forward_range!");

    std::cout << "Elementos no forward_range (após dobrar): ";
    imprimir(numeros);

    return 0;
}
