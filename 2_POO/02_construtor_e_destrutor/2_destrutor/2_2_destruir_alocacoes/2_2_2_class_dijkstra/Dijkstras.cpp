#include <string>
#include <queue>
#include <limits>
#include "class_graph.hpp"

Graph::Graph(int v) : vertice(v), adjList(v)
{
    // Inicializa a lista de adjacência com V vetores vazios
}

void Graph::adicionarEdge(int source, int destination, int weight)
{
    adjList[source].emplace_back(destination, weight);
}

void Graph::dijkstra(int source) const
{
    std::vector<int> minDist(vertice, std::numeric_limits<int>::max());
    std::vector<bool> visitado(vertice, false);

    using pii = std::pair<int, int>; // (distância, vértice)
    std::priority_queue<pii, std::vector<pii>, std::greater<>> filaPrioridade;

    minDist[source] = 0;
    filaPrioridade.emplace(0, source);

    while (!filaPrioridade.empty())
    {
        auto [dist, u] = filaPrioridade.top();
        filaPrioridade.pop();

        if (visitado[u])
            continue;

        visitado[u] = true;

        for (const auto &[v, peso] : adjList[u])
        {
            if (!visitado[v] && dist + peso < minDist[v])
            {
                minDist[v] = dist + peso;
                filaPrioridade.emplace(minDist[v], v);
            }
        }
    }

    std::cout << "\nVértice \tDistância\n";
    for (int i = 0; i < vertice; ++i)
    {
        std::cout << i << " \t\t" << (minDist[i] == std::numeric_limits<int>::max() ? "INF" : std::to_string(minDist[i])) << '\n';
    }
}

// O destrutor padrão é suficiente, pois não há alocação dinâmica manual.
Graph::~Graph() = default;