#include <iostream>
#include <cstring>

/**
 * std::strcmp(): Função de comparação de duas strings
 *
 * SINTAXE: int strcmp(const char *_Str1, const char *_Str2);
 *
 * @param _Str1 Parâmetro de receber a primeira string para comparação
 * @param _Str2 Parâmetro de receber a segunda string para comparação
 * @return: Retorna um valor inteiro:
 * - 0 se as strings forem iguais.
 * - Valor negativo se _Str1 for menor que _Str2.
 * - Valor positivo se _Str1 for maior que _Str2.
 *
 * -----------------------------------------------------------------------
 *
 * std::strncmp(): Compara até `n` caracteres de duas strings lexicograficamente.
 *
 * SINTAXE: int strncmp(const char *_Str1, const char *_Str2, size_t _MaxCount);
 *
 * @param _Str1 Primeira string a ser comparada.
 * @param _Str2 Segunda string a ser comparada.
 * @param _MaxCount Número máximo de caracteres a comparar.
 * @return Retorna um valor inteiro:
 * - 0 se as primeiras _MaxCount caracteres das strings forem iguais.
 * - Valor negativo se os primeiros _MaxCount caracteres de _Str1 forem menores que os de _Str2.
 * - Valor positivo se os primeiros _MaxCount caracteres de _Str1 forem maiores que os de _Str2.
 */

int main(int argc, char **argv)
{
    char string1[] = "Programacao com C++";
    char string2[] = "Linguagem de Programacao";

    // Usando strstr para encontrar as ocorrências de "Programacao"
    char *substr1 = std::strstr(string1, "Programacao"); // procura "Programacao" em string1
    char *substr2 = std::strstr(string2, "Programacao"); // procura "Programacao" em string2

    if (substr1 != nullptr && substr2 != nullptr)
    {
        // Variáveis que irão receber a string "programação"
        char palavra1[20] = "";
        char palavra2[20] = "";

        // Copia apenas a palavra "Programação" da string1 para palavra1
        std::strncpy(palavra1, substr1, sizeof(palavra1) - 1);
        palavra1[sizeof(palavra1) - 1] = '\0'; // Garantir a terminação da string

        // Copia apenas a palavra "Programação" da string2 para palavra2
        std::strncpy(palavra2, substr2, sizeof(palavra2) - 1);
        palavra2[sizeof(palavra2) - 1] = '\0'; // Garantir a terminação da string

        // Agora comparando as palavras isoladas
        if (std::strcmp(palavra1, palavra2) == 0)
        {
            std::cout << "As palavras 'Programação' nas duas strings são iguais." << '\n';
        }
        else
        {
            std::cout << "As palavras 'Programação' nas duas strings são diferentes." << '\n';
        }
    }
    else
    {
        std::cout << "A palavra 'Programação' não foi encontrada em uma das strings." << '\n';
    }

    std::cout << "-----------------------------------" << '\n';

    const char str1[] = "Strings";
    const char str2[] = "String";
    bool stringsIguais = (std::strncmp(str1, str2, 6) == 0);

    std::cout << "As string são iguais: " << stringsIguais;

    return 0;
}
