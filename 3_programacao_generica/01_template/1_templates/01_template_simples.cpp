#include <iostream>
#include <vector>
#include <algorithm>

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

/**
 * @brief Função genérica para imprimir os elementos de um container (como std::vector)
 *
 * @tparam T O tipo do container (por exemplo, std::vector<char>)
 * @param container O container cujos elementos serão impressos
 */
template <typename T>
void print(const T &container)
{
    for (const auto &elem : container)
    {
        std::cout << elem << '\n';
    }
    std::cout << "-----\n"; // Separador visual
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

    std::cout << "-----\n"; // Separador visual

    // Inicialização direta dos vetores
    std::vector<char> grupoCaracteres1{'A', 'B', 'C'};
    std::vector<char> grupoCaracteres2{'D', 'E', 'F', 'G'};

    std::cout << "Grupo 1 inicial:\n";
    print(grupoCaracteres1);

    // Ordena o grupo 1
    std::sort(grupoCaracteres1.begin(), grupoCaracteres1.end());
    std::cout << "Grupo 1 ordenado:\n";
    print(grupoCaracteres1);

    std::cout << "Grupo 2:\n";
    print(grupoCaracteres2);

    // Concatenar grupo 2 no início do grupo 1
    grupoCaracteres1.insert(grupoCaracteres1.begin(), grupoCaracteres2.begin(), grupoCaracteres2.end());
    std::cout << "Após inserção do Grupo 2 no início:\n";
    print(grupoCaracteres1);

    // Ordena novamente
    std::sort(grupoCaracteres1.begin(), grupoCaracteres1.end());
    std::cout << "Grupo 1 final ordenado:\n";
    print(grupoCaracteres1);

    return 0;
}
