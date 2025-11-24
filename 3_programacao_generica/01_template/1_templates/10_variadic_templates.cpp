#include <iostream>
#include <string>

/**
 * Variadic templates, introduzidos no C++11, permitem que funções ou classes
 * aceitem um número variável de argumentos de tipos diferentes. Eles são
 * definidos usando o operador `...` (parameter pack) e são expandidos recursivamente
 * ou com técnicas modernas (como fold expressions no C++17).
 */

// Caso base: função vazia para terminar a recursão
void print() {}

// Função sobrecarregada com `variadic template` que aceita um número variável de argumentos
template <typename T, typename... Args>
void print(const T &first, const Args &...args)
{
    std::cout << first << ' ';
    print(args...); // Expande os argumentos recursivamente
}

// Exemplo com fold expression (C++17)
template <typename... Args>
void print_fold(Args &&...args)
{
    (std::cout << ... << args) << '\n'; // Fold expression para impressão
}

int main(int argc, char **argv)
{
    print(1, 2.5, "Hello", std::string("World\n"));    // Imprime: 1 2.5 Hello World
    print_fold(1, 2.5, "Hello", std::string("World")); // Imprime: 123HelloWorld
    return 0;
}
