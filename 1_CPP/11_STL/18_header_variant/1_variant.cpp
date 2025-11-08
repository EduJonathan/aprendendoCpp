#include <iostream>
#include <string>
#include <variant>

/**
 * std::variant (C++17)
 * ---------------------
 * Classe template que representa uma **união discriminada com segurança de tipo**.
 * Permite armazenar um valor de diferentes tipos, mas apenas um tipo por vez.
 *
 * Quando usar:
 * - Quando um valor pode assumir tipos mutuamente exclusivos.
 * - Substituir uniões C (union) com verificação de tipo.
 * - Implementar máquinas de estado ou padrões como Visitor.
 *
 * Acessando valores:
 * - std::get<T>(v): retorna o valor do tipo T (lança exceção se o tipo não corresponder).
 * - std::get_if<T>(&v): retorna ponteiro para o valor ou nullptr (sem exceção).
 * - std::visit(functor, v): aplica uma função/lambda ao valor armazenado,
 *   executando o código correspondente ao tipo ativo.
 *
 * Vantagens:
 * - Segurança de tipo em tempo de compilação.
 * - Evita casts inseguros e exceções desnecessárias.
 * - Código mais limpo e expressivo.
 */

int main(int argc, char **argv)
{
    int varType = 1;
    std::variant<int, float, std::string> myVariant;

    // Usando std::get_if para evitar exceções.
    switch (varType)
    {
    case 0:
        myVariant = 42; // Armazena um int
        if (auto val = std::get_if<int>(&myVariant))
        {
            std::cout << *val << '\n'; // Imprime o valor do int
        }
        else
        {
            std::cout << "Tipo incorreto ou não encontrado!\n";
        }
        break;

    case 1:
        myVariant = 3.14f; // Armazena um float
        if (auto val = std::get_if<float>(&myVariant))
        {
            std::cout << *val << '\n'; // Imprime o valor do float
        }
        else
        {
            std::cout << "Tipo incorreto ou não encontrado!\n";
        }
        break;

    case 2:
        myVariant = std::string("Hello, Variant!"); // Armazena uma string
        if (auto val = std::get_if<std::string>(&myVariant))
        {
            std::cout << *val << '\n'; // Imprime a string
        }
        else
        {
            std::cout << "Tipo incorreto ou não encontrado!\n";
        }
        break;

    default:
        myVariant = 0; // Valor padrão
        std::cout << "Tipo não especificado. Usando valor padrão.\n";
        break;
    }

    // Usando std::visit para operar com base no tipo armazenado.
    std::cout << "\nUsando std::visit para operação baseada no tipo armazenado:\n";
    std::visit([](auto &&arg)
    {
        std::cout << "Valor armazenado: " << arg << '\n';
    }, myVariant);

    return 0;
}
