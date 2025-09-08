#include <iostream>
#include <cstring>

/**
 * std::strpbrk(): Função em C++ é usada para localizar o primeiro caractere em uma
 * string que corresponde a qualquer caractere de um conjunto específico. É útil para
 * verificar a presença de caracteres específicos em uma string.
 *
 * SINTAXE: inline const char *strpbrk(const char *__s1, const char *__s2);
 *
 * PARAMETROS:
 * @param str A string a ser analisada.
 * @param accept O conjunto de caracteres que estamos procurando na string. *
 * @return Um ponteiro para o primeiro caractere correspondente encontrado em str.
 * Retorna nullptr se nenhum dos caracteres em accept for encontrado em str.
 */

int main(int argc, char **argv)
{
    const char *str = "Olá, mundo!";
    const char *accept = "aeiou";

    // Localiza o primeiro caractere de 'accept' em 'str'
    const char *result = std::strpbrk(str, accept);

    if (result != nullptr)
    {
        std::cout << "Primeiro caractere encontrado: " << *result << '\n';
    }
    else
    {
        std::cout << "Nenhum caractere correspondente encontrado." << '\n';
    }
    return 0;
}
