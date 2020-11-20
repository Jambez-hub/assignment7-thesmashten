// File name: Composite_Subtract_Node.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Composite_Subtract_Node data structure.
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#include "Composite_Subtract_Node.h"
#include "Visitor.h"

// Ctor
Composite_Subtract_Node::Composite_Subtract_Node(Component_Node* left, Component_Node* right)
    : Composite_Binary_Node(left, right)
{
}

int Composite_Subtract_Node::item() const
{
    return '-';
}

// accept a visitor
void Composite_Subtract_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
