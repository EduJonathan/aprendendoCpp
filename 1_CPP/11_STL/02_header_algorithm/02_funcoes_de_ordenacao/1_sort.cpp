#include <iostream>
#include <vector>
#include <algorithm>

// std::sort(): Função que deixa em ordem os elementos de um container.

/**
 * @brief Ordena o vetor de inteiros de forma decrescente utilizando a função std::sort com 
 * uma função lambda.
 *
 * A função utiliza a função lambda para definir a ordem decrescente dos elementos do vetor.
 * Ela modifica o vetor original passado por referência.
 *
 * @param v O vetor de inteiros que será ordenado.
 */
void ordenarDecrescente(std::vector<int> &v)
{
    std::sort(v.begin(), v.end(), [](int x, int y)
    {
        return x > y; // Ordenação decrescente
    });
}

int main(int argc, char **argv)
{
    /** Vetor de inteiros */
    std::vector<int> v = {5, 7, 3, 2, 1, 8, 6, 10, 11};

    /** Imprime o vetor original */
    std::cout << "Vetor original: ";
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << ' ';
    }

    // Ordena o vetor de forma crescente
    std::sort(v.begin(), v.end());

    std::cout << "\nVetor ordenado (ascendente): ";
    for (int ind : v)
    {
        std::cout << ind << ' ';
    }

    // Chama a função para ordenar de forma decrescente
    ordenarDecrescente(v);

    // Exibe o vetor ordenado de forma decrescente
    std::cout << "\nVetor ordenado (decrescente) com lambda: ";
    for (int ind : v)
    {
        std::cout << ind << ' ';
    }

    return 0;
}
