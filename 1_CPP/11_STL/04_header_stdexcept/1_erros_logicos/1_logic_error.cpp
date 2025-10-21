#include <iostream>
#include <stdexcept>

/**
 * std::logic_error:
 * -----------------
 * É uma classe base para exceções que indicam **erros lógicos** no programa,
 * ou seja, situações em que o código está incorreto em termos de **lógica ou estrutura**,
 * e não devido a condições externas (como falhas de entrada/saída ou falta de memória).
 *
 * Esses erros normalmente **poderiam ter sido evitados** com uma verificação ou
 * uma implementação correta da lógica do programa.
 *
 * Exemplos comuns incluem:
 *  - Acesso a um índice inválido em um contêiner.
 *  - Uso incorreto de uma função ou argumento.
 *  - Violações de pré-condições (ex: chamar `pop()` em um contêiner vazio).
 *
 * Em resumo: `std::logic_error` representa falhas na **lógica interna do código**,
 * que indicam **erros de programação**, não falhas de execução.
 */

/**
 * @brief Função que verifica se um valor é válido.
 *
 * @param value O valor a ser verificado.
 * @return true se o valor for válido, caso contrário, lança uma exceção.
 * @throws std::logic_error Se o valor for inválido.
 */
bool is_valid(int value)
{
    // Exemplo de erro lógico: valor inválido
    if (value <= 0)
    {
        throw std::logic_error("Valor inválido: deve ser maior ou igual a zero.");
    }

    return true;
}

int main(int argc, char **argv)
{
    // É possível comparar um char com um double, mas não é uma comparação lógica válida.
    // De acordo com a tabela ASCII, os valores char são INTEIROS, o valor de 'a' pode ser 97.0.
    double valor_comparativo = 97.0;
    char caractere_a_comparar = 'a';

    try
    {
        if (valor_comparativo == caractere_a_comparar)
        {
            std::cout << "valor_comparativo == caractere_a_comparar" << '\n';
        }
        else
        {
            throw std::logic_error("valor_comparativo != caractere_a_comparar\n");
        }
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
    }

    std::cout << "-----------------------------------------------" << '\n';

    // Exemplo de uso da função is_valid
    try
    {
        int value = -5; // Valor inválido
        is_valid(value);
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
    }

    return 0;
}
