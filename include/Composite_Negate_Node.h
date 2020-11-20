// File name: Composite_Negate_Node.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Composite_Negate_Node data structure.
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#ifndef COMPOSITE_NEGATE_NODE_H
#define COMPOSITE_NEGATE_NODE_H

#include "Composite_Unary_Node.h"

class Component_Node;

class Visitor;

/**
 * @class Composite_Negate_Node
 * @brief A composite node containing only a right child.
 *        The meaning of this node is -right, eg -5, -7, etc.
 */
class Composite_Negate_Node : public Composite_Unary_Node {
public:
    // Ctor
    explicit Composite_Negate_Node(Component_Node* right);

    // Dtor
    ~Composite_Negate_Node() override = default;

    // Return the printable character stored in the node.
    int item() const override;

    // Define the accept() operation used for the Visitor pattern.
    void accept(Visitor& visitor) const override;
};

#endif // COMPOSITE_NEGATE_NODE_H
