#ifndef AVLTREE_H
#define AVLTREE_H

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <new>
#include <functional>

/**
 * @brief Classe genérica de nó utilizada em árvores binárias.
 *
 * @tparam T Tipo de dado armazenado no nó.
 */
template <typename T>
class Node;

/**
 * @brief Classe base para implementação de Árvore Binária de Busca.
 *
 * @tparam T Tipo de dado armazenado na árvore.
 */
template <typename T>
class BinarySearchTree
{
public:
    /// Ponteiro para o nó raiz da árvore.
    Node<T> *root;

    /// Construtor da árvore.
    BinarySearchTree();

    /// Destrutor virtual da árvore.
    virtual ~BinarySearchTree();

    /**
     * @brief Adiciona um valor à árvore.
     *
     * @param id Valor a ser inserido.
     * @return Ponteiro para o nó inserido.
     */
    virtual Node<T> *addValue(const T &id);

    /**
     * @brief Retorna o nó que contém o valor especificado.
     *
     * @param value Valor a ser buscado.
     * @return Ponteiro para o nó encontrado, ou nullptr.
     */
    virtual Node<T> *getNode(const T &value);

    /**
     * @brief Retorna um nó substituto para remoção.
     * 
     * @param node Nó a ser substituído.
     * @return Ponteiro para o nó substituto.
     */
    virtual Node<T> *getReplacementNode(Node<T> *node);

    /**
     * @brief Substitui um nó antigo por um novo na árvore.
     *
     * @param oldNode Nó antigo a ser substituído.
     * @param newNode Novo nó que ocupará o lugar.
     */
    virtual void replaceNodeWithNode(Node<T> *oldNode, Node<T> *newNode);

    /**
     * @brief Valida a integridade do nó.
     *
     * @param node Nó a ser validado.
     * @return Verdadeiro se o nó for válido.
     */
    virtual bool validateNode(Node<T> *node);

protected:
    /// Função usada para criar novos nós.
    using NodeCreator = std::function<Node<T> *(Node<T> *, const T &)>;

    /**
     * @brief Cria um novo nó (pode ser sobrescrito por classes derivadas).
     *
     * @param parent Nó pai.
     * @param id Valor do nó.
     * @return Novo nó criado.
     */
    virtual Node<T> *createNewNode(Node<T> *parent, const T &id);

private:
    /// Remove recursivamente os nós da subárvore.
    void deleteSubtree(Node<T> *node);
};

/**
 * @brief Classe que representa um nó básico da árvore binária.
 *
 * @tparam T Tipo de dado armazenado no nó.
 */
template <typename T>
class Node
{
public:
    T id;             ///< Valor armazenado no nó.
    Node<T> *parent;  ///< Ponteiro para o nó pai.
    Node<T> *lesser;  ///< Ponteiro para o filho à esquerda.
    Node<T> *greater; ///< Ponteiro para o filho à direita.

    /**
     * @brief Construtor do nó.
     *
     * @param parent Nó pai.
     * @param id Valor armazenado.
     */
    Node(Node<T> *parent, const T &id);

    /// Destrutor virtual.
    virtual ~Node();
};

/**
 * @brief Implementação da Árvore AVL, derivada da BinarySearchTree.
 *
 * @tparam T Tipo de dado armazenado.
 */
template <typename T>
class AVLTree : public BinarySearchTree<T>
{
private:
    /// Enumeração usada para identificar o tipo de desbalanceamento.
    enum class Balance
    {
        LEFT_LEFT,
        LEFT_RIGHT,
        RIGHT_LEFT,
        RIGHT_RIGHT
    };

    /**
     * @brief Nó específico da Árvore AVL, com suporte a altura.
     */
    class AVLNode : public Node<T>
    {
    public:
        int height; ///< Altura do nó.

        /// Construtor do nó AVL.
        AVLNode(Node<T> *parent, const T &value);

        /// Verifica se o nó é uma folha.
        bool isLeaf() const;

        /// Atualiza e retorna a nova altura do nó.
        int updateHeight();

        /// Retorna o fator de balanceamento do nó.
        int getBalanceFactor() const;

        /// Retorna uma representação em string do nó.
        std::string toString() const;
    };

public:
    /// Construtor padrão.
    AVLTree();

    /// Construtor com criador de nós personalizado.
    AVLTree(typename BinarySearchTree<T>::NodeCreator creator);

    /// Destrutor.
    ~AVLTree() override;

    /**
     * @brief Adiciona um valor à árvore AVL.
     *
     * @param id Valor a ser inserido.
     * @return Ponteiro para o nó inserido.
     */
    Node<T> *addValue(const T &id) override;

    /**
     * @brief Remove um valor da árvore AVL.
     *
     * @param value Valor a ser removido.
     * @return Ponteiro para o nó removido.
     */
    virtual Node<T> *removeValue(const T &value);

    /**
     * @brief Retorna uma representação textual da árvore.
     *
     * @return String contendo a árvore formatada.
     */
    std::string toString() const;

protected:
    /// Cria um novo nó AVL.
    Node<T> *createNewNode(Node<T> *parent, const T &id) override;

    /// Valida a estrutura AVL de um nó.
    bool validateNode(Node<T> *node) override;

private:
    /// Rotação simples à esquerda.
    void rotateLeft(AVLNode *node);

    /// Rotação simples à direita.
    void rotateRight(AVLNode *node);

    /// Balanceia a árvore após inserção.
    void balanceAfterInsert(AVLNode *node);

    /// Balanceia a árvore após remoção.
    void balanceAfterDelete(AVLNode *node);

    /**
     * @brief Classe auxiliar para imprimir a árvore AVL.
     */
    class AVLTreePrinter
    {
    public:
        /// Retorna a string representando a árvore inteira.
        static std::string getString(const AVLTree<T> *tree);

        /// Retorna a string representando um nó.
        static std::string getString(AVLNode *node);

    private:
        /// Método recursivo para construir a visualização da árvore.
        static std::string getString(AVLNode *node, const std::string &prefix, bool isTail);
    };
};

#include "AVLTree.tpp"

#endif // AVLTREE_H
