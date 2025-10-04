#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @brief Classe que implementa uma pilha genérica.
 *
 * Esta classe implementa uma pilha com operações básicas de uma pilha,
 * como empilhar (push), desempilhar (pop), acessar o topo (top) e limpar
 * a pilha (ficarVazio).
 *
 * @tparam Object Tipo dos elementos armazenados na pilha.
 */
template <class Object>
class Stack
{
public:
    explicit Stack(std::size_t initialCapacity = 10);
    bool isEmpty() const;
    bool isFull() const;
    const Object &top() const;
    void ficarVazio();
    void push(const Object &obj);
    void pop();
    Object topAndPop();
    std::size_t getTopIndex() const;
    std::size_t size() const; // Método para obter o tamanho da pilha

private:
    std::vector<Object> elems; /**< Vetor que armazena os elementos da pilha. */
    std::size_t topo;          /**< Índice do topo da pilha. */
};

/**
 * @brief Construtor da pilha, que inicializa a pilha com uma capacidade específica.
 *
 * @param initialCapacity Capacidade inicial da pilha (valor padrão: 10).
 */
template <class Object>
Stack<Object>::Stack(std::size_t initialCapacity) : elems(initialCapacity)
{
    topo = static_cast<std::size_t>(-1);
}

/**
 * @brief Verifica se a pilha está vazia.
 *
 * @return true se a pilha estiver vazia, false caso contrário.
 */
template <class Object>
bool Stack<Object>::isEmpty() const
{
    return (topo == static_cast<std::size_t>(-1));
}

/**
 * @brief Verifica se a pilha está cheia.
 *
 * @return true se a pilha estiver cheia, false caso contrário.
 */
template <class Object>
bool Stack<Object>::isFull() const
{
    return (topo == elems.size() - 1);
}

/**
 * @brief Limpa todos os elementos da pilha, tornando-a vazia.
 */
template <class Object>
void Stack<Object>::ficarVazio()
{
    topo = static_cast<std::size_t>(-1);
}

/**
 * @brief Retorna o valor do topo da pilha sem removê-lo.
 *
 * @return O elemento no topo da pilha.
 * @throws "Pilha vazia" Se a pilha estiver vazia.
 */
template <class Object>
const Object &Stack<Object>::top() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Pilha vazia");
    }
    return elems[topo];
}

/**
 * @brief Empilha um novo elemento no topo da pilha.
 *
 * @param obj O elemento a ser empilhado.
 * @throws "Pilha cheia" Se a pilha estiver cheia.
 */
template <class Object>
void Stack<Object>::push(const Object &obj)
{
    if (isFull())
    {
        throw std::out_of_range("Pilha cheia");
    }
    elems[++topo] = obj;
}

/**
 * @brief Desempilha o elemento do topo da pilha.
 *
 * @throws "Pilha vazia" Se a pilha estiver vazia.
 */
template <class Object>
void Stack<Object>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Pilha vazia");
    }
    topo--; // Apenas decrementa o topo
}

/**
 * @brief Retorna o topo da pilha e o desempilha simultaneamente.
 *
 * @return O elemento do topo da pilha.
 * @throws "Pilha vazia" Se a pilha estiver vazia.
 */
template <class Object>
Object Stack<Object>::topAndPop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Pilha vazia");
    }
    return elems[topo--]; // Retorna o topo e decrementa
}

/**
 * @brief Retorna o índice do topo da pilha.
 *
 * @return O índice do topo da pilha.
 */
template <class Object>
std::size_t Stack<Object>::getTopIndex() const
{
    return topo;
}

/**
 * @brief Retorna o número de elementos na pilha.
 *
 * @return O número de elementos na pilha.
 */
template <class Object>
std::size_t Stack<Object>::size() const
{
    return topo + 1;
}

int main(int argc, char **argv)
{
    using Pilha = Stack<int>;
    Pilha pilha = Pilha(10); // Cria uma pilha de inteiros com capacidade 10.

    // Empilhando elementos
    for (std::size_t i{0ull}; i < 10; ++i)
    {
        if (!pilha.isFull())
        {
            pilha.push(i);
        }
        else
        {
            std::cout << "A pilha está cheia, não é possível empilhar " << i << '\n';
            break;
        }
    }

    // Desempilhando e exibindo os valores junto com o índice do topo
    while (!pilha.isEmpty())
    {
        std::cout << "Índice do topo: " << pilha.getTopIndex()
                  << " -> Valor: " << pilha.topAndPop() << '\n';
    }
    return 0;
}
