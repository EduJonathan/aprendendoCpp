#include <iostream>

/**
 * Break e Continue são utilizados para controlar a execução de um laço de repetição, onde:
 *
 * BREAK: Ele interrompe a execução da estrutura de repetição.
 * CONTINUE: Ele pula para o inicio da estrutura de repetição.
 */

int main(int argc, char **argv)
{
    std::cout << "-------------------------------\n";
    std::cout << "\tBREAK" << '\n';
    std::cout << "-------------------------------\n";

    int numero = 5;
    bool sinalizar = false;

    // Verificando se o numero é primo
    for (int i = 2; i < numero / 2; ++i)
    {
        // Caso o numero nao seja primo
        if (numero % i == 0)
        {
            sinalizar = true; // Sinalizar passa a ser true, pois o numero nao eh primo
            break;            // Se encontrado um divisor, sair do laço, pois o valor não é nº primo
        }
    }

    // Se sinalizar for true, o número não é primo
    if (sinalizar)
    {
        std::cout << "O numero nao é primo" << '\n';
    }
    else
    {
        std::cout << "O numero é primo" << '\n';
    }

    std::cout << "\n-------------------------------\n";
    std::cout << "\tCONTINUE" << '\n';
    std::cout << "-------------------------------\n";

    // Imprimindo os números impares
    for (int i = 0; i <= 10; ++i)
    {
        // Caso o número seja par, continue
        if (i % 2 == 0)
        {
            // Caso o número seja par, continue
            continue;
        }

        // Imprimindo os números impares
        std::cout << i << '\n';
    }
    return 0;
}
