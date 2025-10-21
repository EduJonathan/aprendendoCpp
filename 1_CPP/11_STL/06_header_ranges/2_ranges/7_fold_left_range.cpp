#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>

/**
 * std::ranges::fold_left(C++23): Aplica uma operação de redução (fold) da esquerda para a 
 * direita  em uma faixa de elementos. A função acumuladora processa os elementos de forma 
 * sequencial.
 *
 * - Útil para operações como soma, concatenação de strings, etc.
 * - A operação é realizada com um acumulador que acumula o resultado da aplicação da função
 * em cada elemento.
 */

int main(int argc, char **argv)
{
    std::vector<std::string> words{"hello", "world", "from", "C++", "ranges"};

    // Usando fold_left (disponível no C++23 ou mais recente)
    auto concatenar = std::ranges::fold_left(words, std::string(""),
    [](std::string acc, const std::string &word)
    {
        return acc + (acc.empty() ? "" : " ") + word;
    });

    std::cout << concatenar << '\n'; // Output: hello world from C++ ranges
    return 0;
}
