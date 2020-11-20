// File name: Composite_Add_Node.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Composite_Add_Node data structure.
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#ifndef ADD_NODE_H
#define ADD_NODE_H

#include "Composite_Binary_Node.h"

// Forward declaration.
class Component_Node;

class Visitor;

/**
 * @class Composite_Add_Node
 * @brief A composite node containing left and right
 *        children. The meaning of this node is left + right
 */
class Composite_Add_Node : public Composite_Binary_Node {
public:
    // Ctor
    Composite_Add_Node(Component_Node* left, Component_Node* right);

    // Dtor
    ~Composite_Add_Node() override = default;

    // Return the printable character stored in the node.
    int item() const override;

    // Define the accept() operation used for the Visitor pattern.
    void accept(Visitor& visitor) const override;
};

#endif // ADD_NODE_H
