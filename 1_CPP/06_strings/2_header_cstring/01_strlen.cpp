#include <iostream>
#include <cstring>

/**
 * std::strlen(): Função para obter retornando o tamanho (comprimento) de uma string,
 * tendo seu derivado, o `strnlen`, que permite obter o comprimento até um número
 * definido de caracteres da string.
 *
 * SINTAXE: size_t strlen(const char* str);
 *
 * @param str Ponteiro para a string (C-style) (array de caracteres terminada por '\0').
 * @return Retorna o número de caracteres (sem contar o '\0').
 *
 * -----------------------------------------------------------
 *
 * SINTAXE: size_t strnlen(const char* str, size_t max_len);
 *
 * @param str Ponteiro para a string (C-style).
 * @param max_len Número máximo de caracteres a serem verificados.
 * @return Retorna o número de caracteres até o '\0' ou até max_len, o que ocorrer primeiro.
 */

int main(int argc, char **argv)
{
    const char *string = "Linguagem C++";
    std::size_t len = std::strlen(string);

    std::cout << "O tamanho da string " << string << " é >> " << len;

    std::cout << "\n-----------------------------------" << '\n';

    const char str1[] = "Java";
    const char str2[] = "JavaScript";

    // Calculando o tamanho das primeiras 4 letras de cada string
    std::size_t lenStr1 = strnlen(str1, 4);
    std::size_t lenStr2 = strnlen(str2, 4);

    // Comparando os tamanhos
    bool stringsIguais = (lenStr1 == lenStr2);

    if (stringsIguais)
    {
        std::cout << "As 4 primeiras letras são iguais" << '\n';
    }
    else
    {
        std::cout << "As 4 primeiras letras não são iguais" << '\n';
    }

    return 0;
}
