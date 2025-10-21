#include <iostream>
#include <cmath>
#include <stdexcept>

/**
 * std::invalid_argument:
 * ----------------------
 * Exceção lançada quando uma função ou método recebe um **argumento inválido**
 * — ou seja, um valor que não atende aos critérios esperados pela função.
 *
 * É comumente utilizada para **validação de parâmetros de entrada**, garantindo
 * que os valores fornecidos estejam dentro de um intervalo válido ou tenham
 * o formato correto antes de prosseguir com a execução.
 *
 * Exemplos de uso:
 *  - Passar um número negativo onde apenas valores positivos são aceitos.
 *  - Fornecer uma string vazia quando um valor não vazio é obrigatório.
 *  - Inserir um parâmetro em formato incorreto (ex: “abc” onde se esperava um número).
 *
 * Em resumo: `std::invalid_argument` é usada para sinalizar **erros de uso da função**,
 * quando o problema está **nos valores passados como argumentos**.
 */

/**
 * @brief Calcula a raiz quadrada de um número decimal (não inteiro).
 *
 * @param value O valor do qual se deseja extrair a raiz quadrada.
 * @return double A raiz quadrada do valor.
 * @throws std::invalid_argument Se o valor for negativo ou inteiro.
 */
inline double raiz_quadrada(double value)
{
    // Verifica se o valor é negativo
    if (value < 0)
    {
        throw std::invalid_argument("Valor inválido: número negativo.");
    }

    // Verifica se o número é inteiro
    double parte_inteira = 0.0;

    if (std::modf(value, &parte_inteira) == 0.0)
    {
        throw std::invalid_argument("Valor inválido: número inteiro fornecido. Use um número com casas decimais.");
    }
    return std::sqrt(value);
}

/**
 * @brief Define a idade de uma pessoa.
 *
 * @param idade A idade a ser definida.
 * @throws std::invalid_argument Se a idade for inválida (menor que 0 ou maior que 100).
 */
void definirIdade(int idade)
{
    if (idade < 0 || idade > 100)
    {
        throw std::invalid_argument("Idade inválida! Deve estar entre 0 e 100.");
    }

    std::cout << "Idade definida com sucesso: " << idade << '\n';
}

int main(int argc, char **argv)
{
    // Teste 1: valor decimal válido
    try
    {
        double numero_decimal = 9.5;
        double resultado = raiz_quadrada(numero_decimal);
        std::cout << "Raiz quadrada de " << numero_decimal << " é " << resultado << '\n';
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Erro (decimal): " << e.what() << '\n';
    }

    std::cout << "--------------------------------------\n";

    // Teste 2: valor inteiro (inválido para esta função)
    try
    {
        double numero_inteiro = 9.0;
        double resultado = raiz_quadrada(numero_inteiro);
        std::cout << "Raiz quadrada de " << numero_inteiro << " é " << resultado << '\n';
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Erro (inteiro): " << e.what() << '\n';
    }

    std::cout << "--------------------------------------\n";

    // Teste 3: valor negativo (para definirIdade) em um try-catch aninhado
    try
    {
        try
        {
            definirIdade(150); // Idade inválida
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "[Interno] Erro ao definir idade: " << e.what() << '\n';
            throw; // Repassa para o try externo
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Externo] Erro capturado no main: " << e.what() << '\n';
    }

    return 0;
}
