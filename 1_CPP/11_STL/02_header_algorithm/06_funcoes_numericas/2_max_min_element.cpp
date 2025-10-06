#include <iostream>
#include <array>
#include <algorithm>

/**
 * - std::max_element(begin, end)
 *   → Retorna um iterador para o maior elemento no intervalo (begin, end).
 *
 * - std::min_element(begin, end)
 *   → Retorna um iterador para o menor elemento no intervalo (begin, end).
 */

/**
 * @brief Encontra o menor e o maior valor em um array estático de inteiros,
 *        utilizando funções lambda para comparação.
 *
 * Esta função demonstra como usar std::min_element e std::max_element
 * com expressões lambda em arrays estáticos estilo C.
 *
 * @param arr Ponteiro para o início do array de inteiros.
 * @param size Tamanho do array (número de elementos).
 *
 * @note A função imprime o valor e o índice do menor e do maior elemento.
 */
void min_max_array_com_lambda(int arr[], std::size_t size)
{
    // Lambda para comparação "normal" (padrão do <)
    auto menor = std::min_element(arr, arr + size, [](int a, int b)
    {
        return a < b;
    });

    // Lambda para comparação "normal" (padrão do <), mas usado para encontrar o maior
    auto maior = std::max_element(arr, arr + size, [](int a, int b)
    {
        return a < b;  // equivalente ao padrão, mas escrito explicitamente
    });

    std::cout << "Mínimo (com lambda): " << *menor << " no índice " << (menor - arr) << '\n';
    std::cout << "Máximo (com lambda): " << *maior << " no índice " << (maior - arr) << '\n';
}

int main(int argc, char **argv)
{
    std::array<double, 6> array{3, 1, 2, 5, 6, 0};

    auto iterador_max = std::max_element(array.begin(), array.end());
    std::cout << "retorna? " << *iterador_max << '\n';

    auto iterador_min = std::min_element(array.begin(), array.end());
    std::cout << "retorna? " << *iterador_min << '\n';

    int arr[] = {3, 1, 2, 5, 6, 0};
    std::size_t size = sizeof(array) / sizeof(array[0]);

    min_max_array_com_lambda(arr, size);
    return 0;
}
