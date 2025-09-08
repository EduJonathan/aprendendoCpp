#include <iostream>

/**
 * Templates em C++ são uma característica poderosa que permite escrever códigos genéricos
 * e reutilizáveis. Com templates, você pode criar funções, classes e até estruturas de dados
 * que podem operar com qualquer tipo de dado (ou tipo definido pelo usuário), sem ter que
 * escrever uma versão específica para cada tipo de dado.
 */

// Definindo uma classe Pair genérica
template <typename T> // O <typename T> diz que 'T' será o tipo genérico para a classe
class Pair
{
private:
    T x; // Variável x do tipo genérico T
    T y; // Variável y do tipo genérico T

public:
    // Construtor que aceita dois valores do tipo T
    Pair(T _x, T _y) : x(_x), y(_y) {}

    // Método para retornar o primeiro valor
    T get_first_number(void)
    {
        return x;
    }

    // Método para retornar o segundo valor
    T get_second_number(void)
    {
        return y;
    }
};

// Função Max genérica
template <typename T> // Novamente, T é o tipo genérico para a função
T Max(T first_value, T second_value)
{
    // Retorna o maior valor entre os valores genéricos
    return (first_value > second_value) ? first_value : second_value;
}

int main(int argc, char **argv)
{
    // Criando um objeto Pair com tipo int
    Pair<int> par(5, '3'); // '3' será convertido para int, que na tabela ASCII é 51
    std::cout << par.get_first_number() << ' ' << par.get_second_number() << '\n';

    // Usando a função Max com diferentes tipos
    int maxInt = Max(10, 20); // Chamando Max com tipo int
    std::cout << "Max entre inteiros: " << maxInt << '\n';

    float maxFloat = Max(3.5f, 2.1f); // Chamando Max com tipo float
    std::cout << "Max entre floats: " << maxFloat << '\n';

    char maxChar = Max('a', 'z'); // Chamando Max com tipo char
    std::cout << "Max entre caracteres: " << maxChar << '\n';

    return 0;
}
