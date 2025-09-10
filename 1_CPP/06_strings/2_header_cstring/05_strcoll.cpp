#include <iostream>
#include <clocale>
#include <cstring>

/**
 * std::strcoll(): Função em C++ usada para comparar duas strings de acordo com as
 * configurações de localização (locale).
 *
 * SINTAXE: int strcoll(const char *_Str1, const char *_Str2);
 *
 * PARAMETROS:
 * @param str1 Primeiro ponteiros para os primeiros caracteres das strings que você deseja comparar.
 * @param str2 Segundo ponteiros para os primeiros caracteres das strings que você deseja comparar.
 * @return Um valor inteiro que indica a relação entre as strings:
 * (<) Menor que 0: str1 é menor que str2 na ordem definida pelo locale.
 * (==) Igual a 0: str1 é equivalente a str2 na ordem definida pelo locale.
 * (>) Maior que 0: str1 é maior que str2 na ordem definida pelo locale.
 */

int main(int argc, char **argv)
{
    // Configura a localização para o padrão atual do sistema
    std::setlocale(LC_COLLATE, "pt_BR.UTF-8");

    const char *str1 = "não";
    const char *str2 = "sim";

    int result = std::strcoll(str1, str2);

    if (result < 0)
    {
        std::cout << "\'" << str1 << "\' vem antes de \'" << str2 << "\' na ordenação do locale." << '\n';
    }
    else if (result == 0)
    {
        std::cout << "\'" << str1 << "\' é equivalente a \'" << str2 << "\' no locale atual." << '\n';
    }
    else
    {
        std::cout << "\'" << str1 << "\' vem depois de \'" << str2 << "\' na ordenação do locale." << '\n';
    }
    return 0;
}
