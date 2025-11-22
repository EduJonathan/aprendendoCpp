#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>

struct Graph
{
    using Edge = std::pair<int, int>;             // Aresta: (vértice destino, peso)
    using Grafo = std::vector<std::vector<Edge>>; // Lista de adjacência
    Grafo g;                                      // Membro para armazenar o grafo
    Graph(int n) : g(n) {}                        // Construtor para inicializar com n vértices
};

// Valor grande para representar infinito, evitando overflow
const int INF = std::numeric_limits<int>::max() / 2;

/**
 * @brief Executa o algoritmo de Bellman-Ford para encontrar o caminho mais curto
 * a partir de um vértice fonte.
 *
 * @param grafo O grafo representado como uma lista de adjacência.
 * @param source O vértice fonte.
 * @param priority Vetor para armazenar as distâncias mínimas.
 * @param predecessor Vetor para armazenar os predecessores dos vértices.
 * @return true se um ciclo negativo for detectado, false caso contrário.
 */
bool bellmanFord(const Graph &grafo, int source, std::vector<int> &priority, std::vector<int> &predecessor)
{
    int n = grafo.g.size();    // Número de vértices
    priority.assign(n, INF);   // Inicializa todas as distâncias como infinito
    predecessor.assign(n, -1); // Inicializa predecessores como -1
    priority[source] = 0;      // Distância da fonte para ela mesma é 0
    bool alterado = false;     // Flag para verificar se houve alteração nas distâncias

    // Relaxamento das arestas (n-1 iterações)
    for (int i = 0; i < n - 1; ++i)
    {
        alterado = false;

        for (int u = 0; u < n; ++u)
        {
            for (const auto &edge : grafo.g[u])
            {
                int v = edge.first;       // Vértice destino
                int weight = edge.second; // Peso da aresta

                if (priority[u] != INF && priority[u] + weight < priority[v])
                {
                    priority[v] = priority[u] + weight;
                    predecessor[v] = u;
                    alterado = true;
                }
            }
        }

        if (!alterado)
            break; // Otimização: sai se não houver mudanças
    }

    // Verifica ciclo negativo
    for (int u = 0; u < n; ++u)
    {
        for (const auto &edge : grafo.g[u])
        {
            int v = edge.first;       // Vértice destino
            int weight = edge.second; // Peso da aresta

            if (priority[u] != INF && priority[u] + weight < priority[v])
            {
                return true; // Ciclo negativo detectado
            }
        }
    }
    return false;
}

/**
 * @brief Encontra um ciclo negativo no grafo, se existir.
 *
 * @param grafo O grafo representado como uma lista de adjacência.
 * @return Um vetor contendo os vértices do ciclo negativo, ou vazio se não houver
 */
std::vector<int> find_negative_cycle(const Graph &grafo)
{
    int n = grafo.g.size();              // Número de vértices
    std::vector<int> priority(n, INF);   // Inicializa todas as distâncias como infinito
    std::vector<int> predecessor(n, -1); // Inicializa predecessores como -1
    priority[0] = 0;                     // Começa do vértice 0
    int last = -1;                       // Último vértice atualizado

    // Executa Bellman-Ford para detectar ciclo
    for (int i = 0; i < n; ++i)
    {
        last = -1; // Reseta last a cada iteração

        for (int u = 0; u < n; ++u)
        {
            for (const auto &edge : grafo.g[u])
            {
                int v = edge.first;
                int weight = edge.second;

                if (priority[u] != INF && priority[u] + weight < priority[v])
                {
                    priority[v] = priority[u] + weight;
                    predecessor[v] = u;
                    last = v;
                }
            }
        }
    }

    if (last == -1)
        return {}; // Sem ciclo negativo

    // Reconstrói o ciclo
    std::vector<int> cycle;
    int v = last;

    for (int i = 0; i < n; ++i)
        v = predecessor[v]; // Avança até encontrar o ciclo

    int start = v; // Vértice inicial do ciclo

    do
    {
        cycle.push_back(v);
        v = predecessor[v];
    } while (v != start || cycle.size() == 1);

    std::reverse(cycle.begin(), cycle.end());
    return cycle;
}

int main(int argc, char **argv)
{
    int n = 4;      // Número de vértices
    Graph grafo(n); // Grafo com 4 vértices

    // Adiciona arestas: (origem, {destino, peso})
    grafo.g[0].push_back(std::make_pair(1, 1));
    grafo.g[1].push_back(std::make_pair(2, -1));
    grafo.g[2].push_back(std::make_pair(3, -1));
    grafo.g[3].push_back(std::make_pair(1, -1)); // Ciclo negativo: 1 -> 2 -> 3 -> 1

    std::vector<int> priority, predecessor;
    bool has_cycle = bellmanFord(grafo, 0, priority, predecessor);
    std::cout << "Ciclo negativo? " << (has_cycle ? "Sim" : "Não") << '\n';

    auto cycle = find_negative_cycle(grafo);

    if (!cycle.empty())
    {
        std::cout << "Ciclo negativo encontrado: ";
        for (int v : cycle)
            std::cout << v << ' ';
        std::cout << '\n';
    }
    else
    {
        std::cout << "Nenhum ciclo negativo encontrado.\n";
    }
    return 0;
}
