#include "AVLTree.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    AVLTree<int> t(-1); // -1 será ITEM_NOT_FOUND
    t.insert(20);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(15);
    t.insert(25);
    t.insert(35);

    std::cout << "Árvore (ordem):\n";
    t.printTreePretty();

    std::cout << "\nMin: " << t.findMin() << '\n';
    std::cout << "Max: " << t.findMax() << '\n';

    t.remove(10);
    std::cout << "\nApós remover 10:\n";
    t.printTreePretty();

    return 0;
}
