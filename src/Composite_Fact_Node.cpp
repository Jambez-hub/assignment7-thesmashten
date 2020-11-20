// File name: Composite_Fact_Node.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Composite_Fact_Node data structure.
// Last Changed: 11/20/20

#include "Composite_Fact_Node.h"
#include "Visitor.h"

// Ctor
Composite_Fact_Node::Composite_Fact_Node(Component_Node* left)
    : Composite_Unary_Node(left)
{
}

int Composite_Fact_Node::item() const
{
    return '!';
}

// accept a visitor
void Composite_Fact_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
