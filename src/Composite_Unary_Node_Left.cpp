// File name: Composite_Unary_Node_Left.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Composite_Unary_Node_Left data structure.
// Last Changed: 11/20/20
#include "Composite_Unary_Node_Left.h"

// Ctor
Composite_Unary_Node_Left::Composite_Unary_Node_Left(Component_Node* left)
    : Component_Node()
    , leftChild(left)
{
}

// Return the right child pointer
Component_Node* Composite_Unary_Node_Left::left() const
{
    return leftChild.get();
}
