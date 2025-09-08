#include <iostream>

/**
 * A Sobrecarga de Funções (Function Overloading): A sobrecarga de funções ocorre quando
 * várias funções possuem o mesmo nome, mas diferem no número e/ou tipo de parâmetros.
 * O compilador escolhe automaticamente a versão correta da função com base nos argumentos
 * passados.
 *
 * @note A sobrecarga **não pode ser realizada** apenas alterando o tipo de retorno.
 * Ou seja, funções com o mesmo nome, tipo de retorno diferente, mas com a mesma
 * assinatura (mesmos tipos e número de parâmetros) não são consideradas sobrecarga.
 *
 * CUIDADOS: Muitos casos de sobrecarga podem gerar confusão sobre qual função
 * será chamada, especialmente em casos de parâmetros semelhantes.
 *
 * EXEMPLOS:
 * - int calcular(int a, int b);           // Soma dois inteiros
 * - double calcular(double a, double b); // Soma dois doubles
 *
 * @note Requisitos para a sobrecarga de funções:
 * - Número diferente de parâmetros
 * - Tipos diferentes de parâmetros
 * - Ordem dos parâmetros diferente
 *
 * A sobrecarga é útil para realizar a mesma operação em diferentes tipos de dados,
 * facilitando a reutilização de código sem necessidade de nomes de funções distintos.
 */

/**
 * @brief Realiza a soma entre dois números.
 *
 * Solicita ao usuário o segundo valor, soma os dois e imprime o resultado.
 *
 * @param num Primeiro número da operação.
 */
void operacao(int &num)
{
    int num2 = 0;
    std::cout << "Entre com o segundo valor para somar ao primeiro: ";
    std::cin >> num2;

    int result = num + num2;
    std::cout << "Resultado da operação (soma): " << result << '\n';
}

/**
 * @brief Realiza a subtração de um número fornecido pelo usuário pelo valor armazenado
 *        em uma variável.
 *
 * Esta função subtrai o valor fornecido pelo usuário do valor armazenado em uma
 * variável e exibe o resultado na saída padrão.
 *
 * @param num Referência para o número que será subtraido.
 * @param num2 Número fornecido pelo usuário que será utilizado como subtrator.
 */
void operacao(int &num, int num2)
{
    int result = num - num2;
    std::cout << "Resultado da operação (subtração): " << result << '\n';
}

/**
 * @brief Realiza a multiplicação de um número por outro fornecido pelo usuário.
 *
 * Esta função solicita ao usuário um multiplicador e realiza a multiplicação do
 * número fornecido por este multiplicador. O resultado da multiplicação é
 * exibido na saída padrão.
 *
 * @param num Referência para o número que será multiplicado.
 * @param num2 Número fornecido pelo usuário que será utilizado como multiplicador.
 */
void operacao(int &num, double num2)
{
    double result = num * num2;
    std::cout << "Resultado da operação (multiplicação): " << result << '\n';
}

/**
 * @brief Realiza a divisão de um número por outro fornecido pelo usuário.
 *
 * Esta função solicita ao usuário um divisor e realiza a divisão do número
 * fornecido por este divisor. Caso o divisor seja zero, é exibida uma
 * mensagem de erro para evitar divisão por zero.
 *
 * @param num Referência para o número que será dividido.
 */
void operacao(double &num)
{
    double num2 = 0;

    std::cout << "Entre com o divisor: ";
    std::cin >> num2;

    if (num2 != 0)
    {
        double result = num / num2;
        std::cout << "Resultado da operação (divisão): " << result << '\n';
    }
    else
    {
        std::cout << "Erro: divisão por zero!" << '\n';
    }
}

int main(int argc, char **argv)
{
    int numInteiro = 0;
    double numDouble = 0.0;

    // Solicita o primeiro número inteiro
    std::cout << "Entre com o primeiro valor (inteiro): ";
    std::cin >> numInteiro;

    // Chama a função de soma
    operacao(numInteiro);

    // Solicita o segundo número para subtração
    int numSubtração = 0;
    std::cout << "\nEntre com o valor para subtração (inteiro): ";
    std::cin >> numSubtração;

    // Chama a função de subtração
    operacao(numInteiro, numSubtração);

    // Solicita o segundo número para multiplicação
    double numMultiplicação = 0.0;
    std::cout << "\nEntre com o valor para multiplicação (número decimal): ";
    std::cin >> numMultiplicação;

    // Chama a função de multiplicação
    operacao(numInteiro, numMultiplicação);

    // Solicita o valor para divisão
    std::cout << "\nEntre com o primeiro valor para divisão (decimal): ";
    std::cin >> numDouble;

    // Chama a função de divisão
    operacao(numDouble);
    return 0;
}
