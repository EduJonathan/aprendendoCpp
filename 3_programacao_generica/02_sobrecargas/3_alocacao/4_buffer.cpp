#include <iostream>
#include <cstdlib>
#include <new>

// Template para alocar memória
template <typename T>
class Buffer
{
private:
    T *dados; // Ponteiro para o bloco de memória alocado
    std::size_t tamanho;

public:
    // Construtor
    Buffer(std::size_t t) : tamanho(t)
    {
        std::cout << "Criando buffer de " << t << " elementos\n";
        dados = new T[t]; // Aloca a memória para o buffer de T
    }

    // Destruidor
    ~Buffer()
    {
        std::cout << "Liberando buffer de " << tamanho << " elementos\n";
        delete[] dados; // Libera a memória do buffer
    }

    // Sobrecarga de new para alocar memória para um único objeto
    static void *operator new(std::size_t size)
    {
        std::cout << "Alocando " << size << " bytes para um objeto\n";
        return std::malloc(size); // Aloca com malloc
    }

    // Sobrecarga de delete para liberar memória de um único objeto
    static void operator delete(void *ptr)
    {
        std::cout << "Liberando memória de um objeto\n";
        std::free(ptr); // Libera com free
    }

    // Sobrecarga de new[] para alocar memória para um array
    static void *operator new[](std::size_t size)
    {
        std::cout << "Alocando " << size << " bytes para um array\n";
        return std::malloc(size); // Aloca com malloc
    }

    // Sobrecarga de delete[] para liberar memória de um array
    static void operator delete[](void *ptr)
    {
        std::cout << "Liberando memória de um array\n";
        std::free(ptr); // Libera com free
    }

    // Acesso aos dados do buffer
    T &operator[](std::size_t index)
    {
        return dados[index]; // Acesso normal ao buffer
    }
};

int main(int argc, char **argv)
{
    // Criando um buffer para 5 inteiros
    Buffer<int> *buffer = new Buffer<int>(5);

    // Atribuindo valores ao buffer
    for (int i = 0; i < 5; ++i)
    {
        (*buffer)[i] = i * 10;
    }

    // Exibindo os valores do buffer
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "buffer[" << i << "] = " << (*buffer)[i] << '\n';
    }

    // Liberando a memória do buffer
    delete buffer;

    // Criando um array de buffers para 3 buffers de 4 elementos
    Buffer<int> *buffers = new Buffer<int>[3]{{4}, {4}, {4}};

    // Atribuindo valores aos buffers
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            buffers[i][j] = i * 10 + j;
        }
    }

    // Exibindo os valores dos buffers
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << "buffers[" << i << "][" << j << "] = " << buffers[i][j] << '\n';
        }
    }

    // Liberando a memória do array de buffers
    delete[] buffers;

    return 0;
}
