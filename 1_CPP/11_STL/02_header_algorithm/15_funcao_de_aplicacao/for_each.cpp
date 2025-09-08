#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::for_each(): é uma função que permite aplicar uma função a cada elemento de um intervalo.
 * - std::for_each_n(): é uma função similar, mas aplica a função a um número específico de elementos.
 */

/**
 * @brief Função para imprimir um valor.
 *
 * @param x Valor a ser impresso.
 */
void print(int x) { std::cout << x << ' '; }

/**
 * @brief Função para imprimir o vetor utilizando std::for_each com uma expressão lambda.
 *
 * @param v Vetor de inteiros a ser impresso.
 */
void imprimirComForEach(const std::vector<int> &v)
{
    std::cout << "Usando std::for_each: ";

    std::for_each(v.begin(), v.end(), [](int x)
    {
        std::cout << x << ' '; 
    });
    std::cout << '\n';
}

/**
 * @brief Função para imprimir o vetor utilizando std::for_each_n com uma expressão lambda.
 *
 * @param v Vetor de inteiros a ser impresso.
 */
void imprimirComForEachN(const std::vector<int> &v)
{
    std::cout << "Usando std::for_each_n: ";
    
    std::for_each_n(v.begin(), v.size(), [](int x)
    {
        std::cout << x << ' '; 
    });
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    /** Vetor de inteiros */
    std::vector<int> v = {1, 2, 3, 4, 5};

    /** Imprime o vetor original */
    std::cout << "Vetor original: ";

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';

    /** Imprime o vetor de inteiros utilizando std::for_each com função regular */
    std::cout << "Usando std::for_each sem a expressão lambda: ";
    std::for_each(v.begin(), v.end(), print);
    std::cout << '\n';

    /** Imprime o vetor de inteiros utilizando std::for_each_n com função regular */
    std::cout << "Usando std::for_each_n sem a expressão lambda: ";
    std::for_each_n(v.begin(), v.size(), print);
    std::cout << '\n';

    // Chama as funções para imprimir os vetores
    imprimirComForEach(v);
    imprimirComForEachN(v);

    return 0;
}
