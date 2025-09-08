#include <iostream>

/**
 * O SWITCH_CASE: Estrutura de controle que permite executar uma instrução que
 * dependendo da leitura de uma condição for verdadeira entrará em execução de caso.
 */

int main(int argc, char **argv)
{
    // Declarando uma variavel do tipo inteiro.
    int x = 4;

    // Imprimindo o valor da variavel antes do switch case.
    std::cout << "Valor de x antes do switch case: " << x << '\n';

    // Utilizando o switch case para receber um número do usuário.
    std::cout << "Digite um número: ";
    std::cin >> x;
    std::cout << "Voce digitou: " << x << '\n';

    // Utilizando o switch case para executar uma instrucao dependendo de uma condicao.
    switch (x)
    {
    case 1:
        std::cout << "O número digitado foi: " << x << '\n';
        break;

    case 2:
        std::cout << "O número digitado foi: " << x << '\n';
        break;

    case 3:
        std::cout << "O número digitado foi: " << x << '\n';
        break;

    default:
        std::cout << "Os números 1, 2 ou 3 não foi o valor de x" << '\n';
        break;
    }

    return 0;
}
