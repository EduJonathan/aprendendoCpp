#ifndef CLASS_MATRIZ_HPP
#define CLASS_MATRIZ_HPP

#include <iostream>

/**
 * @brief Classe genérica para manipulação de matrizes.
 *
 * Esta classe permite a criação e manipulação de matrizes de qualquer tipo T.
 * Suporta operações como multiplicação e exponenciação de matrizes.
 *
 * @tparam T Tipo de dado armazenado na matriz (ex: int, float, double, long long, etc.)
 */
template <class T>
class Matriz
{
public:
    int linhas;  ///< Número de linhas da matriz
    int colunas; ///< Número de colunas da matriz
    T *dados;    ///< Ponteiro para os dados da matriz armazenados em ordem linear (row-major)

    /**
     * @brief Construtor da matriz.
     *
     * @param linhas Número de linhas
     * @param colunas Número de colunas
     */
    Matriz(int linhas, int colunas);

    /**
     * @brief Construtor de cópia.
     *
     * @param matriz Objeto matriz a ser copiado
     */
    Matriz(const Matriz<T> &matriz);

    /**
     * @brief Operador de atribuição.
     *
     * @param matriz Objeto matriz a ser atribuído
     * @return Referência para o objeto atual
     */
    const Matriz<T> &operator=(const Matriz<T> &matriz);

    /**
     * @brief Operador de multiplicação de matrizes.
     *
     * @param matriz A matriz com a qual multiplicar
     * @return Nova matriz resultado da multiplicação
     * @throws std::invalid_argument se as dimensões forem incompatíveis
     */
    const Matriz<T> operator*(const Matriz<T> &matriz);

    /**
     * @brief Operador de exponenciação de matriz (por expoente inteiro).
     *
     * Utiliza exponenciação rápida (exponenciação binária).
     *
     * @param expoente Expoente inteiro não-negativo
     * @return Matriz elevada à potência especificada
     * @throws std::invalid_argument se a matriz não for quadrada
     */
    const Matriz<T> operator^(int expoente);

    /**
     * @brief Destrutor da matriz.
     *
     * Libera a memória alocada dinamicamente.
     */
    ~Matriz();
};

#endif // CLASS_MATRIZ_HPP
