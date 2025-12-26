#include <iostream>
#include <string>

// A expressão `if constexpr` é uma construção do C++17 que permite que escrevermos
// códigos que se adaptam a diferentes tipos ou condições, sem sobrecarga de verificação
// em tempo de compilação.

template <typename T>
auto printValor(T value)
{
    if constexpr (std::is_integral<T>::value)
    {
        std::cout << "Valor integral: " << value << '\n';
    }
    else if constexpr (std::is_floating_point<T>::value)
    {
        std::cout << "Valor de ponto flutuante: " << value << '\n';
    }
    else
    {
        std::cout << "Outro Tipo" << '\n';
    }
}

int main(int argc, char **argv)
{
    printValor(42);                   // Integral type
    printValor(3.14);                 // Floating point type
    printValor(3.14f);                // Floating point type
    printValor("Hello");              // Other type (string literal)
    printValor(std::string("World")); // Other type (std::string)
    return 0;
}
