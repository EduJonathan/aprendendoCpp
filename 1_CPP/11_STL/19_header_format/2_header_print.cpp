#include <print>
#include <cmath>

/**
 * header: <print>
 *
 * A header print foi implementada no C++23 e fornece funcionalidades para
 * formatação e impressão de texto de maneira mais simples e eficiente.
 */

/**
 * @brief A função std::println é uma extensão do std::print que adiciona automaticamente um caractere de nova linha ('\n')
 * ao final da string formatada. Exemplo: std::println("Hello, {}!", "World") produzirá "Hello, World!\n".
 *
 * @param valor O valor a ser processado e impresso
 */
void operacao(int valor)
{
    std::println("{}", valor / std::sqrt(valor));
}

int main(int argc, char **argv)
{
    double valores[] =
    {
        #include "numbers.csv" // Irá incluir números de um arquivo CSV para preencher o array
    };

    for (const auto &target : valores)
    {
        std::println("Valores: {}", target);
    }

    operacao(66);

    /**
     * Para compilar este código, certifique-se de usar um compilador que suporte o C++23.
     * Exemplo de comando de compilação com g++:
     * g++ -std=c++23 -o print 2_header_print.cpp
     *
     * ou
     *
     * g++-14 -std=c++23 -o print 2_header_print.cpp
     *
     * Depois de compilar, execute o programa:
     * ./print
     */
    return 0;
}
