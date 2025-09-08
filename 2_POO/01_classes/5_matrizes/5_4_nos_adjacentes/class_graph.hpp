#ifndef CLASS_GRAPH_HPP
#define CLASS_GRAPH_HPP

#include <list>
#include <stack>
#include <memory>
#include "adjacente_node.hpp"

/**
 * @class Graph
 * @brief Representa um grafo direcionado com pesos.
 */
class Graph
{
private:
    int nVertices;                                       ///< Número de vértices.
    std::unique_ptr<std::list<AdjacenteListNode>[]> adj; ///< Lista de adjacência.

    /**
     * @brief Função auxiliar recursiva para ordenação topológica.
     *
     * @param v Vértice atual.
     * @param visited Vetor de visitados.
     * @param stack Pilha de ordenação.
     */
    void topologicalSortUtil(int v, bool visited[], std::stack<int> &stack);

public:
    /**
     * @brief Construtor da classe Graph.
     *
     * @param nVertices Número de vértices.
     */
    Graph(int nVertices);

    /**
     * @brief Destrutor (default).
     */
    ~Graph() = default;

    /**
     * @brief Adiciona uma aresta direcionada com peso.
     *
     * @param u Vértice de origem.
     * @param v Vértice de destino.
     * @param peso Peso da aresta.
     */
    void adicionarArestas(int u, int v, int peso);

    /**
     * @brief Calcula e imprime o maior caminho a partir de um vértice.
     *
     * @param src Vértice de origem.
     */
    void maiorCaminho(int src);
};

#endif
