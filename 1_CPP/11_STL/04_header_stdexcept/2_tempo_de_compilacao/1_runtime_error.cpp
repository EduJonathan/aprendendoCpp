#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

constexpr int limiar = 50; // Limiar para comparação

/**
 * std::runtime_error:
 * -------------------
 * Classe base para exceções que indicam **erros detectados durante a execução**
 * do programa, geralmente causados por **condições externas ou imprevistas**, e
 * não por falhas de lógica no código.
 *
 * Diferente de `std::logic_error`, que representa erros de programação,
 * `std::runtime_error` está relacionada a **situações que só podem ser detectadas
 * em tempo de execução**, após o programa já estar em execução normal.
 *
 * Exemplos de ocorrência:
 *  - Falha na alocação de memória.
 *  - Erros de leitura ou escrita em arquivos.
 *  - Perda de conexão com um recurso externo (como rede ou banco de dados).
 *  - Cálculos que resultam em valores inválidos detectados apenas em tempo de execução.
 *
 * Em resumo: `std::runtime_error` sinaliza **erros imprevistos durante a execução**
 * que **não poderiam ser evitados apenas com uma lógica de programação correta**.
 */

int gerarNumeroAleatorio()
{
    return std::rand() % 100; // Gera um número entre 0 e 99
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
