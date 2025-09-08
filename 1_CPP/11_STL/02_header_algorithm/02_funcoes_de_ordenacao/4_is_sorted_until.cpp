#include <iostream>
#include <array>
#include <algorithm>

/**
 * Ele percorre o array até encontrar um par de elementos que viola a ordem definida
 * pelo comparador. Retorna um iterador para o primeiro elemento fora de ordem.
 */

/**
 * @brief Verifica até que ponto um array está ordenado, utilizando uma função lambda para comparação.
 *
 * Esta função demonstra o uso de std::is_sorted_until com um array estático de inteiros.
 * Ela determina a partir de qual posição o array deixa de estar ordenado de forma crescente.
 *
 * @param arr Ponteiro para o início do array de inteiros.
 * @param size Número total de elementos no array.
 *
 * @note A função imprime o índice onde a ordenação se quebra, ou informa que o array está totalmente ordenado.
 */
void verificar_ordenacao_com_lambda(int arr[], int size)
{
    // Lambda para comparação crescente (padrão)
    auto it = std::is_sorted_until(arr, arr + size, [](int a, int b)
    {
        return a <= b; // permite elementos iguais
    });

    if (it == arr + size)
    {
        std::cout << "Array completamente ordenado.\n";
    }
    else
    {
        std::cout << "Ordenação quebra no índice " << (it - arr)
                  << " (valor: " << *it << ")\n";
    }
}

int main(int argc, char **argv)
{
    // Exemplo com std::array
    std::array<int, 10> arr{1, 2, 3, 4, 5, 1, 7, 9, 9, 1};

    auto iterator1 = std::is_sorted_until(arr.begin(), arr.end());
    auto iterator2 = std::is_sorted_until(arr.begin() + 4, arr.end());

    auto diff1 = std::distance(arr.begin(), iterator1);
    auto diff2 = std::distance(arr.begin() + 4, iterator2);

    std::cout << "diff1 (índice onde quebra a ordenação completa): " << diff1 << '\n';
    std::cout << "diff2 (índice relativo a partir de arr[4]): " << diff2 << '\n';

    int array[] = {1, 2, 3, 5, 4, 6}; // quebra na posição 4
    int size = sizeof(array) / sizeof(array[0]);

    verificar_ordenacao_com_lambda(array, size);

    return 0;
}
