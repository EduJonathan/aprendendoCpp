#include <iostream>
#include <type_traits>

template <typename T, std::enable_if_t<std::is_integral_v<T>, void> * = nullptr>
void process(T value)
{
    std::cout << "Processando tipo inteiro: " << value << '\n';
}

template <typename T, std::enable_if_t<!std::is_integral_v<T>, void> * = nullptr>
void process(T value)
{
    std::cout << "Processando tipo não-inteiro: " << value << '\n';
}

int main(int argc, char **argv)
{
    process(42);     // Imprime: Processando tipo inteiro: 42
    process(3.14);   // Imprime: Processando tipo não-inteiro: 3.14
    process("0.50"); // Imprime: Processando tipo não-inteiro: 0.50
    return 0;
}
