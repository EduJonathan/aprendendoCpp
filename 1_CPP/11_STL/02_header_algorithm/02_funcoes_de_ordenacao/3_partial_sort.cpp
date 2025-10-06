#include <iostream>
#include <algorithm>

/**
 * std::partial_sort(): Reorganiza os elementos de um intervalo de forma que os primeiros k
 * elementos sejam os menores (ou maiores, dependendo do critério de comparação) e estejam
 * em ordem ordenada. Os demais elementos não são necessariamente ordenados.
 *
 * É útil quando apenas os primeiros k elementos ordenados são necessários, sem a sobrecarga
 * de ordenar toda a sequência.
 *
 * Complexidade: O(n log k), onde n é o número total de elementos no intervalo e
 * k é o número de elementos a serem ordenados.
 */

/**
 * @brief Função para ordenar parcialmente o vetor de caracteres.
 *
 * A função usa std::partial_sort para ordenar os primeiros `k` elementos
 * do vetor em ordem crescente, utilizando uma lambda. O intervalo do vetor
 * que não é ordenado permanece na ordem original.
 *
 * @param first_value Ponteiro para o início do vetor.
 * @param last_value Ponteiro para o final do vetor.
 * @param k Número de elementos a ordenar parcialmente.
 */
void partial_sort_with_lambda(char *first_value, char *last_value, std::size_t k)
{
    // Se k for maior que o tamanho do vetor, deve ser ajustado
    k = std::min(k, static_cast<std::size_t>(last_value - first_value));

    // Ordena todos os elementos (equivalente a usar std::sort)
    std::partial_sort(first_value, last_value, last_value, [](char a, char b)
    {
        return a < b; // Ordenação crescente
    });

    // Exibindo o vetor ordenado
    std::cout << "Array ordenado com partial_sort (crescente): ";
    for (char *ptr = first_value; ptr != last_value; ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    char arr[] = {'z', 'b', 'a', 'h', 'g', 'y', 'c', 'x', 'd', 'f'};

    // Propriedades do array (tamanho, primeiro e último valor)
    std::size_t size = (sizeof(arr) / sizeof(arr[0]));
    char *first_value = arr;
    char *last_value = &arr[size]; // O último valor é "one-past-the-end"

    // Usando std::partial_sort para ordenar parcialmente (ordem decrescente)
    std::cout << "Usando std::partial_sort (decrescente, primeiros 5 elementos): ";
    std::partial_sort(first_value, first_value + 5, last_value, std::greater<char>());

    // Exibindo o vetor parcialmente ordenado
    for (std::size_t i = 0ull; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    // Chamando a função para ordenar todos os elementos com std::partial_sort
    partial_sort_with_lambda(first_value, last_value, size);
    return 0;
}
