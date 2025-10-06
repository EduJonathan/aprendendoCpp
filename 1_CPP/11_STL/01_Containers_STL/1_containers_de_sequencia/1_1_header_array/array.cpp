#include <iostream>
#include <array>

/**
 * std::array<T, N> é um container que representa um vetor estático de tamanho fixo.
 * Ele armazena N elementos do tipo T, oferecendo métodos úteis e segurança
 * em comparação aos arrays C tradicionais.
 */

/**
 * @brief Algoritmo de Kadane para encontrar a soma máxima de uma subarray contígua.
 *
 * Utiliza programação dinâmica para identificar a maior soma possível de uma subarray contínua.
 * Mantém duas variáveis: uma para o valor acumulado atual e outra para o maior valor encontrado.
 *
 * @param arr Array de inteiros.
 * @return Maior soma de uma subarray contígua.
 */
int kadane(const std::array<int, 10> &arr)
{
    int max_so_far = arr[0];      // Maior soma encontrada até o momento
    int max_ending_here = arr[0]; // Soma atual da subarray

    for (std::size_t i{1}; i < arr.size(); ++i)
    {
        max_ending_here = std::max(arr[i], max_ending_here + arr[i]);
        max_so_far = std::max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

/**
 * @brief Função para calcular a soma dos elementos do array de forma simétrica,
 * exibindo cada soma e retornando a soma total.
 *
 * A função soma o primeiro com o último, o segundo com o penúltimo e assim por diante.
 * A cada soma, o valor é exibido no console. No final, retorna a soma total em um std::array.
 *
 * @param arr O array de inteiros.
 * @return Um std::array contendo a soma total dos pares simétricos.
 */
std::array<int, 1> somaDeConjuntosSimetricos(const std::array<int, 10> &arr)
{
    // Inicializa a soma total
    int somaTotal = 0;

    // Soma os pares simétricos e exibe as somas
    for (std::size_t i{0}; i < arr.size() / 2; ++i)
    {
        // Soma os elementos
        int soma = arr[i] + arr[arr.size() - 1 - i];

        // Adiciona a soma ao total
        somaTotal += soma;

        // Exibe cada soma no formato solicitado
        std::cout << "Soma de arr[" << i << "] + arr[" << (arr.size() - 1 - i)
                  << "] (" << arr[i] << " + " << arr[arr.size() - 1 - i]
                  << ") = " << soma << '\n';
    }

    // Exibe a soma total
    std::cout << "Soma total de todos os pares simétricos: " << somaTotal << '\n';

    // Retorna a soma total dentro de um std::array
    return {{somaTotal}};
}

int main(int argc, char **argv)
{
    // Exemplo 1: Algoritmo de Kadane
    const std::array<int, 10> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4, 6};
    int resultado = kadane(arr);
    std::cout << "A soma máxima da subarray contígua é: " << resultado << '\n';

    std::cout << "\n----------------------------------\n";

    // Exemplo 2: Soma de conjuntos simétricos
    std::array<int, 10> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Chama a função e obtém a soma total dos pares simétricos
    std::array<int, 1> result = somaDeConjuntosSimetricos(array);

    // Exibe a soma total
    std::cout << "A soma total dos conjuntos simétricos é: " << result[0] << '\n';
    return 0;
}
