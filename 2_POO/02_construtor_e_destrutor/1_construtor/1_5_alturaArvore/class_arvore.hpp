#ifndef CLASS_ARVORE_HPP
#define CLASS_ARVORE_HPP

#include <memory>
#include <vector>
#include <map>

/**
 * @brief Estrutura que representa um nó da árvore binária.
 */
struct TreeNode
{
    int val;                         ///< Valor do nó
    std::unique_ptr<TreeNode> left;  ///< Ponteiro para o filho à esquerda
    std::unique_ptr<TreeNode> right; ///< Ponteiro para o filho à direita

    /**
     * @brief Construtor que inicializa o nó com um valor.
     * 
     * @param x Valor do nó
     */
    TreeNode(int x);
};

/**
 * @brief Classe para manipulação e consulta de uma árvore binária.
 */
class Tree
{
public:
    std::map<int, int> left;       ///< Mapa para armazenar as alturas das subárvores esquerdas.
    std::map<int, int> right;      ///< Mapa para armazenar as alturas das subárvores direitas.
    std::map<int, int> max_height; ///< Mapa para armazenar as alturas máximas propagadas.

    /**
     * @brief Calcula a altura da árvore binária.
     *
     * A altura de um nó é definida como o número máximo de arestas entre esse nó e uma folha.
     * A altura de uma folha é 1.
     *
     * @param root Ponteiro para o nó raiz da árvore.
     * @return A altura da árvore, considerando o maior número de arestas entre o nó e uma folha.
     */
    int calcularAltura(TreeNode *root);

    /**
     * @brief Calcula a altura máxima considerando os nós acima do nó atual.
     *
     * Esta função propaga a altura máxima até o nó, levando em consideração o máximo
     * da profundidade dos nós acima do nó atual. Utiliza recursão para os filhos da árvore.
     *
     * @param root Ponteiro para o nó atual da árvore.
     * @param maxAbove A maior altura calculada acima do nó atual (do nó pai).
     * @param depth A profundidade do nó atual na árvore (distância desde a raiz).
     */
    void heightMap(TreeNode *root, int maxAbove, int depth);

    /**
     * @brief Realiza as consultas para obter a altura máxima de cada nó na árvore.
     *
     * Para cada nó especificado nas consultas, retorna a altura máxima associada
     * ao nó, considerando as subárvores e a altura máxima propagada dos nós acima.
     *
     * @param root Ponteiro para o nó raiz da árvore.
     * @param queries Vetor de inteiros contendo os valores dos nós a serem consultados.
     * @return Um vetor de inteiros com as respostas para as consultas.
     */
    std::vector<int> treeQueries(TreeNode *root, std::vector<int> &queries);
};

#endif // CLASS_ARVORE_HPP
