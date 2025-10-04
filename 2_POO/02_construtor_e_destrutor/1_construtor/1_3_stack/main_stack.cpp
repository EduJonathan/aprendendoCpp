#include <stdexcept>
#include <new>
#include "class_stack.hpp"

Stack::Stack(std::size_t capacity)
{
    if (capacity <= 0)
    {
        throw std::invalid_argument("Capacidade deve ser maior que zero.");
    }
    this->capacity = capacity;         // Define a capacidade da pilha
    array = new std::size_t[capacity]; // Aloca o array com std::size_t
    top = -1;                          // Inicializa a pilha como vazia
}

Stack::~Stack()
{
    delete[] array; // Libera a memória alocada para o array
}

bool Stack::isEmpty(void)
{
    return (top == -1);
}

bool Stack::isFull(void)
{
    return (top == capacity - 1);
}

void Stack::push(int value)
{
    if (!isFull())
    {
        std::cout << "Empilhando: " << value << '\n';
        array[++top] = value; // Empilha o valor no topo e incrementa o índice do topo
    }
    else
    {
        std::cerr << "Pilha cheia!" << '\n';
    }
}

int Stack::pop(void)
{
    if (!isEmpty())
    {
        std::cout << "Desempilhando: " << array[top] << '\n';
        return array[top--]; // Retorna o valor no topo e decrementa o índice do topo
    }
    else
    {
        std::cerr << "Pilha vazia!" << '\n';
    }
    return -1;
}

int main(int argc, char **argv)
{
    // Criando uma pilha com capacidade 5
    // A pilha é criada automaticamente na pilha de execução e será destruída
    // automaticamente no final do escopo (destruidor será chamado)
    Stack pilha(5);

    pilha.push(10); // Empilha o valor 10
    pilha.push(20); // Empilha o valor 20
    pilha.push(30); // Empilha o valor 30
    pilha.push(40); // Empilha o valor 40
    pilha.push(50); // Empilha o valor 50
    pilha.push(60); // Tentativa de empilhar o valor 60 (falha, pois a pilha está cheia)

    pilha.pop(); // Desempilha o valor do topo
    pilha.pop(); // Desempilha o valor do topo
    pilha.pop(); // Desempilha o valor do topo
    pilha.pop(); // Desempilha o valor do topo
    pilha.pop(); // Desempilha o valor do topo
    pilha.pop(); // Tentativa de desempilhar quando a pilha está vazia (erro)

    return 0; // Ao sair de 'main', a pilha será destruída e o destruidor chamado
}
