#include <iostream>
#include <cstring>
#include <cstdlib>

/**
 * std::qsort(): Organiza valores utilizando o algoritmo de ordenação Quick Sort.
 * std::bsearch(): Busca valores utilizando o algoritmo de busca Binary Search(Busca Binária).
 */

struct pack
{
    std::string itens;
    double peso;
};

// Itens de exemplo na mochila do explorador
pack MochilaDoExplorador[] = {
    {"Mapa", 0.90},
    {"Garrafa D'Agua", 10.50},
    {"Papel Higiênico", 0.30},
    {"Garfo", 0.45},
    {"Faca", 0.50},
    {"Facão", 1.45}};

/*
Função de comparação para ordenar por nome
int compararPorNome(const void *a, const void *b)
{
    pack *itemA = (pack *)a;
    pack *itemB = (pack *)b;
    return itemA->itens.compare(itemB->itens); // Compara pelo nome do item
}*/

// Função de comparação para ordenar por peso
int compararPorPeso(const void *a, const void *b)
{
    pack *itemA = (pack *)a;
    pack *itemB = (pack *)b;

    if (itemA->peso < itemB->peso)
    {
        return -1; // itemA tem menos peso
    }
    if (itemA->peso > itemB->peso)
    {
        return 1; // itemA tem mais peso
    }

    return 0; // mesmos pesos
}

// Função para organizar os itens utilizando qsort (por peso)
void organizarItensComQsort(pack itens[], std::size_t tamanho)
{
    std::qsort(itens, tamanho, sizeof(pack), compararPorPeso); // Ordena por peso
}

// Função de comparação para busca binária (por nome)
int compararPorNomeBusca(const void *a, const void *b)
{
    pack *itemA = (pack *)a;
    pack *itemB = (pack *)b;
    return itemA->itens.compare(itemB->itens); // Compara pelo nome do item
}

// Função para buscar um item utilizando busca binária
void BuscarItensComBsearch(pack itens[], std::size_t tamanho, const std::string &item)
{
    pack chaveBusca = {item, 0.0}; // Cria uma chave de busca com apenas o nome do item

    // Realiza a busca binária
    pack *resultado = (pack *)std::bsearch(&chaveBusca, itens, tamanho, sizeof(pack), compararPorNomeBusca);

    if (resultado != nullptr)
    {
        std::cout << "Item encontrado: " << resultado->itens << " com peso: " << resultado->peso << '\n';
    }
    else
    {
        std::cout << "Item não encontrado!" << '\n';
    }
}

int main(int argc, char **argv)
{
    std::size_t tamanho = sizeof(MochilaDoExplorador) / sizeof(MochilaDoExplorador[0]);

    // Organiza os itens na mochila
    organizarItensComQsort(MochilaDoExplorador, tamanho);

    // Exibe os itens organizados
    std::cout << "Itens organizados por nome:" << '\n';
    for (std::size_t i = 0ull; i < tamanho; ++i)
    {
        std::cout << MochilaDoExplorador[i].itens << " - " << MochilaDoExplorador[i].peso << " kg" << '\n';
    }

    // Exemplo de busca por um item
    std::string itemBusca = "Faca";
    std::cout << "\nBuscando o item '" << itemBusca << "'..." << '\n';
    BuscarItensComBsearch(MochilaDoExplorador, tamanho, itemBusca);

    return 0;
}
