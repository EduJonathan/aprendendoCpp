#include <iostream>
#include <algorithm>
#include "lis.hpp"

/**
 * @brief Construtor do nó.
 *
 * @param x Valor a ser armazenado no nó.
 */
LargestIndependentSet::Node::Node(int x) : dado(x), liss(0), left(nullptr), right(nullptr) {}

/**
 * @brief Construtor da classe LargestIndependentSet.
 */
LargestIndependentSet::LargestIndependentSet() : root(nullptr) {}

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
void LargestIndependentSet::construirExemplo(void)
{
    root               = std::make_unique<Node>(10);
    root->left         = std::make_unique<Node>(20);
    root->right        = std::make_unique<Node>(30);
    root->left->left   = std::make_unique<Node>(40);
    root->right->left  = std::make_unique<Node>(50);
    root->right->right = std::make_unique<Node>(60);
}

/**
 * @brief Calcula o tamanho do maior conjunto independente da árvore.
 *
 * @return Um inteiro representando o tamanho do conjunto.
 *
 * @note Se você estiver estranhando o retorno de uma função que não foi
 * declarado antes e sim logo após, tenha calma, é normal este tipo de caso em POO,
 * mas não em programação estruturada funcional.
 */
int LargestIndependentSet::calcularLIS(void)
{
    return Liss(root.get());
}

/**
 * @brief Função auxiliar recursiva para calcular o maior conjunto independente (LIS).
 *
 * A função usa memoização com o campo `liss` em cada nó para evitar recomputações.
 *
 * @param node Ponteiro para o nó atual.
 * @return Tamanho do maior conjunto independente na subárvore com raiz em `node`.
 */
int LargestIndependentSet::Liss(Node *node)
{
    if (!node)
        return 0;

    // Retorna valor memoizado
    if (node->liss != 0)
        return node->liss;

    // Nó folha
    if (!node->left && !node->right)
        return (node->liss = 1);

    // Excluindo o nó atual
    int excluindo = Liss(node->left.get()) + Liss(node->right.get());

    // Incluindo o nó atual
    int incluindo = 1;

    if (node->left)
    {
        incluindo += Liss(node->left->left.get());
        incluindo += Liss(node->left->right.get());
    }

    if (node->right)
    {
        incluindo += Liss(node->right->left.get());
        incluindo += Liss(node->right->right.get());
    }

    node->liss = std::max(incluindo, excluindo);
    return node->liss;
}

int main(int argc, char **argv)
{
    LargestIndependentSet lis;
    lis.construirExemplo();

    std::cout << "Tamanho do maior conjunto independente: " << lis.calcularLIS() << '\n';

    // Não se preocupar com delete, o unique_ptr irá fazer automaticamente.
    return 0;
}
