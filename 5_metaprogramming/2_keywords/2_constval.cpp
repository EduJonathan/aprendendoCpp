#include <iostream>

// O consteval garante que uma função seja avaliada apenas em tempo de compilação.

consteval int square(int x)
{
    return x * x;
}

int main(int argc, char **argv)
{
    constexpr int result = square(5); // Calculado em tempo de compilação
    std::cout << result << '\n';      // Imprime: 25
    // int x = 5;
    // square(x); // Erro: consteval só pode ser usado em contexto de compilação

    /**
     * Compile e execute o programa com: g++ -std=c++20 -o consteval consteval.cpp
     */
    return 0;
}
