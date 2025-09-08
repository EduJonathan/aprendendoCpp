#include <iostream>
#include <concepts>

/**
 * Concepts são uma adição do C++20 que simplificam a metaprogramação ao permitir
 * restrições explicitas em templates. Torna-se o código mais legível e os erros
 * mais claros
 */

// Template para tipos númericos
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// Função restrita para tipos númericos
template <Numeric T>
T square(T value)
{
    return value * value;
}

int main(int argc, char **argv)
{
    std::cout << square(5) << '\n';
    std::cout << square(5.5f) << '\n';
    std::cout << square(3.14) << '\n';
    // std::cout << square("3.14") << '\n'; // Erro de compilação

    /**
     * Compile e execute o programa com
     * g++ -std=c++20 -o concept concept.cpp
     */

    return 0;
}
