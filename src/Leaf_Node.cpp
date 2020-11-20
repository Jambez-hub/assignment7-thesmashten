// File name: Leaf_Node.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Leaf_Node class
// Last Changed: 11/20/20
#ifndef LEAF_NODE_CPP
#define LEAF_NODE_CPP

#include "Leaf_Node.h"
#include "Visitor.h"
#include <iostream>

// Ctor
Leaf_Node::Leaf_Node(int item)
    : Component_Node()
    , value(item)
{
}

// Ctor
Leaf_Node::Leaf_Node(const std::string& item)
    : Component_Node()
{
    value = atoi(item.c_str());
}

// Ctor
Leaf_Node::Leaf_Node(const char* item)
    : Component_Node()
{
    value = atoi(item);
}

// return the item
int Leaf_Node::item() const
{
    return value;
}

void Leaf_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}

#endif // LEAF_NODE_CPP
