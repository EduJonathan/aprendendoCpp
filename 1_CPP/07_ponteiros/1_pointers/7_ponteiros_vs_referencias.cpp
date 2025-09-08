#include <iostream>
#include <new>

/**
 * REFERÊNCIAS: EM C++, referências são um "apelido" para uma variável existente, as referências
 * são criadas usando o operador '&'. Não podem ser nulas (devem referenciar um objeto válido)
 * Não podem ser reassinaladas após inicialização. Sintaxe mais limpa e intuitiva.
 * São automaticamente desreferenciadas.
 *
 * USE REFERÊNCIAS (&):
 *
 * - Use referências para passar variáveis para funções quando você quer modificar o valor original
 * sem a sobrecarga de copiar (passagem por valor) e com sintaxe mais limpa que ponteiros.
 *
 * - Para objetos grandes (como structs ou classes), passe por referência constante (`const T&`)
 * para evitar cópias e garantir que o objeto não será modificado.
 *
 * - Quando você precisa de um nome alternativo para uma variável existente, sem manipular
 * endereços de memória.
 *
 * -------------------
 *
 * - QUANDO NÃO USAR:
 *
 * - Se referências não podem ser nulas, então não as use se a variável pode não existir ou ser opcional.
 *
 * - Referências não podem ser reatribuídas para referenciar outra variável após a inicialização.
 *
 * - Referências não são adequadas para estruturas como listas encadeadas ou árvores,
 * onde você precisa manipular endereços de memória dinamicamente.
 *
 * -------------------
 *
 * PONTEIROS: Já os ponteiros são variáveis que armazenam o endereço de memória de outra variável,
 * os ponteiros são criados usando o operador '*'. Podem ser reassinalados (p = &outra_variavel).
 * Podem ser nulos (nullptr). Sintaxe mais explícita
 *
 * -------------------
 *
 * * USE PONTEIROS (*):
 *
 * - Para alocação dinâmica (ex.: new) ou estruturas complexas (ex.: listas encadeadas).
 * - Ponteiros podem ser nullptr, úteis para indicar ausência de valor ou inicialização.
 * - Use em listas encadeadas, árvores ou grafos, onde você precisa armazenar e manipular
 * endereços de memória.
 *
 * -------------------
 *
 * - QUANDO NÃO USAR:
 *
 * - Evite ponteiros em funções simples onde referências são suficientes e mais seguras
 * (evitam erros como desreferenciar nullptr).
 *
 * - Ponteiros são propensos a erros como dangling pointers (apontar para memória inválida)
 * ou desreferenciamento de nullptr. Use referências ou smart pointers (std::unique_ptr,
 * std::shared_ptr) quando possível.
 *
 * - Em C++ moderno, smart pointers ou contêineres da STL (como std::vector) são preferíveis
 * para gerenciar memória em vez de ponteiros brutos.
 */

// Referência: modificação simples e segura
void incrementa_ref(int &r)
{
    r++; // Sintaxe limpa, sem nulidade
}

// Ponteiro: permite nulidade e verificação
void incrementa_ptr(int *p)
{
    if (p)      // Verifica se não é nulo
        (*p)++; // Desreferencia explicitamente para modificar
}

/**
 * Evita cópia de objetos grandes, no caso os próprios objetos de estruturas de dados da STL,
 * (como std::string, std::vector, etc.), garantindo que o objeto não será modificado.
 */
void print(const std::string &s)
{
    std::cout << "String: " << s << '\n';
}

// Ponteiro: alocação dinâmica para estrutura
struct Node
{
    int data;
    Node *next;
};

int main(int argc, char **argv)
{
    int a = 10;
    incrementa_ref(a);                          // Referência: modifica diretamente
    std::cout << "a (após ref): " << a << '\n'; // Saída: 11

    int b = 20;
    int *p = &b;
    incrementa_ptr(p);                          // Ponteiro: permite nulidade
    std::cout << "b (após ptr): " << b << '\n'; // Saída: 21
    incrementa_ptr(nullptr);                    // Seguro, não altera nada

    std::string s = "Exemplo";
    print(s); // Referência constante: evita cópia

    Node *node = new Node{42, nullptr};               // Ponteiro: alocação dinâmica
    std::cout << "Node data: " << node->data << '\n'; // Saída: 42
    delete node;                                      // Gerenciamento manual

    return 0;
}
