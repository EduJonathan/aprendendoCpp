#ifndef CLASS_ADJACENTE_NODE_HPP
#define CLASS_ADJACENTE_NODE_HPP

/**
 * @class AdjacenteListNode
 * @brief Representa um nó na lista de adjacência de um grafo.
 *
 * Armazena informações sobre o vértice de destino e o peso da aresta.
 */
class AdjacenteListNode
{
private:
    int vertice; ///< Vértice de destino da aresta.
    int peso;    ///< Peso da aresta.

public:
    /**
     * @brief Construtor que inicializa o nó da lista de adjacência.
     *
     * @param vertex Vértice de destino da aresta.
     * @param weight Peso da aresta.
     */
    AdjacenteListNode(int vertex, int weight);

    /**
     * @brief Retorna o vértice de destino da aresta.
     *
     * @return Vértice de destino.
     */
    int getVertice() const;

    /**
     * @brief Retorna o peso da aresta.
     *
     * @return Peso da aresta.
     */
    int getPeso() const;
};

#endif
