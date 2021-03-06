// File name: Leaf_Node.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Leaf_Node class
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#ifndef LEAF_NODE_H
#define LEAF_NODE_H

#include "Component_Node.h"
#include <string>

// Forward declarations.
class Visitor;

/**
 * @class Leaf_Node
 * @brief Defines a terminal node of type integer. This node inherits
 *        from Node and so has no children.
 */

class Leaf_Node : public Component_Node {
public:
    // Ctor.
    Leaf_Node(int item);

    // Ctor.
    Leaf_Node(const std::string& item);

    // Ctor.
    Leaf_Node(const char* item);

    // Dtor.
    virtual ~Leaf_Node() = default;

    // Return the item stored in the node.
    virtual int item() const;

    // Define the accept() operation used for the Visitor pattern.
    virtual void accept(Visitor& visitor) const;

private:
    // Integer value associated with the operand.
    int value;
};

#endif // LEAF_NODE_H
