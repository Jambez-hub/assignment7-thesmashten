// File name: Composite_Unary_Node_Left.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Composite_Unary_Node_Left data structure.
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#ifndef COMPOSITE_UNARY_NODE_LEFT_H
#define COMPOSITE_UNARY_NODE_LEFT_H

#include "Component_Node.h"
#include <memory>

/**
 * @class Composite_Unary_Node
 * @brief Defines a left child (but not a right one) and thus is useful for
 * unary operations.
 * @see Composite_Binary_Node
 */
class Composite_Unary_Node_Left : public Component_Node {
public:
    // Ctor
    explicit Composite_Unary_Node_Left(Component_Node* left);

    // Return the right child.
    Component_Node* left() const override;

    // Dtor
    ~Composite_Unary_Node_Left() override = default;

private:
    // Right child
    std::unique_ptr<Component_Node> leftChild;
};

#endif // EXPRESSIONTREE_COMPOSITE_UNARY_NODE_LEFT_H
