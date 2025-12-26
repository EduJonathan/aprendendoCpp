#include <iostream>
#include "BinaryTree.hpp"

// Construtor do nó
Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

// Construtor da árvore
BSTree::BSTree() : root(nullptr) {}

// Destrutor da árvore
BSTree::~BSTree()
{
    std::cout << "Destrutor da árvore chamado." << '\n';
    // Nada mais a fazer — std::unique_ptr lida com a liberação de memória automaticamente.
}

/**
 * @brief Insere recursivamente um valor na árvore.
 *
 * @param node Referência ao ponteiro único do nó atual.
 * @param value Valor a ser inserido.
 */
void BSTree::insert(std::unique_ptr<Node> &node, int value)
{
    if (!node)
    {
        node = std::make_unique<Node>(value);
    }
    else if (value < node->value)
    {
        insert(node->left, value);
    }
    else if (value > node->value)
    {
        insert(node->right, value);
    }
    // Duplicados não são inseridos
}

/**
 * @brief Realiza uma busca recursiva por um valor na árvore.
 *
 * @param node Ponteiro constante para o nó atual.
 * @param value Valor a ser buscado.
 * @return true se o valor for encontrado, false caso contrário.
 */
bool BSTree::search(const std::unique_ptr<Node> &node, int value)
{
    if (!node)
        return false;

    if (value == node->value)
        return true;

    if (value < node->value)
        return search(node->left, value);

    return search(node->right, value);
}

/**
 * @brief Percorre a árvore em ordem (in-order) e armazena os valores em um vetor.
 *
 * @param node Ponteiro constante para o nó atual.
 * @param result Vetor que armazena os valores em ordem crescente.
 */
void BSTree::inorderTraversal(const std::unique_ptr<Node> &node, std::vector<int> &result)
{
    if (node)
    {
        inorderTraversal(node->left, result);
        result.push_back(node->value);
        inorderTraversal(node->right, result);
    }
}
/**
 * @brief Insere um valor na árvore.
 *
 * @param value Valor a ser inserido.
 */
void BSTree::insert(int value)
{
    insert(root, value);
}

/**
 * @brief Verifica se um valor existe na árvore.
 *
 * @param value Valor a ser buscado.
 * @return true se o valor for encontrado, false caso contrário.
 */
bool BSTree::search(int value)
{
    return search(root, value);
}

/**
 * @brief Retorna os valores da árvore em ordem crescente.
 *
 * @return Um vetor com os valores em ordem.
 */
std::vector<int> BSTree::inorder(void)
{
    std::vector<int> result;
    inorderTraversal(root, result);
    return result;
}

int main(int argc, char **argv)
{
    BSTree tree;

    // Inserir elementos na BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Buscar valores
    std::cout << "Buscar 7: " << (tree.search(7) ? "Encontrado" : "Não encontrado") << '\n';
    std::cout << "Buscar 40: " << (tree.search(40) ? "Encontrado" : "Não encontrado") << '\n';
    std::cout << "Buscar 12: " << (tree.search(12) ? "Encontrado" : "Não encontrado") << '\n';

    // Exibir percurso em ordem
    std::cout << "Elementos em ordem: ";
    for (int val : tree.inorder())
    {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    return 0;
}
