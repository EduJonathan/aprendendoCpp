#include <iostream>

// Caso base: nenhuma argumento
constexpr int sum() { return 0; }

// Caso geral: Soma o primeiro argumento com o restante
template <typename T, typename... Args>
constexpr int sum(T first, Args... args)
{
    return first + sum(args...);
}

// Soma os caracteres de uma string
constexpr int somar_caracteres() { return 0; }

// Caso geral: Soma o valor numérico do primeiro caractere com o restante
template <typename... Args>
constexpr int somar_caracteres(char first, Args... args)
{
    return (first - '0') + somar_caracteres(args...);
}

int main(int argc, char **argv)
{
    // Somando uma série de argumentos de valores
    constexpr int resultado = sum(1, 2, 3, 4); // Calculado em tempo de compilação
    std::cout << "Soma: " << resultado << '\n';

    constexpr int resultado_caracteres = somar_caracteres('5', '4');
    std::cout << "Soma dos caracteres: " << resultado_caracteres << '\n';

    return 0;
}
