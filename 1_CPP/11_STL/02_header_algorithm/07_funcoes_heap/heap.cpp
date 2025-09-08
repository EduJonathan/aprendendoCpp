#include <iostream>
#include <vector>
#include <algorithm>

/**
 * As funções std::push_heap, std::pop_heap e std::make_heap permitem a manipulação de heaps,
 * que são estruturas de dados úteis para implementar filas de prioridade.
 *
 * - std::make_heap() => Converte vetor em um max-heap.
 * - std::push_heap() => Insere um novo elemento mantendo a estrutura de heap.
 * - std::pop_heap() => Move o maior elemento para o fim (não o remove).
 * - std::sort_heap() => Ordena os elementos e desfaz a propriedade de heap.
 */

/**
 * @brief Cria um heap a partir de um vetor.
 *
 * Usa a função std::make_heap para converter o vetor em um heap (estrutura de dados).
 * O vetor resultante possui o maior elemento na posição inicial.
 *
 * @param valores Vetor de inteiros a ser transformado em heap.
 */
void criarHeap(std::vector<int> &valores)
{
    std::make_heap(valores.begin(), valores.end());
    std::cout << "Heap criado: ";

    for (int v : valores)
    {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

/**
 * @brief Adiciona um novo elemento ao heap e ajusta sua estrutura.
 *
 * O novo elemento é inserido no vetor e, em seguida, a função std::push_heap
 * é chamada para ajustar o heap e garantir que ele continue com a propriedade de heap
 * após a inserção.
 *
 * @param valores Vetor de inteiros representando o heap.
 * @param elemento Novo elemento a ser adicionado ao heap.
 */
void adicionarElemento(std::vector<int> &valores, int elemento)
{
    valores.push_back(elemento);
    std::push_heap(valores.begin(), valores.end());

    std::cout << "Após adicionar " << elemento << ": ";

    for (int v : valores)
    {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

/**
 * @brief Remove o maior elemento do heap.
 *
 * A função std::pop_heap move o maior elemento para o final do vetor. Em seguida,
 * ele é removido com a função pop_back().
 *
 * @param valores Vetor de inteiros representando o heap.
 */
void removerMaiorElemento(std::vector<int> &valores)
{
    std::pop_heap(valores.begin(), valores.end());
    valores.pop_back(); // remove o último, que era o maior

    std::cout << "Após remover o maior elemento: ";

    for (int v : valores)
    {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    std::cout << "CRIANDO HEAP\n";
    std::vector<int> heap = {3, 7, 1, 9, 5};

    std::cout << "===== MANIPULAÇÃO DE HEAP =====\n";
    criarHeap(heap);
    adicionarElemento(heap, 10);
    removerMaiorElemento(heap);

    std::cout << "\n===== ORDENANDO O HEAP =====\n";

    // Cópia para ordenar sem modificar o heap original
    std::vector<int> heapCrescente = heap;
    std::sort_heap(heapCrescente.begin(), heapCrescente.end());

    std::cout << "Heap ordenado (crescente): ";

    for (int v : heapCrescente)
    {
        std::cout << v << ' ';
    }
    std::cout << '\n';

    // Outra cópia para ordenação decrescente
    std::vector<int> heapDecrescente = heap;
    std::make_heap(heapDecrescente.begin(), heapDecrescente.end(), std::greater<int>());
    std::sort_heap(heapDecrescente.begin(), heapDecrescente.end(), std::greater<int>());

    std::cout << "Heap ordenado (decrescente): ";

    for (int v : heapDecrescente)
    {
        std::cout << v << ' ';
    }
    std::cout << '\n';

    return 0;
}
