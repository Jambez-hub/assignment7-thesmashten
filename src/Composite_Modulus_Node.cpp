/* Copyright G. Hemingway @ 2019, All Rights Reserved */
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
