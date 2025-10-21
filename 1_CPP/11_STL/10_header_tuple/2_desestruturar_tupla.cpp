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

    std::cout << "===========================================================" << '\n';

    std::cout << "Sem Desestrutura com auto[]: " << '\n';

    // Acessando elementos diretamente com std::get<indice>()
    std::cout << "Inteiro: " << std::get<0>(minhaTupla) << '\n';
    std::cout << "Double: " << std::get<1>(minhaTupla) << '\n';
    std::cout << "String: " << std::get<2>(minhaTupla) << '\n';

    std::cout << "===========================================================" << '\n';

    std::cout << "Desestruturado com auto[]: " << '\n';

    auto [a, b, c] = minhaTupla;

    std::cout << "Inteiro: " << a << '\n';
    std::cout << "Double: " << b << '\n';
    std::cout << "String: " << c << '\n';

    std::cout << "===========================================================" << '\n';

    std::cout << "Sem Desestrutura com auto[]: " << '\n';

    std::tuple<std::string, std::string, std::string> banho = horaDoBanho();

    if (std::get<0>(banho) == "shampoo" &&
        std::get<1>(banho) == "sabonete" &&
        std::get<2>(banho) == "toalha")
    {
        std::cout << "Hora do banho:\n";
        std::cout << " - " << std::get<0>(banho) << '\n';
        std::cout << " - " << std::get<1>(banho) << '\n';
        std::cout << " - " << std::get<2>(banho) << '\n';
    }

    std::cout << "===========================================================" << '\n';

    std::cout << "Desestruturado com auto[]: " << '\n';

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
