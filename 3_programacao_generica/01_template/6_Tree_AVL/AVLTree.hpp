#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>

template <class Comparable>
class AVLTree;

template <class Comparable>
class AVLNode
{
public:
    Comparable element;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(const Comparable &theElement, AVLNode *lt = nullptr, AVLNode *rt = nullptr, int h = 0)
        : element{theElement}, left{lt}, right{rt}, height{h} {}

    friend class AVLTree<Comparable>;
};

template <class Comparable>
class AVLTree
{
public:
    explicit AVLTree(const Comparable &notFound);
    AVLTree(const AVLTree &rhs);
    ~AVLTree();

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    const Comparable &find(const Comparable &x) const;
    bool isEmpty() const;
    void printTree() const;

    void makeEmpty();
    void insert(const Comparable &x);
    void remove(const Comparable &x);

    const AVLTree &operator=(const AVLTree &rhs);
    void printTreePretty() const;

private:
    void printTreePretty(AVLNode<Comparable> *node, const std::string &prefix, bool isLeft) const;
    AVLNode<Comparable> *root;
    const Comparable ITEM_NOT_FOUND;

    const Comparable &elementAt(AVLNode<Comparable> *t) const;
    void insert(const Comparable &x, AVLNode<Comparable> *&t);
    AVLNode<Comparable> *findMin(AVLNode<Comparable> *t) const;
    AVLNode<Comparable> *findMax(AVLNode<Comparable> *t) const;
    AVLNode<Comparable> *find(const Comparable &x, AVLNode<Comparable> *t) const;
    void makeEmpty(AVLNode<Comparable> *&t);
    void printTree(AVLNode<Comparable> *t) const;

    int height(AVLNode<Comparable> *t) const;
    int max(int lhs, int rhs) const;
    void rotateWithLeftChild(AVLNode<Comparable> *&k2);
    void rotateWithRightChild(AVLNode<Comparable> *&k1);
    void doubleWithLeftChild(AVLNode<Comparable> *&k3);
    void doubleWithRightChild(AVLNode<Comparable> *&k1);

    AVLNode<Comparable> *clone(AVLNode<Comparable> *t) const;
};

#include "AVLTree.tpp"

#endif // AVLTREE_H
