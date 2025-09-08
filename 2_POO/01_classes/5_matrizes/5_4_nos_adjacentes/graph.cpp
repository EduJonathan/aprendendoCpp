#include <iostream>
#include <climits>
#include <memory>
#include <vector>
#include "class_graph.hpp"

Graph::Graph(int numVertices) : nVertices(numVertices),
                                adj(std::make_unique<std::list<AdjacenteListNode>[]>(numVertices)) {}

void Graph::adicionarArestas(int u, int v, int peso) { adj[u].emplace_back(v, peso); }

void Graph::topologicalSortUtil(int v, bool visited[], std::stack<int> &stack)
{
    visited[v] = true; // Marca o nó atual como visitado

    for (const auto &no : adj[v])
    {
        if (!visited[no.getVertice()])
        {
            topologicalSortUtil(no.getVertice(), visited, stack);
        }
    }
    stack.push(v);
}

void Graph::maiorCaminho(int src)
{
    std::stack<int> stack;

    // Usando std::vector ao invés de um array de tamanho variável
    std::vector<int> destinos(nVertices, INT_MIN);
    std::unique_ptr<bool[]> visited = std::make_unique<bool[]>(nVertices);

    for (int i = 0; i < nVertices; ++i)
        visited[i] = false;

    for (int i = 0; i < nVertices; ++i)
    {
        if (!visited[i])
            topologicalSortUtil(i, visited.get(), stack);
    }

    destinos[src] = 0; // Distância do nó de origem para ele mesmo é sempre 0

    while (!stack.empty())
    {
        int v = stack.top(); // Pega o vértice do topo da pilha
        stack.pop();         // Remove o vértice do topo da pilha

        if (destinos[v] != INT_MIN)
        {
            for (const auto &i : adj[v])
            {
                int destino = i.getVertice(); // Vértice de destino
                int peso = i.getPeso();       // Peso da aresta

                if (destinos[v] + peso > destinos[destino])
                {
                    // Atualiza o caminho mais longo para o destino
                    destinos[destino] = destinos[v] + peso;
                }
            }
        }
    }

    for (int i = 0; i < nVertices; ++i)
    {
        if (destinos[i] == INT_MIN)
        {
            std::cout << "INF ";
        }
        else
        {
            std::cout << destinos[i] << ' ';
        }
    }
    std::cout << '\n';
}
