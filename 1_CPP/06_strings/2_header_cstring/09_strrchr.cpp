#include <iostream>
#include <cstring>

/**
 * std::strchr(): Encontra a primeira ocorrência de um caractere em uma string.
 *
 * SINTAXE: inline const char *strchr(const char *__s, int __c);
 * @param __s Parâmetro para string
 * @param __c Parâmetro para caractere
 * @return Retorna um ponteiro para a primeira ocorrência do caractere ch na string str,
 * ou nullptr se o caractere não for encontrado.
 *
 * -------------------------------------------------------------
 *
 * std::strrchr(): Encontra a última ocorrência de um caractere em uma string.
 *
 * SINTAXE: inline const char *strrchr(const char *__s, int __c);
 * @param __s Parâmetro para string
 * @param __c Parâmetro para caractere
 * @return Retorna Ponteiro para a última ocorrência do caractere ch na string str,
 * ou nullptr se o caractere não for encontrado.
 * @note std::strchr e std::strrchr são case sensitive
 */

int main(int argc, char **argv)
{
    const char *string = "Linguagem C++?";
    const char *caracteresLocalizados = "aeiou+?c";

    // Iterar sobre os caracteres de string
    for (std::size_t i = 0ull; i < std::strlen(string); ++i)
    {
        // Verificar se o caractere de string está presente em caracteresLocalizados
        if (std::strchr(caracteresLocalizados, string[i]))
        {
            std::cout << "Caractere '" << string[i] << "' encontrado na posição " << i << '\n';
        }
    }

    std::cout << "---------------------------" << '\n';

    const char *str = "Hello, World!";
    const char *result = std::strrchr(str, 'o');
    const char *encontrado = std::strrchr(str, 'O');

    if (result)
    {
        std::cout << "Ultima ocorrência de 'o' está em: " << result - str << '\n';
    }
    else
    {
        std::cout << "'o' não encontrado." << '\n';
    }

    if (encontrado)
    {
        std::cout << "Ultima ocorrência de 'O' está em: " << result - str << '\n';
    }
    else
    {
        std::cout << "'O' não encontrado." << '\n';
    }
    return 0;
}
