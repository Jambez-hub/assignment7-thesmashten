/* Copyright G. Hemingway @ 2019, All Rights Reserved */
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
