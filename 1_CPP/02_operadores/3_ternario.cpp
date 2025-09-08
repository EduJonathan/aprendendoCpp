#include <iostream>
#include <iomanip>

/**
 * O operador ternário (?:): Estrutura de controle que permite executar uma instrução
 * se uma condição for verdadeira e outra instrução se a condição for falsa.
 *
 * SINTAXE: (condição) ? condição verdadeira : condição falsa
 */

int main(int argc, char **argv)
{
    std::cout << "Utilizando o operador ternário dentro do std::cout" << '\n';

    // Definindo variáveis.
    float nota1 = 10.0f,
          nota2 = 8.0f,
          media = (nota1 + nota2) / 2.0f;

    // Se a string mensagem estiver vazia, imprima umas das seguintes informação do ternário
    std::string mensagem;
    std::cout << (mensagem.empty() ? "A mensagem esta vazia" : "A mensagem nao esta vazia") << '\n';

    // Utilizando o operador ternário.
    mensagem = (media >= 7.0f) ? "Aprovado" : "Reprovado";

    // Imprimindo o resultado.
    std::cout << "Media: " << media << '\n';
    std::cout << "Situação: " << mensagem << '\n';

    std::cout << "-----------------------------------------\n";

    // Definindo variáveis e armazenando condições.
    int numero = 16;
    bool isPar = (numero % 2 == 0);
    const char *trueOrFalse = (isPar) ? "Verdadeiro" : "Falso";

    // Utilizando o operador ternário dentro do std::cout.
    // Informa 1(true) ou 0(false) e se o número é par ou impar.
    std::cout << "É par? " << trueOrFalse << " -> O número " << numero << " é " << (isPar ? "Par" : "Impar");

    std::cout << "\n-----------------------------------------\n";

    // Valores para comparação.
    float n1 = 30.17f;
    float n2 = 30.15f;
    float n3 = 30.16f;

    // Utilizando o operador ternário para decidir qual dos 3 números é o maior.
    float maior = (n1 > n2) ? (n1 > n3 ? n1 : n3) : (n2 > n3 ? n2 : n3);

    // Imprimindo o resultado.
    std::cout << "O Maior entre os 3 números é -> " << std::fixed << std::setprecision(2) << maior << '\n';
    return 0;
}
