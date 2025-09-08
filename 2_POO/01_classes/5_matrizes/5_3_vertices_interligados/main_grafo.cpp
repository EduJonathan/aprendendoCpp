#include "class_grafo.hpp"

Grafo::Grafo(int n) : numVertices(n)
{
    adjacencia = new bool *[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        adjacencia[i] = new bool[n + 1];
        for (int j = 0; j <= n; ++j)
        {
            adjacencia[i][j] = false;
        }
    }
}

Grafo::~Grafo()
{
    for (int i = 0; i <= numVertices; ++i)
    {
        delete[] adjacencia[i];
    }
    delete[] adjacencia;
}

void Grafo::adicionarAresta(int origem, int destino)
{
    if (origem >= 1 && origem <= numVertices && destino >= 1 && destino <= numVertices)
    {
        adjacencia[origem][destino] = true;
    }
    else
    {
        std::cout << "Aresta invalida: " << origem << " -> " << destino << '\n';
    }
}

void Grafo::verificarInterligacaoTotal()
{
    for (int u = 1; u <= numVertices; ++u)
    {
        bool conectadoATodos = true;

        for (int v = 1; v <= numVertices; ++v)
        {
            if (!adjacencia[u][v])
            {
                conectadoATodos = false;
                break;
            }
        }

        if (conectadoATodos)
        {
            std::cout << "O vertice " << u << " esta interligado com todos os vertices (inclusive ele mesmo)." << '\n';
        }
        else
        {
            std::cout << "O vertice " << u << " nao esta interligado com todos os outros vertices." << '\n';
        }
    }
}

int main(int argc, char **argv)
{
    Grafo grafo(4);

    // Adicionando arestas: 1->1, 1->2, 1->3, 1->4
    grafo.adicionarAresta(1, 1);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 4);

    // Verificando interligação de cada vértice
    grafo.verificarInterligacaoTotal();

    std::cout << "-------------------------" << '\n';

    // Criando grafo com 2 vértices
    Grafo graph(2);

    // Adicionando arestas válidas: 1->1, 1->2, 2->1, 2->2
    graph.adicionarAresta(1, 1);
    graph.adicionarAresta(1, 2);
    graph.adicionarAresta(2, 1);
    graph.adicionarAresta(2, 2);

    // Tentando adicionar uma aresta inválida (0,0), o que deve ser ignorado
    graph.adicionarAresta(0, 0); // Esta aresta é inválida
    graph.adicionarAresta(2, 2); // Aresta repetida, mas válida

    // Verificando interligação de cada vértice
    graph.verificarInterligacaoTotal();
    return 0;
}
