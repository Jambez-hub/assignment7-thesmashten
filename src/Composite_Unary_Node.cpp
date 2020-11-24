// File name: Composite_Unary_Node.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Composite_Unary_Node data structure.
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#include "Composite_Unary_Node.h"

// Ctor
Composite_Unary_Node::Composite_Unary_Node(Component_Node* right)
    : Component_Node()
    , rightChild(right)
{
}

// Return the right child pointer
Component_Node* Composite_Unary_Node::right() const
{
    return rightChild.get();
}
