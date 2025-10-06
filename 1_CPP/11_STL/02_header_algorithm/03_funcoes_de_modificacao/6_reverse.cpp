#include <iostream>
#include <array>
#include <algorithm>

/**
 * - std::reverse(begin, end)
 *   → Inverte a ordem dos elementos no intervalo (begin, end).
 */

/**
 * @brief Inverte os elementos de um array estático de inteiros.
 *
 * Esta função demonstra o uso de std::reverse com arrays estilo C,
 * utilizando ponteiros para definir o intervalo de inversão.
 *
 * @param arr Ponteiro para o início do array.
 * @param size Número total de elementos no array.
 *
 * @note A função modifica o array original in-place e imprime os elementos após a inversão.
 */
void inverter_array_estatico(int arr[], int size)
{
    std::reverse(arr, arr + size);

    std::cout << "Array invertido: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

/**
 * @brief Inverte os elementos de um std::array usando lambda para exibir os valores.
 *
 * Esta função aplica std::reverse a um std::array e demonstra que ele pode ser usado
 * com iteradores de containers padrão.
 *
 * @param arr Referência para o std::array a ser invertido.
 */
void inverter_std_array(std::array<int, 6> &arr)
{
    std::reverse(arr.begin(), arr.end());

    std::cout << "std::array invertido (com lambda para exibição): ";
    std::for_each(arr.begin(), arr.end(), [](int val)
    {
        std::cout << val << ' ';
    });
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    // Exemplo com array estático
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    inverter_array_estatico(array, size);

    // Exemplo com std::array
    std::array<int, 6> arr_std{10, 20, 30, 40, 50, 60};
    inverter_std_array(arr_std);

    return 0;
}
