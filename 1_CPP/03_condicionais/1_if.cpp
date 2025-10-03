#include <iostream>

/**
 * IF: estrutura de controle condicional que permite executar um fluxo de instruções
 * com base em uma condição. Se a condição for verdadeira, o bloco de código dentro
 * do IF será executado. Caso contrário, o fluxo de execução continuará.
 */

int main(int argc, char **argv)
{
    std::cout << "\tIF UNIDIRECIONAL\n";

    if ((5 + 1) == 6)
        std::cout << "Sim! 5 + 1 é igual a 6" << '\n';

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "\tIF BIDIRECIONAL\n";

    if ('a' == 97)
    {
        std::cout << "Sim! o decimal do caractere 'a' é igual a 97" << '\n';
    }
    else
    {
        std::cout << "Não! o decimal do caractere 'a' não é igual a 97" << '\n';
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "\tIF ELSE-IF\n";

    if ((3 < 2) && (4 < 5))
    {
        std::cout << "Sim! 3 é maior que 2 e 4 é menor que 5" << '\n';
    }
    else if ((2 & 3) == 5)
    {
        std::cout << "Sim! 2 & 3 é igual a 5" << '\n';
    }
    else
    {
        std::cout << "Nenhuma das condições foi verdadeira" << '\n';
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "\tIF ANINHADO\n";

    double valor = 4.5; // Variável que recebe o valor de 4.5

    if (valor > 0.0)
    {
        std::cout << "O valor " << valor << " é maior que zero" << '\n';

        valor += 15.0; // Adiciona 15.0 ao valor

        if (valor < 20.0)
        {
            std::cout << "O valor " << valor << " é menor que 20" << '\n';
        }
        else
        {
            std::cout << "O valor " << valor << " é maior que 20" << '\n';
        }
    }
    else
    {
        std::cout << "O valor não entrou na condição" << '\n';
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "\t EXPRESSÃO Booleana\n";

    bool valorNegado = true;

    if (!valorNegado)
    {
        std::cout << "A variável não foi negada? " << valorNegado << '\n';
    }
    else
    {
        std::cout << "A variável foi negada? " << valorNegado << '\n';
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "\t EXPRESSÃO MAIOR DE TRÊS NÚMEROS\n";

    int maior = 0;
    int valor1 = 15;
    int valor2 = 20;
    int valor3 = -35;

    // Verifica qual é o maior valor utilizando if
    if ((valor1 >= valor2) && (valor1 >= valor3))
    {
        maior = valor1;
    }
    else if ((valor2 >= valor1) && (valor2 >= valor3))
    {
        maior = valor2;
    }
    else
    {
        maior = valor3;
    }

    // Exibe o resultado
    std::cout << "O maior valor é: " << maior << '\n';
    return 0;
}
