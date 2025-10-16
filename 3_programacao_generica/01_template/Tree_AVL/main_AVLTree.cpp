#include "AVLTree.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    AVLTree<int> tree;
    std::cout << "Árvore vazia:\n"
              << tree.toString() << '\n';

    tree.addValue(10);
    tree.addValue(5);
    tree.addValue(15);
    tree.addValue(3);
    tree.addValue(7);

    std::cout << "Após inserções:\n"
              << tree.toString() << '\n';

    tree.removeValue(5);
    std::cout << "Após remover 5:\n"
              << tree.toString() << '\n';

    tree.removeValue(10);
    std::cout << "Após remover 10:\n"
              << tree.toString() << '\n';

    return 0;
}
