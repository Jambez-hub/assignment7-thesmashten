/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Evaluation_Visitor.h"
#include <iostream>
#include <math.h> /* pow */
#include <memory>

// base evaluation for a node. This is used by Leaf_Node
void Evaluation_Visitor::visit(const Leaf_Node& node)
{
    stack.push(node.item());
}

// evaluation of a negation (Composite_Negate_Node)
void Evaluation_Visitor::visit(const Composite_Negate_Node&)
{
    if (stack.size() >= 1) {
        auto value = stack.top();
        stack.pop();
        stack.push(-value);
    }
}

// evaluation of an addition (Composite_Add_Node)
void Evaluation_Visitor::visit(const Composite_Add_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs + rhs);
    }
}

// evaluation of an addition (Composite_Subtract_Node)
void Evaluation_Visitor::visit(const Composite_Subtract_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs - rhs);
    }
}

// evaluations of a division (Composite_Divide_Node)
void Evaluation_Visitor::visit(const Composite_Divide_Node&)
{
    if (stack.size() >= 2 && stack.top()) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs / rhs);
    } else {
        std::cout << "\n\n**ERROR**: Division by zero is not allowed. ";
        std::cout << "Resetting evaluation visitor.\n\n";
        reset();
    }
}

// evaluations of a multiplication (Composite_Multiply_Node)
void Evaluation_Visitor::visit(const Composite_Multiply_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs * rhs);
    }
}

// evaluations of a pow (Composite_Pow_Node)
void Evaluation_Visitor::visit(const Composite_Pow_Node&)
{
    if (stack.size() >= 2) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        int value = pow(lhs, rhs);
        stack.push(value);
    }
}

// evaluations of a Factorial (Composite_Fact_Node)
void Evaluation_Visitor::visit(const Composite_Fact_Node& node)
{
    if (stack.size() >= 1) {
        int result = 1;
        auto value = stack.top();
        for (uint32_t i = 1; i <= value; ++i) {
            result *= i;
        }
        stack.pop();
        stack.push(result);
    }
}

void Evaluation_Visitor::visit(const Composite_Modulus_Node& node)
{
    if (stack.size() >= 2 && stack.top()) {
        auto rhs = stack.top();
        stack.pop();
        auto lhs = stack.top();
        stack.pop();
        stack.push(lhs % rhs);
    }
}

// print a total for the evaluation
int Evaluation_Visitor::total()
{
    if (!stack.empty())
        return stack.top();
    else
        return 0;
}

// reset the evaluation
void Evaluation_Visitor::reset()
{
    while (!stack.empty())
        stack.pop();
}
