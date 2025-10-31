#ifndef GRAFO_HPP
#define GRAFO_HPP

/**
 * @class Grafo
 * @brief Representa um grafo simples, não direcionado, usando matriz de adjacência.
 */
class Grafo
{
private:
    int numVertices;   ///< Número de vértices no grafo.
    bool **adjacencia; ///< Matriz de adjacência representando as arestas do grafo.

public:
    /**
     * @brief Construtor da classe Grafo.
     * 
     * @param n Número de vértices do grafo.
     */
    Grafo(int n);

    /**
     * @brief Destrutor da classe Grafo.
     */
    ~Grafo();

    /**
     * @brief Adiciona uma aresta ao grafo.
     * 
     * @param origem Vértice de origem da aresta.
     * @param destino Vértice de destino da aresta.
     */
    void adicionarAresta(int origem, int destino);

    /**
     * @brief Verifica se cada vértice está interligado com todos os outros vértices.
     */
    void verificarInterligacaoTotal();
};

#endif
