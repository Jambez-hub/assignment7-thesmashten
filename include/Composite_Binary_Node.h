// File name: Composite_Binary_Node.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Composite_Binary_Node data structure.
// Last Changed: 11/20/20
#ifndef COMPOSITE_BINARY_NODE_H
#define COMPOSITE_BINARY_NODE_H

#include "Composite_Unary_Node.h"

/**
 * @class Composite_Binary_Node
 * @brief Defines a left and right node (via inheritance).
 */
class Composite_Binary_Node : public Composite_Unary_Node {
public:
    // Ctor
    Composite_Binary_Node(Component_Node* left, Component_Node* right);

    // Dtor
    ~Composite_Binary_Node() override = default;

    // Return the left child.
    Component_Node* left() const override;

private:
    // left child
    std::unique_ptr<Component_Node> leftChild;
};

#endif // COMPOSITE_BINARY_NODE_H
