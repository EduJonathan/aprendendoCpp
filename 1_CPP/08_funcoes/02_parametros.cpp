#include <iostream>
#include <string>

/**
 * PARAMETROS: Ou argumentos, são informações passadas para uma função de um tipo de dado
 * para obter, operar e alterar o conteúdo do tipo informado sejam (tipos de dados primitivos,
 * structs, enums, class).
 */

/**
 * @brief Função que retorna o tamanho da string, se o tamanho for 0, pede para o usuário
 * inserir uma nova string.
 *
 * Protótipo da função
 *
 * @param tamanho Tamanho da string
 * @param string String a ser verificada
 * @returns Tamanho da string
 */
std::size_t sizeString(std::size_t tamanho, const char *string);

int main(int argc, char **argv)
{
    std::string string{};                  // Inicializa a string vazia
    std::size_t tamanho = string.length(); // Obtém o tamanho da string

    // Passa o tamanho e a string para a função, c_str() Retorna um ponteiro para a string
    std::cout << "Tamanho da string: " << sizeString(tamanho, string.c_str()) << '\n';

    std::cout << "---------------------------------------------" << '\n';

    std::string str{"Eduardo Jonathan"}; // Inicializa a string
    std::size_t size = str.length();     // Obtém o size da string

    // Passa o tamanho e a string para a função, c_str() Retorna um ponteiro para a string
    std::cout << "Tamanho da string: \"" << str << "\" é: " << sizeString(size, str.c_str()) << '\n';
    return 0;
}

std::size_t sizeString(std::size_t tamanho, const char *string)
{
    // Se o tamanho fornecido for 0, pede para o usuário inserir uma string
    if (tamanho == 0)
    {
        std::cout << "A string fornecida está vazia." << '\n';
        std::cout << "Insira uma nova string: ";
        std::string novaString;

        // Leitura para a nova string
        std::getline(std::cin, novaString);

        // Retorna o tamanho da nova string inserida
        return novaString.size();
    }

    // Caso o tamanho já tenha sido fornecido (diferente de 0), retorna o tamanho
    return tamanho;
}
