#ifndef AVLTREE_TPP
#define AVLTREE_TPP

#include "AVLTree.hpp"
#include <new>
#include <functional>
#include <algorithm>
#include <stdexcept>

template <class Comparable>
AVLTree<Comparable>::AVLTree(const Comparable &notFound) : root{nullptr}, ITEM_NOT_FOUND{notFound} {}

template <class Comparable>
AVLTree<Comparable>::AVLTree(const AVLTree &rhs) : ITEM_NOT_FOUND{rhs.ITEM_NOT_FOUND}, root{nullptr}
{
    *this = rhs;
}

template <class Comparable>
AVLTree<Comparable>::~AVLTree()
{
    makeEmpty();
}

template <class Comparable>
const Comparable &AVLTree<Comparable>::elementAt(AVLNode<Comparable> *t) const
{
    return t == nullptr ? ITEM_NOT_FOUND : t->element;
}

template <class Comparable>
bool AVLTree<Comparable>::isEmpty() const
{
    return root == nullptr;
}

template <class Comparable>
void AVLTree<Comparable>::makeEmpty()
{
    makeEmpty(root);
}

template <class Comparable>
void AVLTree<Comparable>::makeEmpty(AVLNode<Comparable> *&t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }
}

template <class Comparable>
const Comparable &AVLTree<Comparable>::findMin() const
{
    return elementAt(findMin(root));
}

template <class Comparable>
const Comparable &AVLTree<Comparable>::findMax() const
{
    return elementAt(findMax(root));
}

template <class Comparable>
AVLNode<Comparable> *AVLTree<Comparable>::findMin(AVLNode<Comparable> *t) const
{
    if (t == nullptr)
    {
        return nullptr;
    }
    while (t->left != nullptr)
    {
        t = t->left;
    }
    return t;
}

template <class Comparable>
AVLNode<Comparable> *AVLTree<Comparable>::findMax(AVLNode<Comparable> *t) const
{
    if (t == nullptr)
    {
        return nullptr;
    }
    while (t->right != nullptr)
    {
        t = t->right;
    }
    return t;
}

template <class Comparable>
const Comparable &AVLTree<Comparable>::find(const Comparable &x) const
{
    return elementAt(find(x, root));
}

template <class Comparable>
AVLNode<Comparable> *AVLTree<Comparable>::find(const Comparable &x, AVLNode<Comparable> *t) const
{
    if (t == nullptr)
    {
        return nullptr;
    }
    if (x < t->element)
    {
        return find(x, t->left);
    }
    else if (t->element < x)
    {
        return find(x, t->right);
    }
    else
    {
        return t; // match
    }
}

template <class Comparable>
void AVLTree<Comparable>::printTree() const
{
    if (isEmpty())
    {
        std::cout << "Empty tree\n";
    }
    else
    {
        printTree(root);
    }
}

template <class Comparable>
void AVLTree<Comparable>::printTreePretty() const
{
    if (root == nullptr)
    {
        std::cout << "<empty tree>\n";
        return;
    }

    printTreePretty(root, "", false);
}

template <class Comparable>
void AVLTree<Comparable>::printTreePretty(AVLNode<Comparable> *node, const std::string &prefix, bool isLeft) const
{
    if (node == nullptr)
        return;

    // prefixo e conector
    std::cout << prefix;

    if (prefix != "")
    {
        std::cout << (isLeft ? "├── " : "└── ");
    }

    // imprime o nó atual
    std::cout << "[" << node->element << "]\n";

    // prepara prefixos para filhos
    std::string nextPrefix = prefix + (isLeft ? "│   " : "    ");

    // esquerda vem antes para ficar visualmente correto
    if (node->left != nullptr || node->right != nullptr)
    {
        printTreePretty(node->left, nextPrefix, true);
        printTreePretty(node->right, nextPrefix, false);
    }
}

template <class Comparable>
int AVLTree<Comparable>::height(AVLNode<Comparable> *t) const
{
    return t == nullptr ? -1 : t->height;
}

template <class Comparable>
int AVLTree<Comparable>::max(int lhs, int rhs) const
{
    return lhs > rhs ? lhs : rhs;
}

