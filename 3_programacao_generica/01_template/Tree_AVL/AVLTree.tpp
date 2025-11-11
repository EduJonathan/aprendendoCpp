#ifndef AVLTREE_TPP
#define AVLTREE_TPP

#include "AVLTree.hpp"

// Implementações da BinarySearchTree
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    deleteSubtree(root);
}

template <typename T>
Node<T> *BinarySearchTree<T>::addValue(const T &id)
{
    if (!root)
    {
        root = createNewNode(nullptr, id);
        return root;
    }

    Node<T> *current = root;

    while (true)
    {
        if (id < current->id)
        {
            if (!current->lesser)
            {
                current->lesser = createNewNode(current, id);
                return current->lesser;
            }
            current = current->lesser;
        }
        else if (id > current->id)
        {
            if (!current->greater)
            {
                current->greater = createNewNode(current, id);
                return current->greater;
            }
            current = current->greater;
        }
        else
        {
            return current; // Node already exists
        }
    }
}

template <typename T>
Node<T> *BinarySearchTree<T>::getNode(const T &value)
{
    Node<T> *current = root;

    while (current)
    {
        if (value < current->id)
        {
            current = current->lesser;
        }
        else if (value > current->id)
        {
            current = current->greater;
        }
        else
        {
            return current;
        }
    }
    return nullptr;
}

template <typename T>
Node<T> *BinarySearchTree<T>::getReplacementNode(Node<T> *node)
{
    if (!node || (!node->lesser && !node->greater))
    {
        return nullptr;
    }
    if (!node->lesser)
    {
        return node->greater;
    }
    if (!node->greater)
    {
        return node->lesser;
    }

    Node<T> *current = node->greater;
    while (current->lesser)
    {
        current = current->lesser;
    }
    return current;
}

template <typename T>
void BinarySearchTree<T>::replaceNodeWithNode(Node<T> *oldNode, Node<T> *newNode)
{
    if (!oldNode)
        return;

    if (oldNode == root)
    {
        root = newNode;
    }
    else if (oldNode->parent->lesser == oldNode)
    {
        oldNode->parent->lesser = newNode;
    }
    else
    {
        oldNode->parent->greater = newNode;
    }
    if (newNode)
    {
        newNode->parent = oldNode->parent;
    }
    delete oldNode;
}

template <typename T>
bool BinarySearchTree<T>::validateNode(Node<T> *node)
{
    if (!node)
        return true;
    if (node->lesser && node->lesser->id >= node->id)
        return false;
    if (node->greater && node->greater->id <= node->id)
        return false;
    return validateNode(node->lesser) && validateNode(node->greater);
}

template <typename T>
Node<T> *BinarySearchTree<T>::createNewNode(Node<T> *parent, const T &id)
{
    return creator ? creator(parent, id) : new Node<T>(parent, id);
}

template <typename T>
void BinarySearchTree<T>::deleteSubtree(Node<T> *node)
{
    if (!node)
        return;
    deleteSubtree(node->lesser);
    deleteSubtree(node->greater);
    delete node;
}

// Implementações do Node
template <typename T>
Node<T>::Node(Node<T> *parent, const T &id) : id(id), parent(parent), lesser(nullptr), greater(nullptr) {}

template <typename T>
Node<T>::~Node() = default;

// Implementações da AVLTree
template <typename T>
AVLTree<T>::AVLTree()
{
    this->creator = [](Node<T> *parent, const T &id) -> Node<T> *
    {
        return new AVLNode(parent, id);
    };
}

template <typename T>
AVLTree<T>::AVLTree(typename BinarySearchTree<T>::NodeCreator creator) : BinarySearchTree<T>(creator) {}

template <typename T>
AVLTree<T>::~AVLTree() = default;

template <typename T>
Node<T> *AVLTree<T>::addValue(const T &id)
{
    Node<T> *nodeToReturn = BinarySearchTree<T>::addValue(id);
    AVLNode *nodeAdded = static_cast<AVLNode *>(nodeToReturn);
    nodeAdded->updateHeight();
    balanceAfterInsert(nodeAdded);

    nodeAdded = static_cast<AVLNode *>(nodeAdded->parent);
    while (nodeAdded)
    {
        int h1 = nodeAdded->height;

        nodeAdded->updateHeight();
        balanceAfterInsert(nodeAdded);

        int h2 = nodeAdded->height;

        if (h1 == h2)
            break;
        nodeAdded = static_cast<AVLNode *>(nodeAdded->parent);
    }
    return nodeToReturn;
}

