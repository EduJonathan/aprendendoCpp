#include <iostream>
#include <vector>
#include <algorithm>

/**
 * std::binary_search(): Verifica se um determinado valor está presente em um
 * intervalo ordenado. O intervalo deve estar previamente ordenado de acordo como
 * mesmo critério de comparação utilizado na busca; caso contrário, o comportamento
 * é indefinido.
 *
 * Retorna um valor booleano (`true` ou `false`), indicando se o valor foi encontrado.
 * Não retorna a posição do elemento nem modifica o conteúdo do intervalo.
 */

/**
 * @brief Função para realizar a busca binária em um vetor.
 *
 * A função utiliza `std::binary_search()` com diferentes abordagens de iteradores:
 * 1. Realizando a busca de forma contínua, usando os iteradores `begin()` e `end()`.
 * 2. Realizando a busca com iteradores reversos `rbegin()` e `rend()`.
 *
 * @param vec Vetor de caracteres onde será realizada a busca binária.
 */
void encontre_valor(std::vector<char> &vec)
{
    // Lambda para realizar a busca binária
    auto busca_binaria = [](auto begin, auto end, char valor)
    {
        return std::binary_search(begin, end, valor);
    };

    /*
     * Primeira busca realizada de forma contínua através dos iteradores begin() e end()
     * em um vetor que está ao contrário
     */
    std::cout << "1º busca: " << busca_binaria(vec.begin(), vec.end(), 'A') << '\n';

    /*
     * Segunda busca realizada de forma reversa dos iteradores rbegin() e rend()
     * em um vetor que está ao contrário
     */
    std::cout << "2º busca: " << busca_binaria(vec.rbegin(), vec.rend(), 'A') << '\n';
}

int main(int argc, char **argv)
{
    // Array de inteiros ordenado
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /* Propriedades do array (tamanho, primeiro e último valor)*/
    std::size_t size = (sizeof(arr) / sizeof(arr[0]));
    int *first_value = arr;
    int *last_value = &arr[size]; // Correção: O último valor é one-past-the-end.

    /* Realizando a busca binária */
    std::cout << "O valor foi encontrado: " << std::binary_search(first_value, last_value, 10) << '\n';
    std::cout << "O valor foi encontrado: " << std::binary_search(first_value, last_value, 11) << '\n';

    std::cout << "------------------------------" << '\n';

    // Vetor de caracteres (não ordenado)
    std::vector<char> vetor = {'F', 'E', 'D', 'C', 'B', 'A'};
    encontre_valor(vetor);

    return 0;
}
