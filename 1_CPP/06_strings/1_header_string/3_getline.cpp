#include <iostream>
#include <string>

/**
 * std::getline(): Extrai os caracteres de uma stream(is) de entrada e os armazena
 * em uma string(str), até que o caractere de delimitação delim seja encontrado
 * (ou o caractere de nova linha, '\n').
 *
 * PARAMETROS:
 * is - stream de entrada
 * str - string de saida
 * delim - caractere de delimitação
 */

int main(int argc, char **argv)
{
    std::string String;

    // Se o tamanho da String estiver vazia, solicita ao usuario que digite uma String.
    // metodo length() retorna o tamanho da String
    if (String.length() == 0)
    {
        std::cout << "Digite uma String: ";

        // Leitura da String
        // std::cin >> String;
        std::getline(std::cin, String);

        // Imprimindo a string
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

    // Solicitando ao usuário para digitar uma frase
    std::cout << "Digite uma frase (Máx. de 100 caracteres): ";
    std::getline(std::cin, frase);

    // Limitando a entrada para até 100 caracteres usando std::cin.get() ou std::istream::read()
    if (frase.length() > TAMANHO_FRASE)
    {
        // Cortando para 100 caracteres, se necessário, Isso é feito com substr(),
        // que corta a string para o limite que você configurou.
        frase = frase.substr(0, TAMANHO_FRASE);
    }

    // Solicitando ao usuário para digitar uma palavra
    std::cout << "Digite uma palavra (máximo de 100 caracteres): ";
    std::getline(std::cin, palavra);

    // Limitando a entrada da palavra para até 100 caracteres
    if (palavra.length() > TAMANHO_PALAVRA)
    {
        // Cortando para 100 caracteres, se necessário
        palavra = palavra.substr(0, TAMANHO_PALAVRA);
    }

    // Comparando os caracteres de forma simétrica para verificar se é um palíndromo
    for (int i = 0; i < palavra.length() / 2; ++i)
    {
        if (palavra[i] != palavra[palavra.length() - 1 - i])
        {
            isPalindromo = false;
            break; // Se o par for diferente, não é palíndromo
        }
    }

    // Verificando o resultado
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
