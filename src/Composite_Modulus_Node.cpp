// File name: Composite_Modulus_Node.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Composite_Modulus_Node data structure.
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.

#include "Composite_Modulus_Node.h"
#include "Visitor.h"

// Ctor
Composite_Modulus_Node::Composite_Modulus_Node(Component_Node* left, Component_Node* right)
    : Composite_Binary_Node(left, right)
{
}

int Composite_Modulus_Node::item() const
{
    return '%';
}

// accept a visitor
void Composite_Modulus_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
