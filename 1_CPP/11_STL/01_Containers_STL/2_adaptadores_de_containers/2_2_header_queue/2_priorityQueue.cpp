#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <queue>

/**
 * std::priority_queue<T> é uma fila de prioridade que organiza os elementos
 * segundo uma função de comparação, garantindo que o elemento de maior prioridade
 * seja acessado primeiro.
 */

/**
 * @struct minHeapNode
 *
 * @brief Estrutura que representa um nó de uma árvore binária usada para construir
 * a árvore de Huffman.
 */
struct minHeapNode
{
    char data;                 /**< Caractere armazenado no nó */
    unsigned frequency;        /**< Frequência do caractere */
    minHeapNode *left, *right; /**< Ponteiros para os filhos esquerdo e direito */

    /**
     * @brief Construtor da estrutura minHeapNode.
     *
     * @param data Caractere a ser armazenado no nó.
     * @param frequency Frequência do caractere.
     */
    minHeapNode(char data, unsigned frequency)
    {
        left = right = nullptr;      // Inicializa os ponteiros filhos como nulos
        this->data = data;           // Armazena o caractere
        this->frequency = frequency; // Armazena a frequência
    }
};

/**
 * @struct compare
 *
 * @brief Função comparadora para a fila de prioridade que organiza os nós por ordem
 * crescente de frequência.
 */
struct compare
{
    /**
     * @brief Sobrecarga do operador de comparação para ordenar nós de acordo com sua frequência.
     *
     * @param l Nó à esquerda da comparação.
     * @param r Nó à direita da comparação.
     * @return Retorna verdadeiro se a frequência do nó à esquerda for maior
     * que a do nó à direita.
     */
    bool operator()(minHeapNode *left, minHeapNode *right)
    {
        return (left->frequency > right->frequency);
    }
};

/**
 * @brief Função recursiva para imprimir os códigos de Huffman a partir da árvore gerada.
 *
 * @param root Raiz da árvore de Huffman.
 * @param str Código binário gerado até o nó atual.
 */
void printCodes(minHeapNode *root, const std::string &str)
{
    if (root == nullptr)
    {
        return;
    }

    // Se o nó não for um nó interno (ou seja, for uma folha), imprime o caractere e seu código
    if (root->data != '$')
    {
        std::cout << root->data << ": " << str << '\n';
    }

    // Recorre para os filhos esquerdo e direito
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

/**
 * @brief Função para construir a árvore de Huffman e gerar os códigos.
 *
 * @param data Array de caracteres que representam os símbolos.
 * @param freq Array de frequências dos símbolos correspondentes.
 * @param size Tamanho do array.
 *
 * @note Huffman Coding é uma técnica de compressão de dados para reduzir o seu tamanho
 * sem perder nenhum dos detalhes. Caracteres mais frequentes têm códigos binários mais curtos.
 */
void HuffmanCodes(char data[], int freq[], std::size_t size)
{
    struct minHeapNode *left = nullptr, *right = nullptr, *top = nullptr;
    std::priority_queue<minHeapNode *, std::vector<minHeapNode *>, compare> minHeap;

    // Criação dos nós e inserção na fila de prioridade
    for (std::size_t i = 0ull; i < size; ++i)
    {
        minHeap.push(new minHeapNode(data[i], freq[i]));
    }

    // Construção da árvore de Huffman
    while (minHeap.size() != 1)
    {
        // Obtem o nó com menor frequência da fila de prioridade na esquerda
        left = minHeap.top();
        minHeap.pop();

        // Obtem o nó com menor frequência da fila de prioridade na direita
        right = minHeap.top();
        minHeap.pop();

        // Criação do nó interno '$'
        top = new minHeapNode('$', left->frequency + right->frequency);

        top->left = left;   // Atribui o filho esquerdo ao nó interno
        top->right = right; // Atribui o filho direito ao nó interno

        // Insere o nó interno na fila de prioridade
        minHeap.push(top);
    }

    // Imprime os códigos gerados pela árvore de Huffman
    printCodes(minHeap.top(), "");
}

int main(int argc, char **argv)
{
    // Array de caracteres a serem codificados
    char arr[] = {'a', 'e', 'i', 'o', 'u'};

    // Frequências dos caracteres
    int frequencia[] = {5, 9, 12, 13, 16};

    // Tamanho do array
    std::size_t size = sizeof(arr) / sizeof(arr[0]);

    // Geração e impressão dos códigos de Huffman
    HuffmanCodes(arr, frequencia, size);

    return 0;
}
