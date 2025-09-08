#include <iostream>
#include <string>

/**
 * @brief Função que imprime o titulo
 *
 * Função que imprime o titulo "====>>FUNÇÕES<<===="
 *
 * @return uma string
 */
const char *imprimeTitulo(void) { return "\n====>> FUNÇÕES <<====\n"; }

/**
 * @brief Prompt para o nome de um usuário
 *
 * Esta função recebe o nome de um usuário e imprime uma saudação.
 * Caso nenhum nome seja fornecido, o valor padrão será "Eduardo".
 *
 * @param nome Nome do usuário (valor padrão: "Eduardo").
 */
void printUser(std::string nome = {"Eduardo"}) { std::cout << "Olá, " << nome << '\n'; }

/**
 * @brief Calcula a idade de um usuário
 *
 * Função que pede ao usuário o ano atual e o ano de nascimento e retorna a idade
 *
 * @returns idade do usuário
 */
int idade(void)
{
    int anoAtual = 0, anoNascimento = 0;

    std::cout << "Digite o \"ANO\" atual: ";
    std::cin >> anoAtual;

    std::cout << "Digite o \"ANO\" de seu nascimento: ";
    std::cin >> anoNascimento;

    return anoAtual - anoNascimento;
}

/**
 * @brief Soma dois números double e imprissão do resultado
 *
 * Função que soma dois números e imprime o resultado
 *
 * @param num1 Primeiro número
 * @param num2 Segundo número
 * @returns A soma dos dois números
 *
 * @note O auto é uma declaração para que variáveis sejam inferidas automaticamente
 * mas que necessariamente precisam ser inicializadas de imediato, o "->" informa o
 * tipo de retorno.
 */
auto soma(double num1, double num2) -> double
{
    std::cout << "A soma de " << num1 << " + " << num2 << " = ";
    return num1 + num2;
}

/**
 * @brief Calcula o fatorial de um número
 *
 * Função que calcula o fatorial de um número
 *
 * @param number Número para calcular o fatorial
 * @return O fatorial do número
 *
 * @note O inline faz com que a função seja executada na linha em que ela foi declarada
 * estas funções são expandidas em linha quando invocadas, reduzindo potencialmente a
 * sobrecarga de chamadas de funções para funções pequenas e frequentemente chamadas
 */
inline unsigned int fatorial(int number)
{
    int fator = 1;

    for (int i = number; i > 0; --i)
    {
        fator *= i;
    }
    return fator;
}

int main(int argc, char **argv)
{
    std::cout << imprimeTitulo() << '\n'; // ====>> FUNÇÕES <<====
    printUser("EDUARDO");                 // Olá, Eduardo

    std::cout << idade() << " anos de idade" << '\n';

    std::cout << "\n=========================\n";

    printUser("Maria"); // Olá, Maria

    std::cout << idade() << " anos de idade" << '\n';

    std::cout << "\n=========================\n";

    // Declarando variáveis
    auto num1{40.5};
    auto num2{30.5};

    // Chamando a função soma
    std::cout << soma(num1, num2) << '\n';

    std::cout << "\n=========================\n";

    std::cout << "O fatorial de 5 é: " << fatorial(5u) << '\n';
    return 0;
}
