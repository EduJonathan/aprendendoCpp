#include <iostream>
#include <algorithm>
#include "class_arvore.hpp"

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

int Tree::calcularAltura(TreeNode *root)
{
    if (!root)
        return 0;

    int left_height = calcularAltura(root->left.get());
    int right_height = calcularAltura(root->right.get());

    left[root->val] = left_height;
    right[root->val] = right_height;

    return std::max(left_height, right_height) + 1;
}

void Tree::heightMap(TreeNode *root, int maxAbove, int depth)
{
    if (!root)
        return;

    max_height[root->val] = maxAbove;

    heightMap(root->left.get(), std::max(maxAbove, depth + right[root->val]), depth + 1);
    heightMap(root->right.get(), std::max(maxAbove, depth + left[root->val]), depth + 1);
}

std::vector<int> Tree::treeQueries(TreeNode *root, std::vector<int> &queries)
{
    int total = calcularAltura(root);

    heightMap(root->left.get(), right[root->val], 1);
    heightMap(root->right.get(), left[root->val], 1);

    std::vector<int> result;
    for (int consultas : queries)
    {
        result.push_back(max_height[consultas]);
    }
    return result;
}

int main(int argc, char **argv)
{
    Tree arvore;

    // Construção da árvore:
    //
    //         1
    //        / \
    //       2   3
    //      /   / \
    //     4   5   6

    auto root          = std::make_unique<TreeNode>(1);
    root->left         = std::make_unique<TreeNode>(2);
    root->right        = std::make_unique<TreeNode>(3);
    root->left->left   = std::make_unique<TreeNode>(4);
    root->right->left  = std::make_unique<TreeNode>(5);
    root->right->right = std::make_unique<TreeNode>(6);

    std::vector<int> consultas = {2, 3, 4, 5, 6};
    std::vector<int> resultados = arvore.treeQueries(root.get(), consultas);

    for (std::size_t i = 0ull; i < consultas.size(); ++i)
    {
        std::cout << "Altura máxima sem o nó " << consultas[i] << ": " << resultados[i] << '\n';
    }

    return 0;
}
