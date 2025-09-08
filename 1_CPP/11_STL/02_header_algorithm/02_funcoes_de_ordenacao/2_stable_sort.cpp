#include <iostream>
#include <vector>
#include <algorithm>

/**
 * std::stable_sort(): Ordena todos os elementos em uma faixa especificada enquanto
 * mantém a estabilidade — ou seja, preserva a ordem relativa dos elementos equivalentes.
 * Isso é particularmente útil quando você tem um conjunto de dados com elementos iguais
 * e deseja manter a ordem original entre eles.
 *
 * O tempo de execução do std::stable_sort é O(n log n), onde n é o número de elementos
 * no intervalo.
 */

/**
 * @brief Função que utiliza std::stable_sort com uma comparação personalizada
 * via lambda para ordenar o vetor em ordem decrescente.
 *
 * @param first_value Primeiro valor da estrutura
 * @param last_value Último valor da estrutura
 */
void stable_sort_with_lambda(int *first_value, int *last_value)
{
    // Ordena o vetor em ordem decrescente
    std::stable_sort(first_value, last_value, [](int a, int b)
    {
        return a > b; // Ordenação decrescente
    });

    // Exibindo o vetor ordenado
    std::cout << "Array ordenado com stable_sort (decrescente): ";
    for (int *ptr = first_value; ptr != last_value; ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    int arr[] = {10, 5, 2, 8, 6, 1, 9, 7, 3, 4};

    // Propriedades do array (tamanho, primeiro e último valor)
    std::size_t size = (sizeof(arr) / sizeof(arr[0]));
    int *first_value = arr;
    int *last_value = &arr[size]; // O último valor é "one-past-the-end"

    // Usando std::stable_sort para ordenar o vetor em ordem crescente
    std::cout << "Usando std::stable_sort (crescente): ";
    std::stable_sort(first_value, last_value);

    // Exibindo o vetor ordenado em ordem crescente
    for (std::size_t i{0}; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    // Chamando as funções para ordenar com stable_sort com lambda (ordem decrescente)
    stable_sort_with_lambda(first_value, last_value); // Ordenando o vetor com stable_sort
    return 0;
}
