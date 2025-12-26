#include <iostream>
#include <string>
#include <cassert>
#include <compare>

/**
 * O operador <=>(spaceship operator) implementada apartir do C++20, é uma forma
 * mais poderosa e concisa de implementar comparações entre objetos em C++, conhecido
 * como o operador de comparação de três vias.
 *
 * - Com isso, você pode reduzir a quantidade de código necessário para implementar comparações,
 * e o compilador gera automaticamente outros operadores de comparação baseados no seu uso do <=>.
 * - Ele retorna um valor que pode indicar se dois objetos são menores, maiores ou iguais.
 *
 * RETORNOS:
 * Tipo de retorno: std::strong_ordering vs std::partial_ordering (header compare)
 *
 * std::strong_ordering: Quando você tem comparações definidas para todos os casos,
 * como no caso de strings ou inteiros, o operador <=> retorna um valor do tipo
 * std::strong_ordering, que podem ser:
 *
 * - std::strong_ordering::less
 * - std::strong_ordering::equal
 * - std::strong_ordering::greater
 *
 * std::partial_ordering: Para tipos que podem ter valores indeterminados (como NaN para double),
 * o operador <=> pode retornar std::partial_ordering:
 * - std::partial_ordering::less
 * - std::partial_ordering::equal
 * - std::partial_ordering::greater
 * - std::partial_ordering::unordered (indefinido)
 */

class Person
{
public:
    std::string name;
    double value;

    Person(std::string n, double v) : name(n), value(v) {}

    // Sobrecarga do operador <=> (spaceship operator)
    std::partial_ordering operator<=>(const Person &rhs) const
    {
        auto cmp1 = name <=> rhs.name; // Compara os nomes
        if (cmp1 != 0)                 // Se os nomes são diferentes, já retorna a comparação
            return cmp1;

        return value <=> rhs.value; // Se os nomes são iguais, compara os valores
    }
};

int main(int argc, char **argv)
{
    Person alice("Alice", 10.5);
    Person bob("Bob", 12.0);

    if (alice < bob)
        std::cout << "Alice é menor que Bob\n";
    else if (alice > bob)
        std::cout << "Alice é maior que Bob\n";
    else
        std::cout << "Alice é igual a Bob\n";

    /**
     * Compile e execute com:
     * g++ -std=c++20 seu_arquivo.cpp -o exe
     * ./exe
     *
     * @note
     * Informações e codificação retirada do livro:
     * C++20 The Complete Guide First, de Nicolai M. Josuttis
     */

    return 0;
}
