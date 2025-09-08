#include <iostream>
#include <chrono> // Header que servirá para medir milisegundos

const int SIZE = 1000; // Número de iterações

/**
 * @brief Realiza alocação de arrays na stack e mede o tempo necessário.
 *
 * @param size Tamanho do array a ser alocado em cada iteração.
 */
void AlocandoNaStack(int size)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; ++i)
    {
        int array[size]; // Alocação na stack (tamanho variável)
        (void)array;     // Evitar warnings de variável não usada
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start; // Tempo em milissegundos
    std::cout << "Tempo de alocacao na stack (" << size << " inteiros): " << duration.count() << " ms\n";
}

/**
 * @brief Realiza alocação de arrays na heap e mede o tempo necessário.
 *
 * @param size Tamanho do array a ser alocado em cada iteração.
 */
void AlocandoNaHeap(std::size_t size)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; ++i)
    {
        int *array = new int[size]; // Alocação na heap
        delete[] array;             // Liberação imediata para não acumular memória
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start; // Tempo em milissegundos
    std::cout << "Tempo de alocacao na heap (" << size << " inteiros): " << duration.count() << " ms\n";
}

int main(int argc, char **argv)
{
    std::cout << "Comparando tempos de alocacao (Stack vs Heap):\n";
    std::cout << "Numero de iterações: " << SIZE << "\n";
    std::cout << "Tamanho de cada alocacao: 10000 inteiros (" << (10000 * sizeof(int)) << " bytes)\n\n";

    // Stack pequena (1000 inteiros)
    AlocandoNaStack(1000);
    AlocandoNaHeap(1000);

    // Heap pequena (10000 inteiros)
    AlocandoNaStack(10000);
    AlocandoNaHeap(10000);

    /**
     * @note Explicação: O código consiste em medir o tempo que é mais rápido alocar
     * entre 1000 e 10000 na stack ou heap
     *
     * Stack: Muito mais rápida para alocações, pois só precisa mover o ponteiro da stack.
     * - A alocação na stack é basicamente um ajuste em um ponteiro (como mover o "topo
     * da pilha").
     * - Não há chamada ao sistema operacional.
     *
     * --------------
     *
     * Heap: É um pouca mais lenta devido à complexidade do gerenciamento de memória.
     * Requer solicitação ao sistema, controle de metadados, desalocação manual.
     *
     * @warning A stack tem tamanho limitado. Arrays muito grandes podem causar stack overflow.
     *
     * @attention Porém a Heap é indispensável para:
     * - Dados muito grandes (acima de dezenas de KB).
     * - Tamanhos dinâmicos (tempo de execução).
     * - Objetos que sobrevivem fora do escopo atual.
     */
    return 0;
}
