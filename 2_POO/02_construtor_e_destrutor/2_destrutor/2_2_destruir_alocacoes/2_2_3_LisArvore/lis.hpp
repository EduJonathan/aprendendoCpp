#ifndef CLASS_LIS_HPP
#define CLASS_LIS_HPP

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
        Node(int x);
    };

    std::unique_ptr<Node> root; ///< Raiz da árvore.
    int Liss(Node *node);

public:
    LargestIndependentSet();
    void construirExemplo(void);
    int calcularLIS(void);
};

#endif // CLASS_LIS_HPP
