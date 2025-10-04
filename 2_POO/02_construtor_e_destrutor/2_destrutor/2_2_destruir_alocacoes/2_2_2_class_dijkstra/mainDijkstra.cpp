#include <iostream>
#include <memory>
#include "class_graph.hpp"

int main(int argc, char **argv)
{
    int Vertices = 0;
    std::cout << "Digite o número de vértices: ";
    std::cin >> Vertices;

    if (Vertices <= 0)
    {
        std::cerr << "O número de vértices deve ser maior que 0!\n";
        return 1;
    }

    // Usando smart pointer para gerenciar a memória automaticamente
    std::unique_ptr<Graph> grafo = std::make_unique<Graph>(Vertices);

    int Edges = 0;
    std::cout << "Digite o número de arestas: ";
    std::cin >> Edges;

    if (Edges < 0)
    {
        std::cerr << "O número de arestas não pode ser negativo!\n";
        return 1;
    }

    for (int i = 0; i < Edges; ++i)
    {
        int source = 0, destination = 0, weight = 0;

        std::cout << "\nAresta " << i + 1 << "\nDigite o vértice de origem (0 a " << Vertices - 1 << "): ";
        std::cin >> source;

        std::cout << "Digite o vértice de destino (0 a " << Vertices - 1 << "): ";
        std::cin >> destination;

        std::cout << "Digite o peso da aresta: ";
        std::cin >> weight;

        if (source >= 0 && source < Vertices && destination >= 0 && destination < Vertices)
        {
            grafo->adicionarEdge(source, destination, weight);
        }
        else
        {
            std::cerr << "Vértices fora do intervalo válido. Tente novamente.\n";
            --i;
        }
    }

    int origem = 0;
    std::cout << "\nDigite o vértice de origem para o algoritmo de Dijkstra (0 a " << Vertices - 1 << "): ";
    std::cin >> origem;

    if (origem < 0 || origem >= Vertices)
    {
        std::cerr << "O vértice de origem está fora do intervalo válido!\n";
        return 1;
    }

    grafo->dijkstra(origem); // Executa o algoritmo de Dijkstra

    // Smart pointer automaticamente libera a memória ao sair do escopo

    /**
     * Compile e execute o programa com:
     * > g++ -std=c++17 mainDijkstra.cpp Dijkstras.cpp -o nome_do_executavel
     * > ./nome_do_executavel
     */
    return 0;
}
