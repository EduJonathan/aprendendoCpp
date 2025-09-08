#include <iostream>
#include <cstring>

/**
 * std::strcspn(): O seu propósito é localizar o índice (a posição) do primeiro caractere
 * em uma string que pertence a um conjunto de caracteres especificado.
 *
 * SINTAXE: size_t strcspn(const char *_Str, const char *_Control);
 *
 * @param str1 A string em que a busca será realizada.
 * @param str2 A string contendo os caracteres que estamos procurando em str1.
 * @return A função retorna o número de caracteres a partir do início de str1 até o
 * primeiro caractere que aparece em str2. Ou seja, ela encontra o índice do primeiro
 * caractere em str1 que também está presente em str2.
 */

int main(int argc, char **argv)
{
    const char *str1 = "Hello, World!";
    const char *str2 = "aeiou";
    std::size_t len = std::strlen(str1);
    std::size_t pos = 0ull;

    // Repetir enquanto houver correspondências
    while (pos < len)
    {
        // Encontrar a posição do primeiro caractere de str1 que está em str2
        std::size_t found_pos = std::strcspn(str1 + pos, str2);

        // Se a posição encontrada for o tamanho restante da string, saímos do loop
        if (found_pos == len - pos)
        {
            break;
        }

        // Exibir a posição encontrada
        std::cout << "Caractere '" << str1[pos + found_pos]
                  << "' encontrado na posição " << pos + found_pos << '\n';

        // Atualizar 'pos' para continuar a busca a partir da próxima posição
        pos += found_pos + 1;
    }

    std::cout << "--------------------------------------- " << '\n';

    const char *string1 = "Good morning!";
    const char *string2 = "xyz";

    std::size_t resultado = std::strcspn(string1, string2);
    std::cout << "A posição do primeiro caractere de str1 que está em str2 é: " << resultado << '\n';

    /**
     * Como nenhum caractere de str2 ("xyz") aparece em str1 ("Good morning!"),
     * a função retorna o tamanho de str1, ou seja, 14 ou 13 caso não contabilize o '\0'.
     */
    return 0;
}
