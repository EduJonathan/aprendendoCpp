#include <algorithm>
#include "lis.hpp"

LargestIndependentSet::Node::Node(int x) : dado(x), liss(0), left(nullptr), right(nullptr) {}
LargestIndependentSet::LargestIndependentSet() : root(nullptr) {}

void LargestIndependentSet::construirExemplo(void)
{
    root = std::make_unique<Node>(10);
    root->left = std::make_unique<Node>(20);
    root->right = std::make_unique<Node>(30);
    root->left->left = std::make_unique<Node>(40);
    root->right->left = std::make_unique<Node>(50);
    root->right->right = std::make_unique<Node>(60);
}

int LargestIndependentSet::calcularLIS(void)
{
    return Liss(root.get());
}

int LargestIndependentSet::Liss(Node *node)
{
    if (!node)
        return 0;

    // Retorna valor memoizado
    if (node->liss != 0)
        return node->liss;

    // Nó folha
    if (!node->left && !node->right)
        return (node->liss = 1);

    // Excluindo o nó atual
    int excluindo = Liss(node->left.get()) + Liss(node->right.get());

    // Incluindo o nó atual
    int incluindo = 1;

    if (node->left)
    {
        incluindo += Liss(node->left->left.get());
        incluindo += Liss(node->left->right.get());
    }

    if (node->right)
    {
        incluindo += Liss(node->right->left.get());
        incluindo += Liss(node->right->right.get());
    }

    node->liss = std::max(incluindo, excluindo);
    return node->liss;
}

int main(int argc, char **argv)
{
    LargestIndependentSet lis;
    lis.construirExemplo();

    std::cout << "Tamanho do maior conjunto independente: " << lis.calcularLIS() << '\n';

    // Não se preocupar com delete, o unique_ptr irá fazer automaticamente.
    return 0;
}
