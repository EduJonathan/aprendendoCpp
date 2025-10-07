#include <iostream>

/**
 * WHILE: Estrutura de repetição que permite executar uma instrução enquanto
 * uma condição for verdadeira. tendo seus derivados como o DO-WHILE e WHILE-TRUE.
 *
 * WHILE: Executa o bloco de código enquanto a condição for verdadeira.
 * DO-WHILE: Executa o bloco de código pelo menos uma vez e depois verifica a condição.
 * WHILE-TRUE: Um laço infinito que só é interrompido com uma instrução de controle como `break`.
 */

int main(int argc, char **argv)
{
    std::cout << "\tWHILE" << '\n';
    std::cout << "\n-----------------------------------------------\n";

    int numero = 0;
    int digitos = 0;

    std::cout << "Digite um número: ";
    std::cin >> numero;

    // Armazenando o valor original
    int numero_original = numero;

    // Cálculo de dígitos
    while (numero != 0)
    {
        numero /= 10;
        digitos++;
    }

    // Caso especial para o número 0
    if (numero_original == 0)
    {
        digitos = 1;
    }

    std::cout << "Quantidade de digitos: " << digitos << '\n';

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "\tDO-WHILE" << '\n';

    // Corrigido: condição mais lógica para entrada no laço
    if (digitos > 0 && digitos < 10)
    {
        std::cout << "Entrei no laço do-while. Vamos incrementar o número de dígitos.\n";
        do
        {
            std::cout << "O valor de 'digitos' é: " << digitos << '\n';
            digitos++;

            // digitos < 10, pois o do-while sempre tem incremento adicional de +1
            // e se caso fosse digitos <= 10, ao entrar no while-true, a contagem
            // começaria a partir do 11
        } while (digitos < 10);
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "\tWHILE-TRUE" << '\n';

    std::cout << "Entrei no loop while-true. Vamos decrementar o número de dígitos até 0.\n";

    while (true)
    {
        std::cout << "Valor atual de 'digitos': " << digitos << '\n';
        digitos--;

        if (digitos == 0)
        {
            std::cout << "Digitos chegou a 0. Saindo do laço...\n";
            break;
        }
    }
    return 0;
}
