#include <algorithm>
#include <cstdio>
#include <numeric>
#include <ranges>
#include <span>

/**
 * std::span::subspan
 * ------------------
 * subspan() cria uma nova visão (view) sobre uma parte específica de um std::span,
 * sem copiar dados ou alocar memória. Ele simplesmente delimita um intervalo dentro
 * do span original, permitindo trabalhar com subsequências de forma leve e eficiente.
 *
 * Quando usar:
 * - Ao manipular apenas uma fatia de um array, buffer ou sequência contínua.
 * - Quando quiser evitar cópias e trabalhar diretamente com a memória existente.
 * - Em funções que operam somente em trechos específicos de dados.
 *
 * Formas de uso:
 * - span.subspan(offset, length): cria um span que começa em 'offset' e tem 'length' elementos.
 * - span.subspan(offset): cria um span que começa em 'offset' e vai até o fim.
 *
 * Por que é útil:
 * - Não copia dados — funciona só como uma janela sobre o array original.
 * - Torna o código mais claro, expressando explicitamente a intenção de usar um intervalo.
 * - Mantém a segurança dos limites (bounds), reduzindo o risco de manipulação incorreta.
 * - Evita ponteiros crus, reforçando boas práticas de C++ moderno.
 *
 * Referência:
 * https://en.cppreference.com/w/cpp/container/span/subspan
 */

void display(std::span<const char> abc)
{
    const auto columns{20U};
    const auto rows{abc.size() - columns + 1};

    for (auto offset{0U}; offset < rows; ++offset)
    {
        std::ranges::for_each(abc.subspan(offset, columns), std::putchar);
        std::puts("");
    }
}

int main(int argc, char **argv)
{
    char abc[26];

    // CORREÇÃO: std::iota, não std::ranges::iota
    std::iota(std::begin(abc), std::end(abc), 'A');

    display(abc);

    /**
     * Compile com:
     * g++ -std=c++20 subspan.cpp -o subspan
     * ./subspan
     */
    return 0;
}
