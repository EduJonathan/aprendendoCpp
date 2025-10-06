#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

/**
 * - std::any_of(begin, end, pred)
 *   → Retorna true se pelo menos um elemento satisfaz a condição `pred`.
 */

/**
 * @brief Verifica se um número inteiro é negativo.
 *
 * @param x Número inteiro a ser verificado.
 * @return true Se o número for menor que zero.
 * @return false Caso contrário.
 */
bool ehNegativo(int x)
{
    return x < 0;
}

/**
 * @brief Verifica se uma string contém pelo menos um caractere que seja um dígito numérico.
 *
 * @param texto String a ser verificada.
 * @return true Se houver pelo menos um dígito na string.
 * @return false Caso contrário.
 */
bool contemDigito(const std::string &texto)
{
    return std::any_of(texto.begin(), texto.end(), [](char c)
    { 
        return std::isdigit(static_cast<unsigned char>(c)); 
    });
}

int main(int argc, char **argv)
{
    // Vetor com números inteiros
    std::vector<int> numeros = {3, -7, 1, 9, -5};

    // Verifica se existe pelo menos um número negativo
    bool algumNegativo = std::any_of(numeros.begin(), numeros.end(), ehNegativo);

    if (algumNegativo)
    {
        std::cout << "Existe pelo menos um número negativo no vetor.\n";
    }
    else
    {
        std::cout << "Todos os números são positivos.\n";
    }

    std::cout << "============================================\n";

    std::string texto = "Projeto Vers.: 0.42";

    // Verifica se a string contém pelo menos um dígito
    if (contemDigito(texto))
    {
        std::cout << "A string contém pelo menos um dígito.\n";
    }
    else
    {
        std::cout << "A string não contém dígitos.\n";
    }
    return 0;
}
