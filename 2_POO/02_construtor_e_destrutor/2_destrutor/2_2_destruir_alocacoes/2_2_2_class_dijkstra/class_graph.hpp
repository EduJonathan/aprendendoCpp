#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

/**
 * @class Graph
 * @brief Representa um grafo direcionado com pesos nas arestas.
 */
class Graph
{
private:
    std::vector<std::vector<std::pair<int, int>>> adjList; // Lista de adjacência: adjList[u] = pares (v, peso)
    int vertice; // Número de vértices do grafo

public:
    /**
     * @brief Construtor do grafo.
     * @param v Número de vértices.
     */
    explicit Graph(int v);

    /**
     * @brief Adiciona uma aresta direcionada ao grafo.
     * @param source Vértice de origem.
     * @param destination Vértice de destino.
     * @param weight Peso da aresta.
     */
    void adicionarEdge(int source, int destination, int weight);

    /**
     * @brief Executa o algoritmo de Dijkstra a partir de um vértice origem.
     * @param source Vértice de origem.
     */
    void dijkstra(int source) const;

    // O destrutor padrão é suficiente, pois não há alocação dinâmica manual.
    ~Graph() = default;
};

#endif
