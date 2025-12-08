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

/** Explicação 1: A função increment só aceitará tipos que atendem ao concept Incrementable.*/
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

/** Explicação 2: Verifica se o operador + está definido para o tipo T. */
template <typename T>
concept Addable = requires(T a, T b) {
    a + b; // Verifica se a operação + está definida para T
};

template <Addable T>
T add(T a, T b)
{
    return a + b;
}

/** Explicação 3: Uso de requires com if constexpr. */
struct First
{
    // (4)
    int count() const
    {
        return 2020;
    }
};

struct Second
{
    int size() const
    {
        return 2021;
    }
};

template <typename T>
int getNumberOfElements(T t)
{

    if constexpr (requires(T t) { { t.count() } -> std::convertible_to<int>; })
    {
        // (1)
        return t.count();
    }
    
    if constexpr (requires(T t) { { t.size() } -> std::convertible_to<int>; })
    {
        // (2)
        return t.size();
    }
    else
        return 42; // (3)
}

/** Explicação 4: requires com valores constantes. */
template <unsigned int i>
    requires(i <= 20) // (1)
int sum(int j)
{
    return i + j;
}

int main(int argc, char **argv)
{
    int x = 5;
    increment(x);
    std::cout << "Incremented value: " << x << '\n';

    int y = 10;
    std::cout << "Sum: " << add(x, y) << '\n';

    std::cout << '\n';

    First first;
    std::cout << "getNumberOfElements(first): " << getNumberOfElements(first) << '\n';

    Second second;
    std::cout << "getNumberOfElements(second): " << getNumberOfElements(second) << '\n';

    int third = 0;
    std::cout << "getNumberOfElements(third): " << getNumberOfElements(third) << '\n';

    std::cout << "\n\n";

    std::cout << "sum<20>(2000): " << sum<20>(2000) << '\n';
    // std::cout << "sum<23>(2000): " << sum<23>(2000) << '\n',  // ERROR

    std::cout << '\n';

    /**
     * Compile e execute o programa com
     * g++ -std=c++20 -o requires 5_requires.cpp
     */
    return 0;
}
