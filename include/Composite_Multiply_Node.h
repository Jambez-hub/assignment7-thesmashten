// File name: Composite_Multiply_Node.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Composite_Multiply_Node data structure.
// Last Changed: 11/20/20
#ifndef COMPOSITE_MULTIPLY_NODE_H
#define COMPOSITE_MULTIPLY_NODE_H

class Component_Node;

#include "Composite_Binary_Node.h"

class Visitor;

/**
 * @class Composite_Multiply_Node
 * @brief A composite node containing left and right
 *        children. The meaning of this node is left * right
 */
class Composite_Multiply_Node : public Composite_Binary_Node {
public:
    // Ctor
    Composite_Multiply_Node(Component_Node* left, Component_Node* right);

    // Dtor
    ~Composite_Multiply_Node() override = default;

    // Return the printable character stored in the node.
    int item() const override;

    // Define the accept() operation used for the Visitor pattern.
    void accept(Visitor& visitor) const override;
};

#endif // COMPOSITE_MULTIPLY_NODE_H
