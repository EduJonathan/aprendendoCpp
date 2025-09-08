#include "adjacente_node.hpp"

AdjacenteListNode::AdjacenteListNode(int vertex, int weight) : vertice(vertex), peso(weight) {}
int AdjacenteListNode::getVertice() const { return vertice; }
int AdjacenteListNode::getPeso() const { return peso; }
