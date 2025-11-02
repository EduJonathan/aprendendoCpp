#include <iostream>
#include <cstdlib>
#include <new>

/**
 * new vs malloc:
 *
 * new =>
 * - Operador do C++
 * - Chama o construtor do objeto
 * - Retorna o tipo correto (não precisa de cast)
 * - Pode ser sobrescrito (operator new)
 * - Lança std::bad_alloc em caso de falha
 * - Sempre alinha memória para qualquer tipo
 * - Trabalha com tratamento de exceções
 *
 * std::malloc =>
 * - Função da biblioteca C
 * - Não chama construtor, apenas aloca memória bruta
 * - Retorna void* (precisando de cast)
 * - Retorna nullptr em caso de falha
 * - Não garante alinhamento para tipos específicos
 * - Não integra com sistema de exceções do C++
 *
 * Sempre use new/delete em C++ para tipos com construtores/destrutores.
 * Use malloc/free apenas para alocação de memória bruta ou quando interoperando com código C.
 */

class MinhaClasse
{
public:
    int valor;

    MinhaClasse(int v) : valor(v)
    {
        std::cout << "Construtor chamado: " << valor << '\n';
    }

    ~MinhaClasse()
    {
        std::cout << "Destrutor chamado: " << valor << '\n';
    }

    void mostrar()
    {
        std::cout << "Valor: " << valor << '\n';
    }
};

int main(int argc, char **argv)
{
    std::cout << "=== USANDO new ===" << '\n';
    
    // new - maneira C++
    MinhaClasse *obj1 = new MinhaClasse(42); // Chama construtor
    obj1->mostrar();
    delete obj1; // Chama destrutor

    std::cout << "\n=== USANDO malloc ===" << '\n';

    // malloc - maneira C
    MinhaClasse *obj2 = static_cast<MinhaClasse *>(std::malloc(sizeof(MinhaClasse)));

    // ATENÇÃO: Construtor NÃO foi chamado!
    obj2->valor = 100; // Acesso direto aos membros (perigoso!)
    obj2->mostrar();   // Comportamento indefinido!
    std::free(obj2);   // Destrutor NÃO é chamado!

    std::cout << "\n=== USANDO Placement new com malloc ===" << '\n';

    // Combinação: malloc + placement new (avançado)
    void *memoria = std::malloc(sizeof(MinhaClasse));
    MinhaClasse *obj3 = new (memoria) MinhaClasse(200); // Placement new
    obj3->mostrar();
    obj3->~MinhaClasse(); // Chamada explícita do destrutor
    std::free(memoria);

    std::cout << "\n=== ALOCAÇÃO DE ARRAYS ===" << '\n';

    // Arrays com new[]
    MinhaClasse *array1 = new MinhaClasse[3]{1, 2, 3}; // Chama construtor para cada elemento
    delete[] array1;                                   // Chama destrutor para cada elemento

    // Arrays com malloc (NÃO RECOMENDADO)
    MinhaClasse *array2 = static_cast<MinhaClasse *>(std::malloc(3 * sizeof(MinhaClasse)));
    // Construtores NÃO chamados - COMPORTAMENTO INDEFINIDO!
    std::free(array2);

    return 0;
}
