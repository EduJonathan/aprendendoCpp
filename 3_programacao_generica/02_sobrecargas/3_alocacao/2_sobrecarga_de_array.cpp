#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <new>

class Array
{
private:
    std::unique_ptr<int[]> dados; // Array gerenciado por unique_ptr
    std::size_t size;

public:
    // Construtor para inicializar o array com 10 elementos
    Array() : dados(std::make_unique<int[]>(10)), size(10)
    {
        // Inicializa os valores do array com 0
        std::fill(dados.get(), dados.get() + size, 0);
    }

    // Sobrecarga do operador [] para acessar ou modificar elementos
    int &operator[](int indice)
    {
        if (indice < 0 || indice >= size)
        {
            throw std::out_of_range("Índice fora do limite!");
        }
        return dados[indice];
    }

    // Função para adicionar um valor em uma posição específica
    void adicionar(int valor, int indice)
    {
        if (indice < 0 || indice >= size)
        {
            throw std::out_of_range("Índice fora do limite!");
        }
        dados[indice] = valor;
    }

    // Função para remover um valor de uma posição específica (substitui o valor por 0)
    void remover(int indice)
    {
        if (indice < 0 || indice >= size)
        {
            throw std::out_of_range("Índice fora do limite!");
        }
        dados[indice] = 0; // Pode substituir por qualquer valor indicativo de "vazio"
    }

    // Função para alterar o valor de um elemento
    void alterar(int valor, int indice)
    {
        if (indice < 0 || indice >= size)
        {
            throw std::out_of_range("Índice fora do limite!");
        }
        dados[indice] = valor;
    }

    // Função para ordenar o array em ordem crescente
    void ordenar()
    {
        std::sort(dados.get(), dados.get() + size);
    }

    // Função para mover um valor de um índice para outro
    void mover(int origem, int destino)
    {
        if (origem < 0 || origem >= size || destino < 0 || destino >= size)
        {
            throw std::out_of_range("Índice fora do limite!");
        }
        dados[destino] = dados[origem];
        dados[origem] = 0; // Substitui o valor original por 0 (ou qualquer valor indicativo de "vazio")
    }

    // Função para imprimir o array
    void imprimir() const
    {
        for (std::size_t i{0}; i < size; ++i)
        {
            std::cout << dados[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main(int argc, char **argv)
{
    try
    {
        Array *arr = new Array();
        arr->adicionar(10, 0);
        arr->adicionar(20, 1);
        arr->adicionar(30, 2);
        arr->adicionar(40, 3);
        arr->adicionar(50, 4);

        std::cout << "Array inicial: ";
        arr->imprimir();

        // Alterando valor na posição 2
        arr->alterar(99, 2);

        std::cout << "Após alteração na posição 2: ";
        arr->imprimir();

        // Removendo valor na posição 3
        arr->remover(3);

        std::cout << "Após remoção na posição 3: ";
        arr->imprimir();

        // Ordenando o array
        arr->ordenar();

        std::cout << "Após ordenação: ";
        arr->imprimir();

        // Movendo valor da posição 0 para a posição 5
        arr->mover(0, 5);

        std::cout << "Após mover da posição 0 para a posição 5: ";
        arr->imprimir();
    }
    catch (const std::exception &e)
    {
        std::cout << "Erro: " << e.what() << '\n';
    }

    return 0;
}
