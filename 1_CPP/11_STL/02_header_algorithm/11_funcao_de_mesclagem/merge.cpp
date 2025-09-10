#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// std::merge(): Combina dois intervalos ordenados em um terceiro intervalo também ordenado.

/**
 * @brief Ordena um vetor de strings usando o algoritmo Merge Sort com std::merge.
 *
 * @param v Referência ao vetor de strings a ser ordenado.
 */
void ordenarComMergeSort(std::vector<std::string> &v)
{
    if (v.size() <= 1)
        return;

    // Divide o vetor em duas partes
    std::vector<std::string> esquerda(v.begin(), v.begin() + v.size() / 2);
    std::vector<std::string> direita(v.begin() + v.size() / 2, v.end());

    // Ordena recursivamente cada metade
    ordenarComMergeSort(esquerda);
    ordenarComMergeSort(direita);

    // Mescla as metades ordenadas
    std::vector<std::string> resultadoMesclado(v.size());

    std::merge(esquerda.begin(), esquerda.end(), direita.begin(), direita.end(),
               resultadoMesclado.begin(), [](const std::string &a, const std::string &b)
               {
                   return a < b; // Comparação para ordem crescente
               });

    // Copia de volta para o vetor original
    std::copy(resultadoMesclado.begin(), resultadoMesclado.end(), v.begin());
}

int main(int argc, char **argv)
{
    // Exemplo com dois vetores ordenados de inteiros
    std::vector<int> v1 = {1, 3, 5, 7};
    std::vector<int> v2 = {2, 4, 6, 8};

    // Vetor resultado da mesclagem
    std::vector<int> resultado(v1.size() + v2.size());

    // Mescla os dois vetores ordenados em um só
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), resultado.begin());

    std::cout << "Vetor mesclado (int): ";

    for (int val : resultado)
    {
        std::cout << val << ' ';
    }

    std::cout << "\n===================================\n";

    // Vetor desordenado de strings
    std::vector<std::string> frutas = {"banana", "laranja", "cereja", "acerola", "kiwi", "pera"};

    std::cout << "Vetor original (strings): ";

    for (const auto &fruta : frutas)
    {
        std::cout << fruta << ' ';
    }
    std::cout << '\n';

    // Ordena usando merge sort
    ordenarComMergeSort(frutas);

    std::cout << "Vetor ordenado (strings): ";

    for (const auto &fruta : frutas)
    {
        std::cout << fruta << ' ';
    }
    std::cout << '\n';

    return 0;
}
