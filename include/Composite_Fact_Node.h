// File name: Composite_Fact_Node.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Composite_Fact_Node data structure.
// Last Changed: 11/20/20
#ifndef COMPOSITE_FACT_NODE_H
#define COMPOSITE_FACT_NODE_H

#include "Composite_Unary_Node.h"

class Component_Node;

class Visitor;

/**
 * @class Composite_Negate_Node
 * @brief A composite node containing only a left child.
 *        The meaning of this node is left!
 */
class Composite_Fact_Node : public Composite_Unary_Node {
public:
    // Ctor
    explicit Composite_Fact_Node(Component_Node* left);

    // Dtor
    ~Composite_Fact_Node() override = default;

    // Return the printable character stored in the node.
    int item() const override;

    // Define the accept() operation used for the Visitor pattern.
    void accept(Visitor& visitor) const override;
};

#endif // COMPOSITE_NEGATE_NODE_H
