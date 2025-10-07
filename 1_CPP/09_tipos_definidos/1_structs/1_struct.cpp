#include <iostream>
#include <new>

/**
 * STRUCTS: Agrupa variáveis de diferentes tipos sob um único nome. São úteis para modelar
 * objetos com múltiplos atributos. E cada um de seus membros possuem um espaço de memória
 * para si próprios.
 */

#ifndef NODE
#define NODE

/**
 * @brief Estrutura de um nó em uma árvore binária.
 */
struct node
{
    int data;    /**< Valor armazenado no nó. */
    node *left;  /**< Ponteiro para o nó filho à esquerda. */
    node *right; /**< Ponteiro para o nó filho à direita. */
};

#endif

/**
 * @brief Cria um novo nó com o valor fornecido.
 *
 * @param valor O valor a ser armazenado no nó.
 * @return Um ponteiro para o novo nó criado.
 */
node *criarNo(int valor)
{
    node *newNode = new node; // Aloca memória para o novo nó
    newNode->data = valor;    // Armazena o valor
    newNode->left = nullptr;  // Inicia a subárvore esquerda como nula
    newNode->right = nullptr; // Inicia a subárvore direita como nula
    return newNode;           // Retorna o ponteiro para o novo nó
}

/**
 * @brief Insere um valor na árvore binária de busca.
 *
 * @param root Ponteiro para a raiz da árvore.
 * @param data O valor a ser inserido na árvore.
 * @return Ponteiro para a raiz da árvore após a inserção.
 */
node *insert(node *root, int data)
{
    // Caso base: se a raiz for nula, cria um novo nó
    if (root == nullptr)
    {
        return criarNo(data);
    }
    if (data < root->data)
    {
        // Se o valor for menor que o valor armazenado na raiz, insere na subárvore esquerda
        // Insere dado na subárvore esquerda
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        // Se o valor for maior que o valor armazenado na raiz, insere na subárvore direita
        // Insere dado na subárvore direita
        root->right = insert(root->right, data);
    }

    // Retorna a raiz da árvore
    return root;
}

/**
 * @brief Imprime os valores da árvore em ordem (inOrder).
 *
 * @param root Ponteiro para a raiz da árvore.
 * @note inOrder imprime os valores da árvore em ordem crescente.
 */
void inOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left); // Imprime os valores da subárvore esquerda
    std::cout << "Valor de -> " << root->data << '\n';
    inOrder(root->right); // Imprime os valores da subárvore direita
}

int main(int argc, char **argv)
{
    /**
     * OBS: Em C++, a declaração de struct necessariamente não precisa ser seguida
     * igualmente no C, que se declara(struct node root;) a criação do seu tipo em C++
     * apenas basta inserir o nome da <struct> <identificador para struct>.
     */

    // Declarando a raiz da árvore
    node *root = nullptr;

    // Inserindo valores na árvore
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Imprimindo os valores da árvore
    inOrder(root);
    return 0;
}
