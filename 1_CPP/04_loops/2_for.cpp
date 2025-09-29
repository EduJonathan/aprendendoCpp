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
        int result = numero % 10; // Pega o último dígito
        soma += result;           // Soma esse dígito à variável 'soma'
    }
    std::cout << "O resultado da soma dos digitos é: " << soma << '\n';

    std::cout << "-----------------------------------------------\n";

    int numero1 = 5;   // Números para calcular o LCM e HCF
    int numero2 = 8;   // Números para calcular o LCM e HCF
    int resultado = 0; // Variável para armazenar o resultado do LCM
    int LMC = 0;       // LMC(Least Common Multiple) menor múltiplo comum
    int HCF = 0;       // HCF(Highest Common Factor) maior comum divisor

    // Calculando o LCM, se numero1 for maior que numero2
    // O resultado recebe o valor de numero1 ou numero2
    resultado = (numero1 > numero2) ? numero1 : numero2;

    // Calculando o LCM
    for (int i = resultado; i <= (numero1 * numero2); ++i)
    {
        // Se o resto da divisão de i por numero1 for igual a zero e o resto da divisão
        // de 'i' por numero2 for igual a zero
        if ((i % numero1 == 0) && (i % numero2 == 0))
        {
            LMC = i; // O LMC recebe o valor de i
            break;
        }
    }

    // Imprimindo o LCM
    std::cout << "O LCM de " << numero1 << " e " << numero2 << " é: " << LMC << '\n';

    // Calculando o HCF
    HCF = (numero1 * numero2) / LMC;

    // Imprimindo o HCF
    std::cout << "O HCF de " << numero1 << " e " << numero2 << " é: " << HCF << '\n';
    return 0;
}
