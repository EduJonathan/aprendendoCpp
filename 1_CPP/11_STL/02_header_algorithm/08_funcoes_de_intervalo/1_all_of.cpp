#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

/**
 * std::all_of(), que verifica se todos os elementos de um intervalo
 * satisfazem um predicado (condição específica).
 */

/**
 * @brief Verifica se um número inteiro é positivo.
 *
 * @param x Número inteiro a ser verificado.
 * @return true Se o número for maior que zero.
 * @return false Caso contrário.
 */
bool ehPositivo(int x)
{
    return x > 0;
}

/**
 * @brief Verifica se todos os caracteres de uma string são letras minúsculas.
 *
 * @param texto String a ser verificada.
 * @return true Se todos os caracteres forem minúsculos.
 * @return false Se existir pelo menos um caractere que não seja minúsculo.
 */
bool todosMinusculos(const std::string &texto)
{
    return std::all_of(texto.begin(), texto.end(), [](char c)
    { 
        return std::islower(static_cast<unsigned char>(c));
    });
}

int main(int argc, char **argv)
{
    std::vector<int> numeros = {3, 7, 1, 9, 5};

    // Verifica se todos os números são positivos
    bool todosPositivos = std::all_of(numeros.begin(), numeros.end(), ehPositivo);

    if (todosPositivos)
    {
        std::cout << "Todos os valores são positivos.\n";
    }
    else
    {
        std::cout << "Existe pelo menos um valor não positivo.\n";
    }

    std::cout << "============================================\n";

    std::string texto = "exemplo";

    // Verifica se todos os caracteres são letras minúsculas
    if (todosMinusculos(texto))
    {
        std::cout << "Todos os caracteres estão em letras minúsculas.\n";
    }
    else
    {
        std::cout << "Existe pelo menos um caractere que não está em minúsculas.\n";
    }
    return 0;
}