template <typename T>
Node<T> *AVLTree<T>::removeValue(const T &value)
{
    Node<T> *nodeToRemove = this->getNode(value);
    if (!nodeToRemove)
        return nullptr;

    Node<T> *replacementNode = this->getReplacementNode(nodeToRemove);
    AVLNode *nodeToRefactor = nullptr;

    if (replacementNode)
    {
        nodeToRefactor = static_cast<AVLNode *>(replacementNode->parent);
    }
    if (!nodeToRefactor)
    {
        nodeToRefactor = static_cast<AVLNode *>(nodeToRemove->parent);
    }
    if (nodeToRefactor && nodeToRefactor == nodeToRemove)
    {
        nodeToRefactor = static_cast<AVLNode *>(replacementNode);
    }

    this->replaceNodeWithNode(nodeToRemove, replacementNode);

    while (nodeToRefactor)
    {
        nodeToRefactor->updateHeight();
        balanceAfterDelete(nodeToRefactor);
        nodeToRefactor = static_cast<AVLNode *>(nodeToRefactor->parent);
    }

    return nodeToRemove;
}

template <typename T>
std::string AVLTree<T>::toString() const
{
    return AVLTreePrinter::getString(this);
}

template <typename T>
Node<T> *AVLTree<T>::createNewNode(Node<T> *parent, const T &id)
{
    return new AVLNode(parent, id);
}

template <typename T>
bool AVLTree<T>::validateNode(Node<T> *node)
{
    if (!BinarySearchTree<T>::validateNode(node))
        return false;

    AVLNode *avlNode = static_cast<AVLNode *>(node);
    int balanceFactor = avlNode->getBalanceFactor();

    if (balanceFactor > 1 || balanceFactor < -1)
    {
        return false;
    }
    if (avlNode->isLeaf())
    {
        return avlNode->height == 1;
    }
    else
    {
        int lesserHeight = avlNode->lesser ? static_cast<AVLNode *>(avlNode->lesser)->height : 1;
        int greaterHeight = avlNode->greater ? static_cast<AVLNode *>(avlNode->greater)->height : 1;
        return avlNode->height == (lesserHeight + 1) || avlNode->height == (greaterHeight + 1);
    }
}

template <typename T>
void AVLTree<T>::rotateLeft(AVLNode *node)
{
    AVLNode *newRoot = static_cast<AVLNode *>(node->greater);
    node->greater = newRoot->lesser;

    if (node->greater)
    {
        node->greater->parent = node;
    }

    newRoot->lesser = node;
    newRoot->parent = node->parent;

    if (!node->parent)
    {
        this->root = newRoot;
    }
    else if (node == node->parent->lesser)
    {
        node->parent->lesser = newRoot;
    }
    else
    {
        node->parent->greater = newRoot;
    }
    node->parent = newRoot;
    node->updateHeight();
    newRoot->updateHeight();
}

template <typename T>
void AVLTree<T>::rotateRight(AVLNode *node)
{
    AVLNode *newRoot = static_cast<AVLNode *>(node->lesser);
    node->lesser = newRoot->greater;

    if (node->lesser)
    {
        node->lesser->parent = node;
    }

    newRoot->greater = node;
    newRoot->parent = node->parent;

    if (!node->parent)
    {
        this->root = newRoot;
    }
    else if (node == node->parent->lesser)
    {
        node->parent->lesser = newRoot;
    }
    else
    {
        node->parent->greater = newRoot;
    }
    node->parent = newRoot;
    node->updateHeight();
    newRoot->updateHeight();
}

template <typename T>
void AVLTree<T>::balanceAfterInsert(AVLNode *node)
{
    int balanceFactor = node->getBalanceFactor();

    if (balanceFactor > 1 || balanceFactor < -1)
    {
        AVLNode *child = nullptr;
        Balance balance;

        if (balanceFactor < 0)
        {
            child = static_cast<AVLNode *>(node->lesser);
            balanceFactor = child->getBalanceFactor();
            balance = balanceFactor < 0 ? Balance::LEFT_LEFT : Balance::LEFT_RIGHT;
        }
        else
        {
            child = static_cast<AVLNode *>(node->greater);
            balanceFactor = child->getBalanceFactor();
            balance = balanceFactor < 0 ? Balance::RIGHT_LEFT : Balance::RIGHT_RIGHT;
        }

        if (balance == Balance::LEFT_RIGHT)
        {
            rotateLeft(child);
            rotateRight(node);
        }
        else if (balance == Balance::RIGHT_LEFT)
        {
            rotateRight(child);
            rotateLeft(node);
        }
        else if (balance == Balance::LEFT_LEFT)
        {
            rotateRight(node);
        }
        else
        {
            rotateLeft(node);
        }

        child->updateHeight();
        node->updateHeight();
    }
}

