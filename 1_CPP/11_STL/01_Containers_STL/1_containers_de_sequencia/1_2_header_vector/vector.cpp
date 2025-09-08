#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

/**
 * std::vector<T> é um container de sequência dinâmico que permite o redimensionamento
 * automático da sua capacidade conforme necessário. Ele pode armazenar qualquer
 * tipo de dado, incluindo outros containers como vetores, listas, strings, etc.
 */

/**
 * @brief Particiona o vetor em torno de um pivô.
 *
 * Reorganiza os elementos para que os menores que o pivô fiquem à esquerda
 * e os maiores à direita, retornando a posição final do pivô.
 *
 * @param arr Vetor a ser particionado.
 * @param low Índice inicial do intervalo.
 * @param high Índice final do intervalo.
 * @return Índice do pivô após a partição.
 */
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

/**
 * @brief Encontra o k-ésimo menor elemento do vetor usando Quickselect.
 *
 * Utiliza o algoritmo Quickselect (baseado no Quicksort) para selecionar o
 * k-ésimo menor elemento (1-based) em tempo médio linear.
 *
 * @param arr Vetor de inteiros.
 * @param low Índice inicial do intervalo.
 * @param high Índice final do intervalo.
 * @param k Posição desejada (1-based).
 * @return Valor do k-ésimo menor elemento ou -1 se inválido.
 */
int quickSelection(std::vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high);

        if (pi == k - 1)
        {
            return arr[pi];
        }
        else if (pi > k - 1)
        {
            return quickSelection(arr, low, pi - 1, k);
        }
        else
        {
            return quickSelection(arr, pi + 1, high, k);
        }
    }

    return -1; // k fora dos limites
}

/**
 * @brief Retorna o número mais frequente em um vetor e sua frequência.
 *
 * Utiliza um std::map para contar ocorrências e identifica o valor com maior frequência.
 *
 * @param numeros Vetor de inteiros.
 * @return Vetor com dois elementos: [número mais frequente, sua frequência].
 */
std::vector<int> frequenciaDeNumeros(const std::vector<int> &numeros)
{
    std::map<int, int> frequencia;

    for (int num : numeros)
        ++frequencia[num];

    int numeroMaisFrequente = 0;
    int maiorFrequencia = 0;

    for (const auto &[numero, freq] : frequencia)
    {
        if (freq > maiorFrequencia)
        {
            maiorFrequencia = freq;
            numeroMaisFrequente = numero;
        }
    }
    
    return {numeroMaisFrequente, maiorFrequencia};
}

int main(int argc, char **argv)
{
    std::vector<int> arr = {10, 4, 5, 8, 6, 11, 26};
    int key = 3;

    int result = quickSelection(arr, 0, arr.size() - 1, key);
    std::cout << "O " << key << "º menor elemento é: " << result << '\n';

    std::cout << "--------------------------------------\n";

    std::vector<int> numeros = {1, 3, 3, 2, 4, 3, 5, 2, 1, 3};
    auto resultado = frequenciaDeNumeros(numeros);

    std::cout << "Número mais frequente é: " << resultado[0]
              << " com frequência de " << resultado[1] << " vezes.\n";

    return 0;
}
