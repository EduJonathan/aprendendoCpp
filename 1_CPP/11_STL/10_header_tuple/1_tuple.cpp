#include <iostream>
#include <typeinfo> // Para usar typeid() e name()
#include <tuple>

/**
 * std::tuple<>: Tuplas são estruturas de dados que permitem armazenar múltiplos valores
 * de diferentes tipos em um único objeto. Em C++, são implementadas através do template
 * std::tuple da biblioteca padrão. Podem conter elementos de tipos diferentes, seu tamanho
 * fixo, mutabilidade estrutural (a menos que sejam const).
 */

int main(int argc, char **argv)
{
    // Criando uma tupla com diferentes tipos de dados
    std::tuple<int, double, std::string> Tuple(42, 3.14, "Hello, World!");

    // Acessando os elementos da tupla
    std::cout << "Element 1: " << std::get<0>(Tuple) << '\n'; // Acessa o primeiro elemento (int)
    std::cout << "Element 2: " << std::get<1>(Tuple) << '\n'; // Acessa o segundo elemento (double)
    std::cout << "Element 3: " << std::get<2>(Tuple) << '\n'; // Acessa o terceiro elemento (string)

    // Tamanho da tupla(Tamanho 3)
    std::cout << "Tuple size: " << std::tuple_size<decltype(Tuple)>::value << '\n';

    // Tipo do primeiro elemento da tupla('i' de inteiro)
    std::cout << "Tuple type: " << typeid(std::get<0>(Tuple)).name() << '\n';

    // Tipo do segundo elemento da tupla('d' de double)
    std::cout << "Tuple type: " << typeid(std::get<1>(Tuple)).name() << '\n';

    // Tipo da tupla(Nome bem extenso para indicar string)
    std::cout << "Tuple type: " << typeid(Tuple).name() << '\n';

    std::cout << "------------------------------------------" << '\n';

    std::tuple<char, bool, float, int> Tupla;
    Tupla = std::make_tuple('A', true, 1.23f, 6); // Inicializa a tupla com valores

    std::cout << "Element 1: " << std::get<0>(Tupla) << '\n'; // Acessa o primeiro elemento (char)
    std::cout << "Element 2: " << std::get<1>(Tupla) << '\n'; // Acessa o segundo elemento (bool)
    std::cout << "Element 3: " << std::get<2>(Tupla) << '\n'; // Acessa o terceiro elemento (float)
    std::cout << "Element 4: " << std::get<3>(Tupla) << '\n'; // Acessa o quarto elemento (int)

    std::cout << "Tuple size: " << std::tuple_size<decltype(Tupla)>::value << '\n'; // Tamanho da tupla
    return 0;
}
