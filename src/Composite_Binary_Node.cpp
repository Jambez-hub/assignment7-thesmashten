// File name: Composite_Binary_Node.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Composite_Binary_Node data structure.
// Last Changed: 11/20/20

#include "Composite_Binary_Node.h"

// Ctor
Composite_Binary_Node::Composite_Binary_Node(Component_Node* left, Component_Node* right)
    : Composite_Unary_Node(right)
    , leftChild(left)
{
}

// Return the left child pointer
Component_Node* Composite_Binary_Node::left() const
{
    return leftChild.get();
}
