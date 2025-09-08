#include <iostream>

#ifndef NODE
#define NODE

/**
 * @brief Estrutura que representa um nó de uma lista encadeada.
 */
struct Node
{
    int dado;   ///< Valor armazenado no nó
    Node *prox; ///< Ponteiro para o próximo nó

    /**
     * @brief Construtor da estrutura Node.
     *
     * @param valor O valor a ser armazenado no nó.
     */
    Node(int valor) : dado(valor), prox(nullptr) {}

    /**
     * @brief Insere um novo nó no final da lista.
     *
     * @param head Ponteiro para o início da lista.
     * @param valor O valor do novo nó.
     *
     * @note A combinação `*&` em (Node *&head): Significa que head é um ponteiro para
     * referência permitindo que a função altere o ponteiro original diretamente.
     * A função pode mudar o endereço para o qual o ponteiro head aponta.
     */
    void insertNode(Node *&head, int valor)
    {
        Node *newNode = new Node(valor); // Cria um novo nó

        // Se a lista estiver vazia, o novo nó é o primeiro
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            // Encontra o último nó da lista
            while (temp->prox != nullptr)
            {
                temp = temp->prox;
            }
            temp->prox = newNode; // Conecta o último nó ao novo nó
        }
    }

    /**
     * @brief Deleta o primeiro nó da lista.
     *
     * @param head Ponteiro para o início da lista.
     */
    void deletar(Node *&head)
    {
        // Verifica se a lista está vazia
        if (head == nullptr)
        {
            std::cout << "A lista está vazia. Nenhum nó para deletar.\n";
            return;
        }

        Node *temp = head; // Armazena o nó a ser deletado
        head = head->prox; // Atualiza o ponteiro da cabeça para o próximo nó
        delete temp;       // Libera a memória do nó deletado
        std::cout << "Nó deletado do início.\n";
    }

    /**
     * @brief Exibe todos os elementos da lista.
     *
     * @param head Ponteiro para o início da lista.
     */
    void display(Node *head)
    {
        // Verifica se a lista está vazia
        if (head == nullptr)
        {
            std::cout << "A lista está vazia.\n";
            return;
        }

        Node *temp = head;

        // Exibe os valores de todos os nós
        while (temp != nullptr)
        {
            std::cout << temp->dado << " -> ";
            temp = temp->prox;
        }
        std::cout << "nullptr\n";
    }

    /**
     * @brief Libera toda a memória da lista.
     *
     * @param head Ponteiro para o início da lista.
     */
    void liberarMemoria(Node *&head)
    {
        Node *temp = nullptr;

        // Libera cada nó da lista
        while (head != nullptr)
        {
            temp = head;
            head = head->prox;
            delete temp; // Libera a memória do nó
        }
        std::cout << "Memória da lista liberada.\n";
    }
};

#endif

int main(int argc, char **argv)
{
    Node *head = nullptr; /** Iniciando a lista com o inicio sendo nulo */

    // Nó inicial (não será usado diretamente, apenas para usar os métodos)
    Node node(0);

    // Inserir elementos na lista
    node.insertNode(head, 10);
    node.insertNode(head, 20);
    node.insertNode(head, 30);

    // Exibir a lista antes da exclusão
    std::cout << "Lista antes da exclusão: ";
    node.display(head);

    // Deletar o primeiro nó da lista
    node.deletar(head);

    std::cout << '\n';

    // Exibir a lista após a exclusão
    std::cout << "Lista após a exclusão: ";
    node.display(head);

    // Liberar toda a memória da lista
    node.liberarMemoria(head);
    return 0;
}
