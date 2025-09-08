#ifndef CLASS_LIS_HPP
#define CLASS_LIS_HPP

#include <iostream>
#include <memory>

/**
 * @brief Implementa o algoritmo para encontrar o maior conjunto independente
 * em uma árvore binária.
 *
 * Um conjunto independente é um subconjunto de nós onde nenhum par está diretamente
 * conectado. A classe usa programação dinâmica com memoização para otimizar o cálculo.
 */
class LargestIndependentSet
{
private:
    /**
     * @brief Representa um nó da árvore binária.
     */
    struct Node
    {
        int dado; ///< Valor armazenado no nó.
        int liss; ///< Valor memoizado do maior conjunto independente passando por este nó.

        std::unique_ptr<Node> left;  ///< Ponteiro para o filho à esquerda.
        std::unique_ptr<Node> right; ///< Ponteiro para o filho à direita.

        /**
         * @brief Construtor do nó.
         *
         * @param x Valor a ser armazenado no nó.
         */
        Node(int x);
    };

    std::unique_ptr<Node> root; ///< Raiz da árvore.

    /**
     * @brief Função auxiliar recursiva para calcular o maior conjunto independente (LIS).
     *
     * A função usa memoização com o campo `liss` em cada nó para evitar recomputações.
     *
     * @param node Ponteiro para o nó atual.
     * @return Tamanho do maior conjunto independente na subárvore com raiz em `node`.
     */
    int Liss(Node *node);

public:
    /**
     * @brief Construtor da classe LargestIndependentSet.
     */
    LargestIndependentSet();

    /**
     * @brief Constrói uma árvore binária de exemplo com estrutura fixa.
     *
     * Estrutura usada:
     *
     *        10
     *       /  \
     *     20    30
     *    /     /  \
     *  40     50   60
     */
    void construirExemplo(void);

    /**
     * @brief Calcula o tamanho do maior conjunto independente da árvore.
     *
     * @return Um inteiro representando o tamanho do conjunto.
     *
     * @note Se você estiver estranhando o retorno de uma função que não foi
     * declarado antes e sim logo após, tenha calma, na linguagem C++ é normal
     * este tipo de caso.
     */
    int calcularLIS(void);
};

#endif // CLASS_LIS_HPP
