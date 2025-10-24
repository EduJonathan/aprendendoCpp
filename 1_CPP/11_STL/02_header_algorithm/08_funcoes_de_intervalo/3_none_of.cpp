#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

/**
 * - std::none_of(begin, end, pred)
 *   → Retorna true se nenhum elemento satisfaz a condição `pred`.
 */

/**
 * @brief Verifica se um número inteiro é negativo.
 *
 * @param x Número a ser analisado.
 * @return true Se o número for menor que zero.
 * @return false Caso contrário.
 */
bool ehNegativo(int x)
{
    return x < 0;
}

/**
 * @brief Verifica se uma string não contém caracteres especiais (ou seja, se todos os
 * caracteres são alfanuméricos).
 *
 * @param texto A string a ser verificada.
 * @return true Se todos os caracteres forem alfanuméricos.
 * @return false Se existir pelo menos um caractere especial.
 */
bool naoContemCaracteresEspeciais(const std::string &texto)
{
    return std::none_of(texto.begin(), texto.end(), [](char c)
    { 
        return !std::isalnum(static_cast<unsigned char>(c));
    });
}

int main(int argc, char **argv)
{
    std::vector<int> numeros = {-3, 7, 1, 9, 5};

    // Verifica se nenhum número é negativo
    bool nenhumNegativo = std::none_of(numeros.begin(), numeros.end(), ehNegativo);

    if (nenhumNegativo)
    {
        std::cout << "Nenhum número é negativo no vetor.\n";
    }
    else
    {
        std::cout << "Existe pelo menos um número negativo.\n";
    }

    std::cout << "============================================\n";

    std::string texto = "Texto123";

    // Verifica se a string contém apenas caracteres alfanuméricos
    if (naoContemCaracteresEspeciais(texto))
    {
        std::cout << "A string não contém caracteres especiais.\n";
    }
    else
    {
        std::cout << "Existe pelo menos um caractere especial na string.\n";
    }
    return 0;
}
