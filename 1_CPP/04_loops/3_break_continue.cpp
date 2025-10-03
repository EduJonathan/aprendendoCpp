#include <iostream>

/**
 * BREAK e CONTINUE são utilizados para controlar a execução de um laço de repetição.
 *
 * BREAK: Interrompe a execução da estrutura de repetição.
 * CONTINUE: Pula para a próxima iteração do laço, ignorando o que estiver abaixo.
 */

int main(int argc, char **argv)
{
    std::cout << "-------------------------------\n";
    std::cout << "\tBREAK" << '\n';
    std::cout << "-------------------------------\n";

    int numero = 0;
    bool sinalizar = false;

    std::cout << "Digite um número para verificar se é primo: ";
    std::cin >> numero;

    if (numero <= 1)
    {
        sinalizar = true; // Números <= 1 não são primos
    }
    else
    {
        // Verificando se o número é primo
        for (int i = 2; i * i <= numero; ++i)
        {
            if (numero % i == 0)
            {
                sinalizar = true; // Encontrou um divisor => não é primo
                break;
            }
        }
    }

    if (sinalizar)
    {
        std::cout << "O número NÃO é primo.\n";
    }
    else
    {
        std::cout << "O número É primo.\n";
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
