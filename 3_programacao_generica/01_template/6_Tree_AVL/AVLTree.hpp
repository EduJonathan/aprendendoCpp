#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>

template <class Comparable>
class AVLTree;

/**
 * @class AVLNode
 *
 * @brief Classe que representa um nó em uma árvore AVL.
 *
 * Esta classe é utilizada internamente pela classe AVLTree para armazenar
 * os elementos da árvore, bem como os ponteiros para os filhos esquerdo
 * e direito e a altura do nó.
 *
 * @tparam Comparable Tipo dos elementos armazenados na árvore.
 */
template <class Comparable>
class AVLNode
{
public:
    Comparable element; // Elemento armazenado no nó.
    AVLNode *left;      // Ponteiro para o filho esquerdo.
    AVLNode *right;     // Ponteiro para o filho direito.
    int height;         // Altura do nó na árvore.

    /**
     * @brief Construtor do nó AVL.
     *
     * @param theElement Elemento a ser armazenado no nó.
     * @param lt Ponteiro para o filho esquerdo (padrão: nullptr).
     * @param rt Ponteiro para o filho direito (padrão: nullptr).
     * @param h Altura do nó (padrão: 0).
     */
    AVLNode(const Comparable &theElement, AVLNode *lt = nullptr, AVLNode *rt = nullptr, int h = 0)
        : element{theElement}, left{lt}, right{rt}, height{h} {}

    // Declaração de amizade para permitir que AVLTree acesse membros privados de AVLNode.
    friend class AVLTree<Comparable>;
};

/**
 * @class AVLTree
 *
 * @brief Classe que representa uma árvore AVL (Adelson-Velsky e Landis).
 *
 * Esta classe implementa uma árvore binária de busca auto-balanceada,
 * onde a diferença de altura entre as subárvores esquerda e direita
 * de qualquer nó é no máximo 1. A árvore suporta operações de inserção,
 * remoção, busca e impressão dos elementos.
 *
 * @tparam Comparable Tipo dos elementos armazenados na árvore.
 */
template <class Comparable>
class AVLTree
{
public:
    /**
     * @brief Construtor padrão da árvore AVL.
     *
     * @param notFound Valor retornado quando um elemento não é encontrado na árvore.
     */
    explicit AVLTree(const Comparable &notFound);

    /**
     * @brief Construtor de cópia da árvore AVL.
     *
     * @param rhs Referência para a árvore AVL à direita da atribuição.
     */
    AVLTree(const AVLTree &rhs);

    // Destrutor da árvore AVL.
    ~AVLTree();

    // Busca o elemento mínimo na árvore AVL.
    const Comparable &findMin() const;

    // Busca o elemento máximo na árvore AVL.
    const Comparable &findMax() const;

    // Busca um elemento na árvore AVL.
    const Comparable &find(const Comparable &x) const;

    // Verifica se a árvore AVL está vazia.
    bool isEmpty() const;

    // Imprime os elementos da árvore AVL em ordem crescente.
    void printTree() const;

    // Remove todos os elementos da árvore AVL.
    void makeEmpty();

    /**
     * @brief Insere um elemento na árvore AVL.
     *
     * @param x Elemento a ser inserido na árvore.
     */
    void insert(const Comparable &x);

    /**
     * @brief Remove um elemento da árvore AVL.
     *
     * @param x Elemento a ser removido da árvore.
     */
    void remove(const Comparable &x);

    /**
     * @brief Sobrecarga do operador de atribuição para a árvore AVL.
     *
     * @param rhs Referência para a árvore AVL à direita da atribuição.
     * @return Referência para a árvore AVL resultante da atribuição.
     */
    const AVLTree &operator=(const AVLTree &rhs);

    // Imprime a árvore AVL de forma estruturada no console.
    void printTreePretty() const;

private:
    /**
     * @brief Função auxiliar para imprimir a árvore de forma estruturada.
     *
     * @param node Nó atual da árvore.
     * @param prefix Prefixo para formatação.
     * @param isLeft Indica se o nó é filho esquerdo.
     */
    void printTreePretty(AVLNode<Comparable> *node, const std::string &prefix, bool isLeft) const;

    // Ponteiro para a raiz da árvore AVL.
    AVLNode<Comparable> *root;

    // Valor retornado quando um elemento não é encontrado na árvore.
    const Comparable ITEM_NOT_FOUND;

    /**
     * @brief Função auxiliar para obter o elemento de um nó.
     *
     * @param t Nó atual da árvore.
     */
    const Comparable &elementAt(AVLNode<Comparable> *t) const;

    /**
     * @brief Função auxiliar para inserir um elemento na árvore AVL.
     *
     * @param x Elemento a ser inserido.
     * @param t Nó atual da árvore.
     */
    void insert(const Comparable &x, AVLNode<Comparable> *&t);

    /**
     * @brief Função auxiliar para encontrar o elemento mínimo na árvore AVL.
     *
     * @param x Elemento a ser removido.
     * @param t Nó atual da árvore.
     */
    AVLNode<Comparable> *findMin(AVLNode<Comparable> *t) const;

    /**
     * @brief Função auxiliar para encontrar o elemento máximo na árvore AVL.
     *
     * @param x Elemento a ser removido.
     * @param t Nó atual da árvore.
     */
    AVLNode<Comparable> *findMax(AVLNode<Comparable> *t) const;

    /**
     * @brief Função auxiliar para buscar um elemento na árvore AVL.
     *
     * @param x Elemento a ser buscado.
     * @param t Nó atual da árvore.
     */
    AVLNode<Comparable> *find(const Comparable &x, AVLNode<Comparable> *t) const;

    /**
     * @brief Função para verificar se a árvore AVL está vazia.
     *
     * @param t Nó atual da árvore.
     */
    void makeEmpty(AVLNode<Comparable> *&t);

    /**
     * @brief Função auxiliar para verificar a altura de um nó na árvore AVL.
     *
     * @param t Nó atual da árvore.
     */
    int height(AVLNode<Comparable> *t) const;

    /**
     * @brief Função auxiliar para obter o máximo entre dois inteiros.
     *
     * @param lhs Primeiro valor.
     * @param rhs Segundo valor.
     * @return O valor máximo entre lhs e rhs.
     */
    int max(int lhs, int rhs) const;

    /**
     * @brief Função auxiliar para rotacionar a árvore AVL à esquerda.
     *
     * @param k2 Ponteiro para o nó onde a rotação será aplicada.
     */
    void rotateWithLeftChild(AVLNode<Comparable> *&k2);

    /**
     * @brief Realiza uma rotação à direita na árvore AVL.
     *
     * @param k1 Ponteiro para o nó onde a rotação será aplicada.
     */
    void rotateWithRightChild(AVLNode<Comparable> *&k1);

    /**
     * @brief Realiza uma rotação dupla à esquerda na árvore AVL.
     *
     * @param k3 Ponteiro para o nó onde a rotação será aplicada.
     */
    void doubleWithLeftChild(AVLNode<Comparable> *&k3);

    /**
     * @brief Realiza uma rotação dupla à direita na árvore AVL.
     *
     * @param k1 Ponteiro para o nó onde a rotação será aplicada.
     */
    void doubleWithRightChild(AVLNode<Comparable> *&k1);

    /**
     * @brief Função auxiliar para clonar a árvore AVL.
     *
     * @param t Nó atual da árvore.
     */
    AVLNode<Comparable> *clone(AVLNode<Comparable> *t) const;
};

#include "AVLTree.tpp"

#endif // AVLTREE_H
