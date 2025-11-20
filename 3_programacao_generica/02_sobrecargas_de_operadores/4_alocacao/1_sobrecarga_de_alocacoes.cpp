#include <iostream>
#include <cstdlib>
#include <new>

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
