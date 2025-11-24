#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept> // Biblioteca para exceções padrão

/**
 * TRY-CATCH: São keywords usadas para lidar com erros. Muito utilizados para tratamento
 * de exceções dentro de funções.
 * THROW: Usado para lançar a exceção, indicando um erro.
 *
 * @note Diferença entre (try-catch) para o (if-else) if-else condiciona o controle do
 * fluxo da execução do programa, enquanto o try-catch é utilizado para capturar/obter
 * erros inesperados durante a execução do programa.
 */

/**
 * @brief Função para dividir dois números.
 *
 * @param num1 Primeiro número.
 * @param num2 Segundo número.
 * @return Retorna a divisão de 2 números
 */
double divisao(double num1, double num2)
{
    if (num2 == 0.0)
    {
        // Lançando uma exceção, mais detalhadas na prática
        throw std::runtime_error("Não é possível divisão por 0! Divisor: " + std::to_string(num2));
        // poder ser: throw std::runtime_error("Não é possivel divisão por 0!");
        // Como também pode ser: throw "Erro de divisão por 0!";
    }
    return num1 / num2;
}

/**
 * @brief Função que lê um índice de um vetor e verifica se ele é válido.
 *        Se o índice for inválido, lança uma exceção do tipo std::out_of_range.
 *
 * @param vec Vetor que será acessado.
 *
 * @note Essa função demonstra o uso do método at() do vetor, que lança uma
 *       exceção se o índice for inválido. Além disso, também é demonstrado como
 *       capturar e exibir a mensagem de erro da exceção.
 */
void indexOutOfBounds(std::vector<int> &vec)
{
    int index = 0; // Declarar a variável local para o índice

    // Solicita o índice ao usuário, vec.size() - 1 para garantir que o índice seja válido
    // e também vec.size informa o tamanho de vector
    std::cout << "Informe o índice para acessar o vetor(de 0 a " << vec.size() - 1 << "): ";
    std::cin >> index;

    try
    {
        // Usando .at() que lança uma exceção se o índice for inválido
        // O metodo .at() retorna um elemento presente no índice 'i' como parâmetro de um
        // determinado array, se 'i' for um índice válido; caso contrário,
        // lança uma exceção out_of_range.
        std::cout << "Valor no índice " << index << ": " << vec.at(index) << '\n';
    }
    catch (const std::out_of_range &erro)
    {
        // Captura a exceção e exibe a mensagem de erro
        std::cout << "Erro: " << erro.what() << '\n';
    }
}

int main(int argc, char **argv)
{
    double num1 = 10.0;
    double num2 = 0.0;

    // Tente dividir num1 por num2
    try
    {
        // Chamando a função para dividir num1 por num2
        double resultado = divisao(num1, num2);

        // Divisão for bem-sucedida, imprima o resultado
        std::cout << "Resultado: " << std::fixed << std::setprecision(4) << resultado << '\n';
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << "Erro: " << err.what() << '\n'; // Exceção capturada
    }

    std::cout << "-------------------------------------" << '\n';

    double numero1 = 55.0;
    double numero2 = 5.0;

    // Tente dividir num1 por num2
    try
    {
        // Chamando a função para dividir num1 por num2
        double resultado = divisao(numero1, numero2);

        // Divisão for bem-sucedida, imprima o resultado
        std::cout << "Resultado: " << std::fixed << std::setprecision(4) << resultado << '\n';
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << "Erro: " << err.what() << '\n'; // Exceção capturada
    }

    std::cout << "-------------------------------------" << '\n';

    std::vector<int> vec = {10, 20, 30, 40, 50}; // Criando um vetor de exemplo
    indexOutOfBounds(vec);                       // Chamando a função para acessar um índice

    return 0;
}
