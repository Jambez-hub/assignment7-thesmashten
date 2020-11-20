// File name: Composite_Pow_Node.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Composite_Pow_Node data structure.
// Last Changed: 11/20/20
#include "Composite_Pow_Node.h"
#include "Visitor.h"

// Ctor
Composite_Pow_Node::Composite_Pow_Node(Component_Node* left, Component_Node* right)
    : Composite_Binary_Node(left, right)
{
}

int Composite_Pow_Node::item() const
{
    return '^';
}

// accept a visitor
void Composite_Pow_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
