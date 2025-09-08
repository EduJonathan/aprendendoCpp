#include <iostream>
#include <string>
#include <tuple>

/**
 * Exemplo de uso de std::tuple e desestruturação
 *
 * Desestruturar uma tupla é o processo de extrair seus elementos individuais em variáveis separadas.
 * Isso pode ser feito de forma concisa usando a sintaxe de desestruturação.
 *
 * Introduzida no C++17, a desestruturação pode ser usada em conjunto com outras
 * funcionalidades da linguagem, como a inicialização de variáveis, além de deixar o código
 * mais legível, reduzindo a necessidade de acessos repetidos aos elementos da tupla.
 */

/**
 * Função que simula a hora do banho, retornando os itens necessários.
 *
 * @return Uma tupla contendo os itens: shampoo, sabonete e toalha.
 */
std::tuple<std::string, std::string, std::string> horaDoBanho()
{
    return std::make_tuple("shampoo", "sabonete", "toalha");
}

int main(int argc, char **argv)
{
    std::tuple<int, double, std::string> minhaTupla(42, 3.14, "Olá");
    auto [a, b, c] = minhaTupla;

    std::cout << "Inteiro: " << a << '\n';
    std::cout << "Double: " << b << '\n';
    std::cout << "String: " << c << '\n';

    auto [x, y, z] = horaDoBanho();
    if (x == "shampoo" && y == "sabonete" && z == "toalha")
    {
        std::cout << "Hora do banho:\n";
        std::cout << " - " << x << '\n';
        std::cout << " - " << y << '\n';
        std::cout << " - " << z << '\n';
    }

    return 0;
}
