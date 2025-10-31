#include <iostream>
#include <cstdlib>
#include <new> // Para std::bad_alloc
#include <limits>

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
 * - Retorna void* (precisa de cast)
 * - Retorna nullptr em caso de falha
 * - Não garante alinhamento para tipos específicos
 * - Não integra com sistema de exceções do C++
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

void demonstrarBadAlloc()
{
    std::cout << "\n=== DEMONSTRANDO std::bad_alloc ===" << '\n';

    // Tentativa de alocação enorme que provavelmente falhará
    try
    {
        std::size_t tamanhoEnorme = std::numeric_limits<std::size_t>::max();
        int *memoria = new int[tamanhoEnorme];
        std::cout << "Alocação bem-sucedida (improvável)" << '\n';
        delete[] memoria;
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << "std::bad_alloc capturada: " << e.what() << '\n';
    }
}

void compararTratamentoErros()
{
    std::cout << "\n=== TRATAMENTO DE ERROS: new vs malloc ===" << '\n';

    // Tratamento com malloc (estilo C)
    std::cout << "Com malloc:" << '\n';
    void *mem1 = std::malloc(1000000000000ULL); // Tamanho enorme
    if (mem1 == nullptr)
    {
        std::cout << "malloc falhou - retornou nullptr" << '\n';
    }
    else
    {
        std::cout << "malloc bem-sucedido" << '\n';
        std::free(mem1);
    }

    // Tratamento com new (estilo C++)
    std::cout << "Com new:" << '\n';
    try
    {
        int *mem2 = new int[1000000000000ULL]; // Tamanho enorme
        std::cout << "new bem-sucedido" << '\n';
        delete[] mem2;
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << "new falhou - lançou std::bad_alloc: " << e.what() << '\n';
    }
}

void versaoNothrow()
{
    std::cout << "\n=== VERSÃO NOTHROW DE new ===" << '\n';

    // new com std::nothrow (não lança exceção, retorna nullptr)
    int *mem = new (std::nothrow) int[1000000000000ULL];
    if (mem == nullptr)
    {
        std::cout << "new(nothrow) falhou - retornou nullptr" << '\n';
    }
    else
    {
        std::cout << "new(nothrow) bem-sucedido" << '\n';
        delete[] mem;
    }
}

void exemploRecuperacao()
{
    std::cout << "\n=== EXEMPLO DE RECUPERAÇÃO ===" << '\n';

    bool sucesso = false;
    std::size_t tamanho = 1000000000; // Começa com 1GB

    while (!sucesso && tamanho > 0)
    {
        try
        {
            char *buffer = new char[tamanho];
            std::cout << "Alocação bem-sucedida: " << tamanho << " bytes" << '\n';
            delete[] buffer;
            sucesso = true;
        }
        catch (const std::bad_alloc &e)
        {
            std::cout << "Falha ao alocar " << tamanho << " bytes, tentando menos..." << '\n';
            tamanho /= 2; // Tenta metade do tamanho
        }
    }

    if (!sucesso)
    {
        std::cout << "Não foi possível alocar memória mesmo com tamanhos menores" << '\n';
    }
}

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

    // Demonstrações com std::bad_alloc
    demonstrarBadAlloc();
    compararTratamentoErros();
    versaoNothrow();
    exemploRecuperacao();

    return 0;
}
