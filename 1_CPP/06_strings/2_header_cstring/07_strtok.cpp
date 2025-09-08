#include <iostream>
#include <cstring>

/**
 * std::strtok(): Função usada em C++ para dividir uma string em pedaços menores,
 * conhecidos como tokens, com base em um delimitador fornecido.
 *
 * SINTAXE: char *strtok(char *__restrict__ _Str, const char *__restrict__ _Delim);
 *
 * PARAMETROS:
 * @param str A string que será tokenizada. Após a primeira chamada, deve ser nullptr para
 * continuar a tokenização da mesma string.
 * @param delimiters Uma string contendo os caracteres delimitadores usados para dividir a string.
 * @return Retorna um ponteiro para o primeiro caractere do próximo token ou um ponteiro nulo se
 * não houver nenhum token.
 */

int main(int argc, char **argv)
{
    // String original
    char str[] = "C++ é incrível, prático e poderoso!";

    // Delimitadores (neste caso, espaço e vírgula)
    const char *delimiters = " ,";

    // Primeira chamada para strtok
    char *token = std::strtok(str, delimiters);

    // Continua a extrair os tokens enquanto não for NULL
    while (token != NULL)
    {
        std::cout << "Token: " << token << '\n';
        token = std::strtok(NULL, delimiters); // Próximo token
    }

    std::cout << "---------------------------" << '\n';

    char str[] = "Hello, world! Welcome to C++ programming.";
    const char *delimitadores = " ,.!";
    char *tokens = std::strtok(str, delimitadores);

    while (token != NULL)
    {
        std::cout << tokens << '\n';
        tokens = std::strtok(NULL, delimitadores);
    }
    return 0;
}
