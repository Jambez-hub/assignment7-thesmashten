/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Composite_Fact_Node.h"
#include "Visitor.h"

// Ctor
Composite_Fact_Node::Composite_Fact_Node(Component_Node* right)
    : Composite_Unary_Node(right)
{
}

int Composite_Fact_Node::item() const
{
    return '!';
}

// accept a visitor
void Composite_Fact_Node::accept(Visitor& visitor) const
{
    visitor.visit(*this);
}