template <class Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode<Comparable> *&k2)
{
    AVLNode<Comparable> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    // atualiza alturas
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template <class Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode<Comparable> *&k1)
{
    AVLNode<Comparable> *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    // atualiza alturas
    k1->height = std::max(height(k1->left), height(k1->right)) + 1;
    k2->height = std::max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

template <class Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode<Comparable> *&k3)
{
    // rotaciona k3->left para a esquerda, depois com k3 para a direita
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template <class Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode<Comparable> *&k1)
{
    // rotaciona k1->right para a direita, depois com k1 para a esquerda
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

template <class Comparable>
void AVLTree<Comparable>::insert(const Comparable &x)
{
    insert(x, root);
}

template <class Comparable>
void AVLTree<Comparable>::insert(const Comparable &x, AVLNode<Comparable> *&t)
{
    if (t == nullptr)
    {
        // cria novo nó corretamente
        t = new AVLNode<Comparable>(x, nullptr, nullptr, 0);
    }
    else if (x < t->element)
    {
        insert(x, t->left);

        if (height(t->left) - height(t->right) == 2)
        {
            if (x < t->left->element)
            {
                rotateWithLeftChild(t);
            }
            else
            {
                doubleWithLeftChild(t);
            }
        }
    }
    else if (t->element < x)
    {
        insert(x, t->right);

        if (height(t->right) - height(t->left) == 2)
        {
            if (t->right->element < x)
            {
                rotateWithRightChild(t);
            }
            else
            {
                doubleWithRightChild(t);
            }
        }
    }
    else
    {
        // elemento já existe — aqui não fazemos nada (ou poderia atualizar)
    }

    t->height = std::max(height(t->left), height(t->right)) + 1;
}

template <class Comparable>
void AVLTree<Comparable>::remove(const Comparable &x)
{
    // wrapper
    AVLNode<Comparable> *&t = root;

    // chamada recursiva inline:
    std::function<void(AVLNode<Comparable> *&, const Comparable &)> removeRec;
    removeRec = [&](AVLNode<Comparable> *&tnode, const Comparable &value)
    {
        if (tnode == nullptr)
            return; // não está presente
        if (value < tnode->element)
        {
            removeRec(tnode->left, value);
            
            // re-balance
            if (height(tnode->right) - height(tnode->left) == 2)
            {
                AVLNode<Comparable> *r = tnode->right;
                if (height(r->right) >= height(r->left))
                {
                    rotateWithRightChild(tnode);
                }
                else
                {
                    doubleWithRightChild(tnode);
                }
            }
        }
        else if (tnode->element < value)
        {
            removeRec(tnode->right, value);

            // re-balance
            if (height(tnode->left) - height(tnode->right) == 2)
            {
                AVLNode<Comparable> *l = tnode->left;
                if (height(l->left) >= height(l->right))
                {
                    rotateWithLeftChild(tnode);
                }
                else
                {
                    doubleWithLeftChild(tnode);
                }
            }
        }
        else // found
        {
            if (tnode->left != nullptr && tnode->right != nullptr) // two children
            {
                AVLNode<Comparable> *minRight = findMin(tnode->right);
                tnode->element = minRight->element;
                removeRec(tnode->right, tnode->element);
            }
            else
            {
                AVLNode<Comparable> *oldNode = tnode;
                tnode = (tnode->left != nullptr) ? tnode->left : tnode->right;
                delete oldNode;
            }
        }
        if (tnode != nullptr)
            tnode->height = std::max(height(tnode->left), height(tnode->right)) + 1;
    };

    removeRec(root, x);
}

template <class Comparable>
AVLNode<Comparable> *AVLTree<Comparable>::clone(AVLNode<Comparable> *t) const
{
    if (t == nullptr)
        return nullptr;
    AVLNode<Comparable> *newNode = new AVLNode<Comparable>(t->element, nullptr, nullptr, t->height);
    newNode->left = clone(t->left);
    newNode->right = clone(t->right);
    return newNode;
}

template <class Comparable>
const AVLTree<Comparable> &AVLTree<Comparable>::operator=(const AVLTree &rhs)
{
    if (this != &rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
    }
    return *this;
}

#endif // AVLTREE_TPP
