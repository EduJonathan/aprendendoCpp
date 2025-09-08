#include <iostream>
#include <concepts>

/**
 * requires está relacionada aos concepts, A expressão requires é usada para definir concepts
 * ou testar se certas operações são válidas para um tipo. Ela contém uma lista de requisitos
 * que o tipo deve satisfazer, como suporte a certas operações ou membros.
 *
 * Quando usar?
 * O requires é útil quando você precisa:
 *
 * Restringir templates a tipos específicos (ex.: apenas tipos que suportam certas operações).
 * Escrever código genérico mais robusto e seguro.
 * Simplificar metaprogramação em comparação com técnicas antigas como SFINAE.
 */

template <typename T>
concept Incrementable = requires(T a) {
    { ++a } -> std::same_as<T &>;
    { a++ } -> std::same_as<T>;
};

template <Incrementable T>
void increment(T &value)
{
    ++value;
}

template <typename T>
concept Addable = requires(T a, T b)
{
    a + b; // Verifica se a operação + está definida para T
};

template <Addable T>
T add(T a, T b)
{
    return a + b;
}

int main(int argc, char **argv)
{
    int x = 5;
    increment(x);
    std::cout << "Incremented value: " << x << '\n';

    int y = 10;
    std::cout << "Sum: " << add(x, y) << '\n';

    /**
     * Compile e execute o programa com
     * g++ -std=c++20 -o requires requires.cpp
     */
    return 0;
}
