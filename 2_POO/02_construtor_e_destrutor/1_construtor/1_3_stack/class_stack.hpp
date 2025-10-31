#ifndef CLASS_STACK_HPP
#define CLASS_STACK_HPP

/**
 * @brief Classe que representa uma pilha (Stack) com capacidade fixa.
 */
class Stack
{
private:
    std::size_t *array;   /**< Ponteiro que vai armazenar os elementos da pilha dinamicamente. */
    std::size_t capacity; /**< Capacidade máxima da pilha. */
    int top;              /**< Índice do topo da pilha. */

public:
    /**
     * @brief Construtor padrão da pilha. Inicializa o topo com -1 e aloca o array dinamicamente.
     *
     * @param capacity Capacidade máxima da pilha.
     */
    Stack(std::size_t capacity);

    /**
     * @brief Destructor da pilha. Libera a memória alocada dinamicamente.
     */
    ~Stack();

    /**
     * @brief Adiciona um valor ao topo da pilha.
     *
     * @param value O valor a ser empilhado.
     */
    void push(int value);

    /**
     * @brief Remove e retorna o valor do topo da pilha.
     *
     * @return O valor no topo da pilha.
     * @retval -1 Se a pilha estiver vazia (erro).
     */
    int pop(void);

    /**
     * @brief Verifica se a pilha está vazia.
     *
     * @return Retorna true se a pilha estiver vazia, caso contrário, retorna false.
     */
    bool isEmpty(void);

    /**
     * @brief Verifica se a pilha está cheia.
     *
     * @return Retorna true se a pilha estiver cheia, caso contrário, retorna false.
     */
    bool isFull(void);
};

#endif
