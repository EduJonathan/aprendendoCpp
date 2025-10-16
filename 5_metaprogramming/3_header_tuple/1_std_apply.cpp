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

/**
 * @brief Classe genérica que encapsula uma tupla de tipos arbitrários.
 *
 * Esta classe aceita um número variável de argumentos (variadic template)
 * e armazena os valores em um `std::tuple`. Fornece um método `print()`
 * que imprime os valores armazenados na tupla para o console.
 *
 * @tparam Args Lista de tipos dos elementos armazenados na tupla.
 */
template <typename... Args>
class MyTuple
{
public:
    /// Tupla contendo os dados passados ao construtor.
    std::tuple<Args...> data;

    /**
     * @brief Construtor que inicializa a tupla com os argumentos fornecidos.
     *
     * @param args Valores de entrada para inicializar a tupla.
     */
    MyTuple(Args... args) : data(args...) {}

    /**
     * @brief Imprime os elementos da tupla separados por espaço.
     *
     * Usa `std::apply` com fold expression para expandir e imprimir todos
     * os elementos da tupla. Requer que os elementos suportem `operator<<`.
     */
    void print()
    {
        std::apply([](auto &&...args)
        {
            ((std::cout << args << ' '), ...);
        }, data);
        std::cout << '\n';
    }
};

int main(int argc, char **argv)
{
    auto myTuple = std::make_tuple(1, 3.14, "Hello");
    printTuple(myTuple); // Imprime: 1 3.14 Hello

    MyTuple<int, double, std::string> Tupla(1, 2.5, "hello");
    Tupla.print(); // Output: 1 2.5 hello

    MyTuple<> tupla_vazia; // Suporta zero argumentos
    tupla_vazia.print();   // Saída: (linha em branco)

    MyTuple<char, bool, const char *> tupla('A', true, "Teste");
    tupla.print(); // Saída: A 1 Teste

    return 0;
}
