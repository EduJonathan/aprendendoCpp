#include <iostream>
#include <cstdlib>
#include <cstring>

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
    if (argc != 4)
    {
        std::cerr << "O codigo permite apenas 3 argumentos." << '\n'
                  << "TENTE: argum1 + argum2 no terminal antes de compilar" << '\n';
        return 1;
    }

    int num1 = std::atoi(argv[1]);
    int num2 = std::atoi(argv[3]);

    if ((num1 == 0) && (num2 == 0))
    {
        std::cout << "0 é um valor não válido" << '\n';
        return 1;
    }

    /* Lógica para o segundo argumento do vetor receber um sinal de operação */
    const char *operacao = argv[2];
    char sinalDeOperacao = '\0';

    if ((std::strlen(operacao) == 1) &&
        (operacao[0] == '+' || operacao[0] == '-' ||
         operacao[0] == 'x' || operacao[0] == '/'))
    {
        sinalDeOperacao = operacao[0];
    }
    else
    {
        std::cerr << "Operacao nao valida." << '\n';
        return 1;
    }

    switch (sinalDeOperacao)
    {
    case '+':
        std::cout << num1 << " + " << num2 << ": " << num1 + num2 << '\n';
        break;

    case '-':
        std::cout << num1 << " - " << num2 << ": " << num1 - num2 << '\n';
        break;

    case 'x':
        std::cout << num1 << " x " << num2 << ": " << num1 * num2 << '\n';
        break;

    case '/':
        if (num2 == 0)
        {
            std::cout << "Divisão por zero não permitida." << '\n';
            return 1;
        }

        std::cout << num1 << " / " << num2 << ": " << num1 / num2 << '\n';
        break;
    }

    /**
     * Compile e execute com
     * g++ .\03_param_main.cpp
     * .\a.exe 12 + 45
     */
    return 0;
}
