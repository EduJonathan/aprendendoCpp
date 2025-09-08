#include <iostream>
#include <cstdlib>
#include <new>

/**
 * A sobrecarga dos operadores de alocação `new`, `new[]`, `delete` e `delete[]` permite
 * personalizar o comportamento de alocação e desalocação de memória em C++. Esses operadores
 * são chamados automaticamente quando você usa `new` ou `delete` para alocar ou desalocar
 * objetos ou arrays.
 *
 * Sobrecargar esses operadores é uma técnica avançada e útil para controle detalhado de memória,
 * como para rastreamento de memória, alocadores customizados ou para garantir um gerenciamento
 * de recursos eficiente. Isso deve ser feito com muito cuidado para evitar vazamentos de memória
 * ou outros erros de gerenciamento de memória.
 *
 * O `new` e `delete` são usados para alocar/desalocar um único objeto, enquanto o `new[]` e
 * `delete[]` são usados para alocar/desalocar arrays de objetos.
 *
 * Quando usar:
 * - Quando você precisa de controle personalizado sobre a alocação de memória.
 * - Quando deseja monitorar ou rastrear alocações e desalocações de memória.
 * - Quando você está implementando um alocador customizado.
 */

class MinhaClasse
{
public:
    // Sobrecarga de new para um único objeto
    void *operator new(std::size_t size)
    {
        std::cout << "Alocando " << size << " bytes para um objeto\n";
        return std::malloc(size);
    }

    // Sobrecarga de delete para um único objeto
    void operator delete(void *ptr)
    {
        std::cout << "Liberando memória de um objeto\n";
        std::free(ptr);
    }

    // Sobrecarga de new[] para um array de objetos
    void *operator new[](std::size_t size)
    {
        std::cout << "Alocando " << size << " bytes para um array\n";
        return std::malloc(size);
    }

    // Sobrecarga de delete[] para um array de objetos
    void operator delete[](void *ptr)
    {
        std::cout << "Liberando memória de um array\n";
        std::free(ptr);
    }
};

int main(int argc, char **argv)
{
    // Alocação e liberação de um único objeto
    MinhaClasse *obj = new MinhaClasse();
    delete obj;

    // Alocação e liberação de um array de objetos
    MinhaClasse *arr = new MinhaClasse[3];
    delete[] arr;

    return 0;
}
