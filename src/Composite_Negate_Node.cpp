// File name: Composite_Negate_Node.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Composite_Negate_Node data structure.
// Last Changed: 11/20/20
#include "Composite_Negate_Node.h"
#include "Visitor.h"

// Ctor
Composite_Negate_Node::Composite_Negate_Node(Component_Node* right)
    : Composite_Unary_Node(right)
{
}

int Composite_Negate_Node::item() const
{
    return '-';
}

// accept a visitor
void Composite_Negate_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
