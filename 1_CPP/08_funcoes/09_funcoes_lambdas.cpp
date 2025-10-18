#include <iostream>
#include <string>

/**
 * @brief Funções Lambda (Funções Anônimas): As funções lambda são funções anônimas,
 * ou seja, funções sem nome, definidas diretamente no local onde são usadas.
 * Elas são especialmente úteis para criar funções simples e temporárias sem
 * a necessidade de declarar uma função tradicional.
 *
 * As lambdas podem ser passadas como parâmetros para outras funções ou até mesmo
 * retornadas de outras funções, permitindo maior flexibilidade.
 *
 * SINTAXE: [capture](parameters) -> return_type { body };
 *
 * - CAPTURE: Especifica as variáveis do escopo externo que serão capturadas para uso dentro da lambda.
 * - PARAMETERS: Parâmetros da função lambda, assim como em uma função comum.
 * - RETURN: Tipo de retorno da lambda (opcional, geralmente já é inferido pelo compilador).
 * - BODY: Corpo da função, que contém a lógica ou operação executada.
 *
 * VANTAGENS:
 * - Sintaxe concisa: Lambdas oferecem uma maneira compacta e legível de escrever funções
 *   temporárias, sem a necessidade de declarar uma função completa.
 *
 * - Captura de variáveis: Permitem capturar variáveis do escopo externo, tornando-as acessíveis
 *   dentro da função, o que elimina a necessidade de passá-las explicitamente como parâmetros.
 *
 * USO: Lambdas são frequentemente usadas em contextos onde funções curtas e rápidas são
 * necessárias, como em algoritmos da Biblioteca Padrão do C++ (STL) como `std::sort`,
 * `std::find_if`, entre outros. Elas são ideais para operações temporárias e quando uma
 * função completa seria excessiva.
 */

/**
 * @brief Função que soma dois inteiros
 *
 * @param a Primeiro inteiro
 * @param b Segundo inteiro
 *
 * @return Soma de a e b
 */
inline int soma(int a, int b) { return a + b; }

/**
 * @brief Função que soma dois inteiros usando uma expressão lambda
 *
 * @param n1 Primeiro inteiro
 * @param n2 Segundo inteiro
 *
 * @return Soma de n1 e n2
 */
inline int lambdaSoma(int n1, int n2)
{
    /** expressão lambda que retorna o resultado da soma */
    auto somaLambda = [](int a, int b) -> int
    {
        return a + b;
    };

    /** chama a expressão lambda */
    return somaLambda(n1, n2);
}

int main(int argc, char **argv)
{
    /** expressão lambda que imprime "Olá Função Lambda!" */
    auto ola = []()
    {
        std::cout << "Olá Função Lambda!" << "\n";
    };

    // Chama a função lambda
    ola();

    std::cout << "==================================" << '\n';

    std::string mensagem = "Função Lambda!";

    /** expressão lambda que passa uma string como argumento e imprime a string */
    auto string = [](std::string msg)
    {
        std::cout << msg << '\n';
    };

    // Passa a string como argumento
    string(mensagem);

    std::cout << "==================================" << '\n';

    int x = 5;

    /** expressão lambda que modifica x por referência */
    auto ref = [&x]()
    {
        // Modifica x por referência
        x = 10;
    };

    // Imprime "Novo valor de x: 10"
    std::cout << "Novo valor de x: " << x << '\n';

    std::cout << "==================================" << '\n';

    int resultadoSoma = soma(5, 4);
    int resultadoLambda = lambdaSoma(5, 4);

    std::cout << "Soma: " << resultadoSoma << '\n';
    std::cout << "Lambda: " << resultadoLambda << '\n';
    return 0;
}
