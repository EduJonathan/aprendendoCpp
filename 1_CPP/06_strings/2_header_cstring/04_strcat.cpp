#include <iostream>
#include <cstring>

/**
 * std::strcat e std::strncat(): Funções de concatenação de strings
 *
 * SINTAXE: char *strcat(char *__restrict__ _Dest, const char *__restrict__ _Source);
 * @param _Dest String de destino (deve ter espaço suficiente).
 * @param _Source String de origem.
 * @return Retorna o ponteiro para _Dest após a concatenação
 *
 * ---------------------------------------------------------------
 *
 * std::strncat(): Concatena até _MaxCount caracteres de _Source a _Dest.
 * Evita transbordamento limitando o número de caracteres copiados.
 *
 * SINTAXE:
 * char *strncat(char *__restrict__ _Dest, const char *__restrict__ _Source, size_t _Count);
 *
 * @param _Dest String de destino.
 * @param _Source String de origem.
 * @param _MaxCount Número máximo de caracteres a copiar.
 * @return Retorna o ponteiro para _Dest após a concatenação.
 */

int main(int argc, char **argv)
{
    // Alocando espaço suficiente para as duas strings concatenadas
    char str1[15] = "Java"; // O tamanho do array deve ser suficiente para a concatenação
    const char *str2 = "Script";

    // Usando std::strcat para concatenar
    std::strcat(str1, str2);

    std::cout << "A concatenação das strings é \"" << str1 << "\"" << '\n';

    std::cout << "-----------------------------------" << '\n';

    char string1[20] = "Concate";
    const char *string2 = "narção";

    // Usando std::strncat para concatenar com n caracteres da strings
    std::strncat(string1, string2, std::strlen(string2) - 4);

    std::cout << "A concatenação das strings é \"" << string1 << "\"" << '\n';
    return 0;
}
