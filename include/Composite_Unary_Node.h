// File name: Composite_Unary_Node.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Composite_Unary_Node data structure.
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#ifndef COMPOSITE_UNARY_NODE_H
#define COMPOSITE_UNARY_NODE_H

#include "Component_Node.h"
#include <memory>

/**
 * @class Composite_Unary_Node
 * @brief Defines a right child (but not a left one) and thus is useful for
 * unary operations.
 * @see Composite_Binary_Node
 */
class Composite_Unary_Node : public Component_Node {
public:
    // Ctor
    explicit Composite_Unary_Node(Component_Node* right);

    // Return the right child.
    Component_Node* right() const override;

    // Dtor
    ~Composite_Unary_Node() override = default;

private:
    // Right child
    std::unique_ptr<Component_Node> rightChild;
};

#endif // COMPOSITE_UNARY_NODE_H
