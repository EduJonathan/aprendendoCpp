#include <iostream>
#include <stdexcept>

/**
 * std::range_error:
 * -----------------
 * Exceção lançada para indicar que um **valor está fora do intervalo permitido**
 * ou que uma **operação numérica produziu um resultado inválido** dentro de um
 * contexto de execução.
 *
 * É uma subclasse de `std::runtime_error`, portanto representa um erro detectado
 * **em tempo de execução**, e não um erro lógico de programação.
 *
 * Exemplos de ocorrência:
 *  - Resultados numéricos que ultrapassam limites definidos pelo algoritmo.
 *  - Operações que produzem valores não representáveis em determinado tipo.
 *  - Conversões ou cálculos que extrapolam o intervalo válido esperado.
 *
 * Em resumo: `std::range_error` sinaliza que uma **operação resultou em um valor
 * fora do intervalo aceitável**, sendo um erro **de execução** relacionado a
 * **limites numéricos**.
 */

void verificaValor(int valor)
{
    if (valor < 0 || valor > 100)
    {
        throw std::range_error("Valor fora do intervalo permitido!");
    }
    else
    {
        std::cout << "Valor dentro do intervalo." << '\n';
    }
}

int main(int argc, char **argv)
{
    try
    {
        verificaValor(150); // Este valor causará uma exceção
    }
    catch (const std::range_error &e)
    {
        std::cerr << "Erro capturado: " << e.what() << '\n';
    }
    
    return 0;
}
