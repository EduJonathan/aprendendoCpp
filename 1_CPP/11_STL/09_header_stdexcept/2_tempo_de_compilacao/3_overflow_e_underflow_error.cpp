#include <iostream>
#include <stdexcept>

const int MAX_RECURSION_DEPTH = 5; // Limite para simular overflow de pilha
int current_depth = 0;             // Profundidade atual da "pilha de chamadas"

// Estrutura da pilha como struct simples
struct Stack
{
    int *data;
    int top;
    int capacity;
};

/**
 * @brief Cria uma pilha com capacidade especificada.
 *
 * @param size Capacidade da pilha.
 * @return Stack A pilha criada.
 * @note Esta função aloca memória dinâmica para a pilha e inicializa seus atributos.
 */
Stack createStack(int size)
{
    Stack s;
    s.data = new int[size]; // alocação dinâmica
    s.top = -1;
    s.capacity = size;
    return s;
}

/**
 * @brief Libera a memória alocada para a pilha.
 *
 * @param s Pilha a ser destruída.
 * @note Esta função libera a memória alocada para a pilha e redefine seus atributos.
 * @note É importante chamar esta função para evitar vazamentos de memória.
 */
void destroyStack(Stack &s)
{
    delete[] s.data;
    s.data = nullptr;
    s.top = -1;
    s.capacity = 0;
}

/**
 * @brief Adiciona um elemento ao topo da pilha.
 *
 * @param s Pilha na qual o elemento será adicionado.
 * @param value O valor a ser adicionado à pilha.
 * @note Overflow é quando tentamos ultrapassar a capacidade.
 */
void push(Stack &s, int value)
{
    if (s.top >= s.capacity - 1)
    {
        throw std::overflow_error("Stack Overflow.");
    }
    s.data[++s.top] = value;
}

/**
 * @brief Remove e retorna o elemento do topo da pilha.
 *
 * @param s Pilha da qual o elemento será removido.
 * @return int O elemento removido do topo da pilha.
 * @note Underflow é quando tentamos remover um elemento um elemento.
 */
int pop(Stack &s)
{
    if (s.top < 0)
    {
        throw std::underflow_error("Stack Underflow.");
    }
    return s.data[s.top--];
}

/**
 * @brief Verifica se a pilha está vazia.
 *
 * @param s Pilha a ser verificada.
 * @return true se a pilha estiver vazia, false caso contrário.
 * @note Esta função verifica se a pilha está vazia, ou seja, se o índice do topo é -1.
 */
bool isEmpty(const Stack &s) { return s.top == -1; }

/**
 * @brief Verifica se a pilha está cheia.
 *
 * @param s Pilha a ser verificada.
 * @return true se a pilha estiver cheia, false caso contrário.
 */
bool isFull(const Stack &s) { return s.top == s.capacity - 1; }

/**
 * @brief Soma recursivamente os números de 1 a n.
 *
 * @param n O número até o qual a soma será realizada.
 * @return int A soma dos números de 1 a n.
 * @note current_depth simula o controle da profundidade da pilha de chamadas.
 * A cada chamada recursiva, a profundidade é aumentada.
 */
int sumRecursion(int n)
{
    // Verifica se a profundidade máxima foi alcançada
    if (current_depth >= MAX_RECURSION_DEPTH)
    {
        throw std::overflow_error("Stack Overflow: Profundidade máxima de recursão alcançada.");
    }

    // Simula o aumento da profundidade da pilha de chamadas
    current_depth++;

    // Caso base da recursão
    if (n <= 0)
    {
        current_depth--; // Decrementa a profundidade ao retornar
        return 0;
    }

    // Chamada recursiva
    int result = n + sumRecursion(n - 1);

    // Decrementa a profundidade ao retornar
    current_depth--;

    return result;
}

int main(int argc, char **argv)
{
    Stack s = createStack(3);

    try
    {
        push(s, 10);
        push(s, 20);
        push(s, 30);
        push(s, 40); // <- overflow aqui
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << pop(s) << '\n';
        std::cout << pop(s) << '\n';
        std::cout << pop(s) << '\n';
        std::cout << pop(s) << '\n'; // <- underflow aqui
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    destroyStack(s);

    std::cout << "-----------------------------------" << '\n';

    try
    {
        int result = sumRecursion(5); // Vai tentar somar os primeiros 10 números
        std::cout << "Resultado: " << result << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
