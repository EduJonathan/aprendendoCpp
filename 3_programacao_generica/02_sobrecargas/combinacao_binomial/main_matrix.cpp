#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <new>
#include "class_matriz.tpp"

/**
 * Este código implementa uma classe de matriz genérica em C++ que suporta operações como
 * multiplicação e exponenciação de matrizes. A função `computarCombinacao` utiliza essa classe
 * para calcular o número de combinações (binomial) usando uma abordagem baseada em matrizes
 */

template <class T>
Matriz<T>::Matriz(int linhas, int colunas)
{
    this->linhas = linhas;
    this->colunas = colunas;
    dados = new T[linhas * colunas];
}

template <class T>
Matriz<T>::Matriz(const Matriz<T> &matriz)
{
    this->linhas = matriz.linhas;
    this->colunas = matriz.colunas;
    dados = new T[linhas * colunas];

    for (int i = 0; i < linhas * colunas; i++)
    {
        dados[i] = matriz.dados[i];
    }
}

template <class T>
const Matriz<T> &Matriz<T>::operator=(const Matriz<T> &matriz)
{
    if (&matriz != this) // Verifica autoatribuição
    {
        delete[] dados;
        this->linhas = matriz.linhas;
        this->colunas = matriz.colunas;
        dados = new T[linhas * colunas];

        for (int i = 0; i < linhas * colunas; i++)
        {
            dados[i] = matriz.dados[i];
        }
    }
    return *this;
}

template <class T>
const Matriz<T> Matriz<T>::operator*(const Matriz<T> &matriz)
{
    if (colunas != matriz.linhas)
        throw std::invalid_argument("Dimensões incompatíveis para multiplicação.");

    Matriz<T> m(linhas, matriz.colunas);

    for (int i = 0; i < linhas; ++i)
    {
        for (int j = 0; j < matriz.colunas; ++j)
        {
            m.dados[i * matriz.colunas + j] = 0;

            for (int k = 0; k < colunas; ++k)
            {
                m.dados[i * matriz.colunas + j] += dados[i * colunas + k] * matriz.dados[k * matriz.colunas + j];
            }
        }
    }
    return m;
}

template <class T>
const Matriz<T> Matriz<T>::operator^(int expoente)
{
    if (linhas != colunas)
        throw std::invalid_argument("A matriz deve ser quadrada para exponenciação.");

    Matriz<T> resultado(linhas, colunas);

    // Matriz identidade
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            resultado.dados[i * colunas + j] = (i == j ? 1 : 0);

    Matriz<T> base = *this;

    while (expoente > 0)
    {
        if (expoente % 2 == 1)
            resultado = resultado * base;

        base = base * base;
        expoente /= 2;
    }

    return resultado;
}

template <class T>
Matriz<T>::~Matriz()
{
    delete[] dados;
}

/**
 * @brief Computa o número de combinações (binomial) C(n, k) usando matrizes.
 *
 * A função utiliza uma matriz de transição baseada no triângulo de Pascal
 * e a exponenciação rápida de matrizes para calcular o resultado.
 *
 * @param n Número total de objetos
 * @param k Número de objetos a serem escolhidos
 * @return Número de combinações C(n, k)
 */
long long computarCombinacao(int n, int k)
{
    Matriz<long long> m(k + 1, k + 1); // Matriz de transição (k+1)x(k+1)

    // Zerar a matriz
    for (int i = 0; i < (k + 1) * (k + 1); ++i)
        m.dados[i] = 0;

    // Matriz de transição baseada no triângulo de Pascal
    m.dados[0] = 1;
    for (int i = 1; i < k + 1; ++i)
    {
        m.dados[i * (k + 1) + i - 1] = 1;
        m.dados[i * (k + 1) + i] = 1;
    }

    return (m ^ n).dados[k * (k + 1)];
}

int main(int argc, char **argv)
{
    int n = 0, // número de objetos
        r = 0; // número de requisitos

    while (true)
    {
        std::cout << "Digite a quantidade de objetos (0 para sair): ";
        std::cin >> n;

        if (n == 0)
            break;

        std::cout << "Digite a quantidade de requisitos: ";
        std::cin >> r;

        std::cout << "Numero de Combinações: " << computarCombinacao(n, std::min(r, n - r)) << "\n\n";
    }
    return 0;
}
