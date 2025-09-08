#include <iostream>
#include <new> // Para std::nothrow

/**
 * @brief Aloca dinamicamente um vetor de números double e inicializa com múltiplos de 1.5.
 *
 * @param tamanho O número de elementos a serem alocados no vetor.
 * @return Ponteiro para o vetor alocado. Retorna nullptr em caso de falha na alocação.
 *
 * @note A alocação é feita utilizando `new (std::nothrow)`, o que evita o lançamento
 * de exceções caso a alocação falhe. Em vez disso, retorna um ponteiro nulo (`nullptr`)
 * que deve ser testado para evitar acesso inválido à memória.
 */
double *alocarVetorDouble(std::size_t tamanho)
{
    // Tenta alocar a memória sem lançar exceção
    double *vetor = new (std::nothrow) double[tamanho];

    if (vetor == nullptr)
    {
        std::cerr << "Erro: Falha ao alocar memória para o vetor de double.\n";
        return nullptr;
    }

    // Inicializa os valores com múltiplos de 1.5
    for (std::size_t i{0}; i < tamanho; ++i)
    {
        vetor[i] = i * 1.5;
    }
    return vetor;
}

int main(int argc, char **argv)
{
    std::size_t tamanho = 15ull;
    double *meuVetor = alocarVetorDouble(tamanho);

    if (meuVetor != nullptr)
    {
        std::cout << "Vetor alocado e preenchido com sucesso:\n";
        for (std::size_t i{0}; i < tamanho; ++i)
        {
            std::cout << meuVetor[i] << ' ';
        }
        std::cout << '\n';

        // Libera a memória
        delete[] meuVetor;
    }
    else
    {
        std::cerr << "Operação encerrada devido à falha na alocação.\n";
    }
    return 0;
}
