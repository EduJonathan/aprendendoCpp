#include <iostream>

/**
 * FOR: Estrutura de repetição que permite executar uma instrução enquanto uma condição
 * for verdadeira, pecorrendo uma série de etapas e valores até que a condição seja falsa.
 */

int main(int argc, char **argv)
{
    std::cout << "\tFOR" << '\n';
    std::cout << "-----------------------------------------------\n";

    int numero = 0;
    int soma = 0;

    std::cout << "Digite um numero: ";
    std::cin >> numero;

    // Usando o laço 'for' para somar os dígitos
    for (; numero != 0; numero = numero / 10)
    {
        int digito = numero % 10;
        soma += digito;
    }
    std::cout << "O resultado da soma dos dígitos é: " << soma << '\n';

    std::cout << "-----------------------------------------------\n";

    int numero1 = 0, numero2 = 0;

    std::cout << "Digite o primeiro numero para LCM e HCF: ";
    std::cin >> numero1;

    std::cout << "Digite o segundo numero para LCM e HCF: ";
    std::cin >> numero2;

    int maior = (numero1 > numero2) ? numero1 : numero2;
    int LCM = 0;

    // Calculando o LCM
    for (int i = maior; i <= (numero1 * numero2); ++i)
    {
        if ((i % numero1 == 0) && (i % numero2 == 0))
        {
            LCM = i;
            break;
        }
    }

    std::cout << "O LCM de " << numero1 << " e " << numero2 << " é: " << LCM << '\n';

    // Calculando o HCF com algoritmo de Euclides
    int a = numero1;
    int b = numero2;

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int HCF = a;

    std::cout << "O HCF de " << numero1 << " e " << numero2 << " é: " << HCF << '\n';

    std::cout << "-----------------------------------------------\n";
    return 0;
}
