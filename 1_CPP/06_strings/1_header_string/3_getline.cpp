#include <iostream>
#include <limits>
#include <string>

/**
 * @brief Lê uma linha completa de texto de uma stream de entrada.
 *
 * A função `std::getline()` extrai caracteres de uma stream de entrada (`is`)
 * e os armazena em uma string (`str`) até encontrar o caractere delimitador (`delim`),
 * ou até o fim da linha (`'\n'`, por padrão).
 *
 * @param is    Stream de entrada de onde os caracteres serão lidos (ex: `std::cin` ou `std::ifstream`).
 * @param str   String onde o texto lido será armazenado.
 * @param delim (opcional) Caractere de delimitação. O padrão é `'\n'`.
 *
 * @return A função retorna uma referência para o objeto `is` (a própria stream de entrada),
 *         permitindo o encadeamento de operações.
 *
 * @note O caractere delimitador (`delim`) é **consumido**, mas **não é armazenado** em `str`.
 *       Como `std::getline()` consome o caractere de nova linha (`'\n'`), normalmente não
 *       deixa resíduos no buffer de entrada. No entanto, ao misturar `std::getline()` com
 *       `operator>>`, pode ser necessário limpar o buffer usando `std::cin.ignore()`.
 *
 * @example
 * std::string nome;
 * std::cout << "Digite seu nome: ";
 * std::getline(std::cin, nome);
 * std::cout << "Olá, " << nome << "!\n";
 */

int main(int argc, char **argv)
{
    std::string String;

    // Limpa o buffer antes da leitura (preventivo)
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (String.length() == 0)
    {
        std::cout << "Digite uma String: ";
        if (!std::getline(std::cin, String))
        {
            std::cerr << "Erro ao ler a string.\n";
            return 1;
        }
        std::cout << String << '\n';
    }
    else
    {
        std::cout << String << '\n';
    }

    std::cout << "---------------------------------------\n";

    std::string frase;   // Variável para armazenar a frase
    std::string palavra; // Variável para armazenar a palavra

    // Definindo constantes para o tamanho máximo da frase e da palavra
    const int TAMANHO_FRASE = 100;
    const int TAMANHO_PALAVRA = 100;

    // Variável para verificar se a palavra é um palíndromo
    bool isPalindromo = true;

    // Limpa o buffer antes de ler a frase (preventivo)
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Digite uma frase (Máx. de 100 caracteres): ";
    if (!std::getline(std::cin, frase))
    {
        std::cerr << "Erro ao ler a frase.\n";
        return 1;
    }

    if (frase.length() > TAMANHO_FRASE)
    {
        frase = frase.substr(0, TAMANHO_FRASE);
    }

    // Limpa o buffer antes de ler a palavra (preventivo)
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Digite uma palavra (Máx. de 100 caracteres): ";
    if (!std::getline(std::cin, palavra))
    {
        std::cerr << "Erro ao ler a palavra.\n";
        return 1;
    }

    if (palavra.empty())
    {
        std::cout << "Erro: Nenhuma palavra foi inserida.\n";
        return 1;
    }

    if (palavra.length() > TAMANHO_PALAVRA)
    {
        palavra = palavra.substr(0, TAMANHO_PALAVRA);
    }

    // Verifica se a palavra é um palíndromo
    for (size_t i = 0; i < palavra.length() / 2; ++i)
    {
        if (palavra[i] != palavra[palavra.length() - 1 - i])
        {
            isPalindromo = false;
            break;
        }
    }

    // Exibe o resultado
    if (isPalindromo)
    {
        std::cout << "A palavra '" << palavra << "' é um palíndromo!" << '\n';
    }
    else
    {
        std::cout << "A palavra '" << palavra << "' não é um palíndromo." << '\n';
    }
    return 0;
}
