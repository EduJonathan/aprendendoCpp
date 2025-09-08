#include <iostream>
#include <tuple>

/**
 * @brief Função para imprimir os elementos de uma tupla
 *
 * @tparam Args Tipos dos elementos da tupla
 * @param tuple tupla a ser impressa
 * 
 * @note std::apply é uma função de metaprogramação que aplica uma função a uma tupla de argumentos.
 * função essa que pode ser usada para manipular e operar sobre tipos variados em tempo de compilação.
 */
template <typename... Args>
void printTuple(const std::tuple<Args...> &tuple)
{
    // Neste exemplo, std::apply para desempacotar os elementos da tupla e imprimi-los,
    // mostrando como a metaprogramação pode manipular tipos variados em tempo de compilação.
    std::apply([](const auto &...args)
    {
        ((std::cout << args << ' '), ...);
    }, tuple);
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    auto myTuple = std::make_tuple(1, 3.14, "Hello");
    printTuple(myTuple); // Imprime: 1 3.14 Hello
    return 0;
}
