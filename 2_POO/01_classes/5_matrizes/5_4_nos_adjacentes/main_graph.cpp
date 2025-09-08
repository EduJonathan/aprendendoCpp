#include <iostream>
#include "class_graph.hpp"

int main(int argc, char **argv)
{
    // Criação de um grafo com 6 vértices
    Graph grafo(6);

    // Adicionando arestas ao grafo
    grafo.adicionarArestas(0, 1, 5);
    grafo.adicionarArestas(0, 2, 3);
    grafo.adicionarArestas(1, 3, 6);
    grafo.adicionarArestas(1, 2, 2);
    grafo.adicionarArestas(2, 4, 4);
    grafo.adicionarArestas(2, 5, 2);
    grafo.adicionarArestas(2, 3, 7);
    grafo.adicionarArestas(3, 5, -1);
    grafo.adicionarArestas(3, 4, -1);
    grafo.adicionarArestas(4, 5, -2);

    int caminho = 4;
    std::cout << "A maior distancia do vertice: " << caminho << '\n';
    grafo.maiorCaminho(caminho);

    /**
     * Compile e execute o programa com:
     * > g++ .\main_graph.cpp .\graph.cpp .\adjacente_node.cpp -std=c++17 -o graph
     * ./graph.exe
     */
    return 0;
}
