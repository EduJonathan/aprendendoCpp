#include <iostream>
#include <stdexcept>
#include <memory>

/**
 * A sobrecarga do operador `operator[]` permite que um objeto seja indexado como
 * se fosse um array. Isso é útil quando você deseja acessar elementos dentro de
 * um container ou estrutura de dados de maneira semelhante à de um array tradicional,
 * mas com controle adicional sobre o comportamento.
 *
 * No exemplo abaixo, a classe `Array` contém um array de inteiros `dados` e implementa
 * a sobrecarga do operador `operator[]` para permitir o acesso e modificação dos elementos do array.
 *
 * Exemplo:
 *
 * Array arr;
 * arr[0] = 10;  // Atribui 10 ao primeiro elemento
 * std::cout << arr[0];  // Acessa o primeiro elemento, imprime 10
 *
 * Isso torna o código mais legível e permite que você customize a forma de acesso aos dados.
 *
 * Quando usar:
 * - Quando você deseja permitir a indexação personalizada de elementos em uma classe ou estrutura de dados.
 * - Quando você precisa controlar o acesso ou modificação de elementos, como limites ou validação.
 * - Para criar containers que se comportam de maneira similar a arrays.
 */

class Array
{
private:
    int dados[10]; // Um array de 10 inteiros

public:
    // Sobrecarga do operador [] para acessar ou modificar elementos
    int &operator[](int indice)
    {
        if (indice < 0 || indice >= 10)
        {
            throw std::out_of_range("Índice fora do limite!");
        }
        return dados[indice];
    }
};

int main(int argc, char **argv)
{
    std::unique_ptr<Array> arrPtr = std::make_unique<Array>();

    try
    {
        (*arrPtr)[0] = 10; // Atribui 10 ao primeiro elemento
        (*arrPtr)[1] = 20; // Atribui 20 ao segundo elemento

        std::cout << "Array[0]: " << (*arrPtr)[0] << '\n'; // Imprime 10
        std::cout << "Array[1]: " << (*arrPtr)[1] << '\n'; // Imprime 20

        // Tentando acessar um índice inválido
        std::cout << "Array[10]: " << (*arrPtr)[10] << '\n'; // Lança exceção
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Erro: " << e.what() << '\n';
    }

    return 0;
}
