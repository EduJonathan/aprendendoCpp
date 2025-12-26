#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <memory>
#include <vector>

/**
 * @brief Estrutura que representa um nó em uma árvore binária de busca (BST).
 */
struct Node
{
    int value;                   // Valor armazenado no nó
    std::unique_ptr<Node> left;  // Ponteiro para o filho esquerdo
    std::unique_ptr<Node> right; // Ponteiro para o filho direito
    Node(int val);               // Construtor para inicializar o nó com um valor
};

/**
 * @class BSTree
 *
 * @brief Classe que implementa uma árvore binária de busca (Binary Search Tree).
 */
class BSTree
{
private:
    std::unique_ptr<Node> root;

    void insert(std::unique_ptr<Node> &node, int value);
    bool search(const std::unique_ptr<Node> &node, int value);
    void inorderTraversal(const std::unique_ptr<Node> &node, std::vector<int> &result);

public:
    BSTree();
    ~BSTree();

    void insert(int value);
    bool search(int value);
    std::vector<int> inorder(void);
};

#endif // BSTREE_HPP
