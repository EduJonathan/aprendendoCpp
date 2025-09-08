#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

constexpr int limiar = 50; // Limiar para comparação

/**
 * std::runtime_error(): É uma classe de exceção que representa erros que podem ocorrer
 * durante a execução de um programa. Esses erros podem ser causados por condições
 * inesperadas, como falhas de alocação de memória, erros de entrada/saída, etc.
 */

int gerarNumeroAleatorio()
{
    return rand() % 100; // Gera um número entre 0 e 99
}

void verificaNumero(int numero)
{
    if (numero > limiar)
    {
        throw std::runtime_error("Erro: O número gerado excede o limiar permitido!");
    }
    else
    {
        std::cout << "Número dentro do intervalo permitido: " << numero << '\n';
    }
}

int main(int argc, char **argv)
{
    std::srand(std::time(nullptr)); // Inicializa o gerador de números aleatórios

    int numero = gerarNumeroAleatorio();

    try
    {
        verificaNumero(numero);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Erro capturado: " << e.what() << '\n';
    }

    return 0;
}
