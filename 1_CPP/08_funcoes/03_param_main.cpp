#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>

/**
 * @brief Realiza uma operação aritmética com base nos argumentos da linha de comando.
 *
 * @param argc Número de argumentos (esperado 4: programa, num1, operador, num2).
 * @param argv Vetor de argumentos (argv[1]: num1, argv[2]: operador, argv[3]: num2).
 * @return int Resultado da operação ou INT_MIN em caso de erro.
 */
int retorna_operacao(int argc, char **argv)
{
    // Verifica se o número de argumentos é correto
    if (argc != 4)
    {
        std::cerr << "O programa requer exatamente 3 argumentos.\n"
                  << "Uso: " << argv[0] << " <numero1> <operador> <numero2>\n"
                  << "Exemplo: " << argv[0] << " 12 + 45\n";
        return INT_MIN;
    }

    // Converte os argumentos numéricos
    char *endptr = nullptr;
    long num1 = std::strtol(argv[1], &endptr, 10);
    if (*endptr != '\0')
    {
        std::cerr << "Erro: '" << argv[1] << "' não é um número válido.\n";
        return INT_MIN;
    }

    long num2 = std::strtol(argv[3], &endptr, 10);
    if (*endptr != '\0')
    {
        std::cerr << "Erro: '" << argv[3] << "' não é um número válido.\n";
        return INT_MIN;
    }

    // Verifica limites de inteiros
    if (num1 < INT_MIN || num1 > INT_MAX || num2 < INT_MIN || num2 > INT_MAX)
    {
        std::cerr << "Erro: Números fora do intervalo de int.\n";
        return INT_MIN;
    }

    // Valida o operador
    const char *operacao = argv[2];
    if (std::strlen(operacao) != 1 ||
        (operacao[0] != '+' && operacao[0] != '-' && operacao[0] != 'x' && operacao[0] != '/'))
    {
        std::cerr << "Erro: Operador inválido. Use +, -, x ou /.\n";
        return INT_MIN;
    }

    char sinalDeOperacao = operacao[0];
    int result = 0;

    // Realiza a operação
    switch (sinalDeOperacao)
    {
    case '+':
        result = static_cast<int>(num1 + num2);
        break;

    case '-':
        result = static_cast<int>(num1 - num2);
        break;

    case 'x':
        result = static_cast<int>(num1 * num2);
        break;

    case '/':
        if (num2 == 0)
        {
            std::cerr << "Erro: Divisão por zero não permitida.\n";
            return INT_MIN;
        }
        result = static_cast<int>(num1 / num2);
        break;

    default:
        std::cerr << "Erro: Operador inválido.\n";
        return INT_MIN;
    }

    return result;
}

/**
 * Os parâmetros da função main():
 *
 * @param argc Arguments count - Total de número de argumentos na linha de comando.
 * @param argv Arguments vector - Array de string no C-style que contém cada argumento,
 * normalmente o argv[0] contém o nome do programa.
 * @return int retorna 0 para confirmar êxito do programa.
 *
 * @note Lembrando que eles não são obrigatórios a está em seu código.
 */
int main(int argc, char **argv)
{
    int resultado = retorna_operacao(argc, argv);
    if (resultado == INT_MIN)
    {
        return 1; // Erro
    }

    // Exibe o resultado
    std::cout << argv[1] << ' ' << argv[2] << ' ' << argv[3] << ": " << resultado << '\n';

    /**
     * Compile e execute com:
     * g++ -std=c++17 calculator.cpp -o calculator
     * ./calculator 12 + 45
     */
    return 0;
}