template <typename T>
void AVLTree<T>::balanceAfterDelete(AVLNode *node)
{
    int balanceFactor = node->getBalanceFactor();

    if (balanceFactor == -2 || balanceFactor == 2)
    {
        if (balanceFactor == -2)
        {
            AVLNode *ll = node->lesser ? static_cast<AVLNode *>(node->lesser->lesser) : nullptr;
            int lesser = ll ? ll->height : 0;

            AVLNode *lr = node->lesser ? static_cast<AVLNode *>(node->lesser->greater) : nullptr;
            int greater = lr ? lr->height : 0;

            if (lesser >= greater)
            {
                rotateRight(node);
                node->updateHeight();

                if (node->parent)
                {
                    static_cast<AVLNode *>(node->parent)->updateHeight();
                }
            }
            else
            {
                rotateLeft(static_cast<AVLNode *>(node->lesser));
                rotateRight(node);
                AVLNode *p = static_cast<AVLNode *>(node->parent);

                if (p->lesser)
                    static_cast<AVLNode *>(p->lesser)->updateHeight();
                if (p->greater)
                    static_cast<AVLNode *>(p->greater)->updateHeight();
                p->updateHeight();
            }
        }
        else if (balanceFactor == 2)
        {
            AVLNode *rr = node->greater ? static_cast<AVLNode *>(node->greater->greater) : nullptr;
            int greater = rr ? rr->height : 0;

            AVLNode *rl = node->greater ? static_cast<AVLNode *>(node->greater->lesser) : nullptr;
            int lesser = rl ? rl->height : 0;

            if (greater >= lesser)
            {
                rotateLeft(node);
                node->updateHeight();

                if (node->parent)
                {
                    static_cast<AVLNode *>(node->parent)->updateHeight();
                }
            }
            else
            {
                rotateRight(static_cast<AVLNode *>(node->greater));
                rotateLeft(node);
                AVLNode *p = static_cast<AVLNode *>(node->parent);

                if (p->lesser)
                    static_cast<AVLNode *>(p->lesser)->updateHeight();
                if (p->greater)
                    static_cast<AVLNode *>(p->greater)->updateHeight();
                p->updateHeight();
            }
        }
    }
}

// Implementações da AVLNode
template <typename T>
AVLTree<T>::AVLNode::AVLNode(Node<T> *parent, const T &value) : Node<T>(parent, value), height(1) {}

template <typename T>
bool AVLTree<T>::AVLNode::isLeaf() const
{
    return !this->lesser && !this->greater;
}

template <typename T>
int AVLTree<T>::AVLNode::updateHeight()
{
    int lesserHeight = this->lesser ? static_cast<AVLNode *>(this->lesser)->height : 0;
    int greaterHeight = this->greater ? static_cast<AVLNode *>(this->greater)->height : 0;
    height = std::max(lesserHeight, greaterHeight) + 1;
    return height;
}

template <typename T>
int AVLTree<T>::AVLNode::getBalanceFactor() const
{
    int lesserHeight = this->lesser ? static_cast<AVLNode *>(this->lesser)->height : 0;
    int greaterHeight = this->greater ? static_cast<AVLNode *>(this->greater)->height : 0;
    return greaterHeight - lesserHeight;
}

template <typename T>
std::string AVLTree<T>::AVLNode::toString() const
{
    std::stringstream ss;
    ss << "value=" << this->id << " height=" << height
       << " parent=" << (this->parent ? std::to_string(this->parent->id) : "NULL")
       << " lesser=" << (this->lesser ? std::to_string(this->lesser->id) : "NULL")
       << " greater=" << (this->greater ? std::to_string(this->greater->id) : "NULL");
    return ss.str();
}

// Implementações da AVLTreePrinter
template <typename T>
std::string AVLTree<T>::AVLTreePrinter::getString(const AVLTree<T> *tree)
{
    if (!tree->root)
        return "Árvore não possue nós.";
    return getString(static_cast<AVLNode *>(tree->root), "", true);
}

template <typename T>
std::string AVLTree<T>::AVLTreePrinter::getString(AVLNode *node)
{
    if (!node)
        return "Sub-Árvore não possue nós.";
    return getString(node, "", true);
}

template <typename T>
std::string AVLTree<T>::AVLTreePrinter::getString(AVLNode *node, const std::string &prefix, bool isTail)
{
    if (!node)
    {
        return "Nó nulo\n";
    }

    std::stringstream builder;
    builder << prefix << (isTail ? "└── " : "├── ") << "(" << node->height << ") " << node->id << '\n';

    std::vector<Node<T> *> children;

    if (node->lesser)
        children.push_back(node->lesser);
    if (node->greater)
        children.push_back(node->greater);

    for (std::size_t i = 0; i < children.size(); ++i)
    {
        AVLNode *avlNode = dynamic_cast<AVLNode *>(children[i]);
        if (!avlNode)
        {
            builder << prefix << (i == children.size() - 1 ? "└── " : "├── ") << "Erro: Nó inválido\n";
            continue;
        }

        bool isLast = (i == children.size() - 1);
        builder << getString(avlNode, prefix + (isTail ? "    " : "│   "), isLast);
    }
    return builder.str();
}

#endif // AVLTREE_TPP
