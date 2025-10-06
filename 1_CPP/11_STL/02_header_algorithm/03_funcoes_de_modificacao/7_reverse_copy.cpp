#include <iostream>
#include <array>
#include <algorithm>

/**
 * - std::reverse_copy(begin, end, dest)
 *   → Copia os elementos invertidos do intervalo (begin, end) para `dest`.
 */

/**
 * @brief Cria uma cópia invertida de um array estático de inteiros.
 *
 * Esta função demonstra o uso de std::reverse_copy com arrays estilo C.
 * Ela copia os elementos em ordem reversa para outro array.
 *
 * @param src Ponteiro para o início do array de origem.
 * @param dst Ponteiro para o início do array de destino.
 * @param size Número total de elementos a serem copiados.
 *
 * @note A função imprime o conteúdo do array destino após a cópia invertida.
 */
void copiar_array_invertido(int src[], int dst[], int size)
{
    std::reverse_copy(src, src + size, dst);

    std::cout << "Cópia invertida do array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << dst[i] << ' ';
    }
    std::cout << '\n';
}

/**
 * @brief Cria uma cópia invertida de um std::array utilizando reverse_copy.
 *
 * Esta função usa std::reverse_copy para inverter um std::array em outro.
 *
 * @param src std::array de origem.
 * @param dst std::array de destino (por referência), onde a cópia invertida será armazenada.
 */
void copiar_std_array_invertido(const std::array<int, 6> &src, std::array<int, 6> &dst)
{
    std::reverse_copy(src.begin(), src.end(), dst.begin());

    std::cout << "std::array invertido com reverse_copy: ";

    std::for_each(dst.begin(), dst.end(), [](int val)
    {
        std::cout << val << ' ';
    });
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    // Exemplo com array estático
    int origem[] = {1, 2, 3, 4, 5, 6};
    int destino[6] = {0};
    int size = sizeof(origem) / sizeof(origem[0]);

    copiar_array_invertido(origem, destino, size);

    // Exemplo com std::array
    std::array<int, 6> origem_std{10, 20, 30, 40, 50, 60};
    std::array<int, 6> destino_std;

    copiar_std_array_invertido(origem_std, destino_std);

    return 0;
}
