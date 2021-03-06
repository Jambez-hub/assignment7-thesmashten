// File name: Print_Visitor.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements the Print_Visitor class
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.

#ifndef PRINT_VISITOR_CPP
#define PRINT_VISITOR_CPP

#include "Print_Visitor.h"
#include "Composite_Add_Node.h"
#include "Composite_Divide_Node.h"
#include "Composite_Multiply_Node.h"
#include "Composite_Negate_Node.h"
#include "Composite_Pow_Node.h"
#include "Composite_Subtract_Node.h"
#include "Leaf_Node.h"
#include <iostream>
#include <memory>

// visit function - prints Leaf_Negate_Node contents to std::cout
void Print_Visitor::visit(const Leaf_Node& node)
{
    std::cout << node.item() << " ";
}

// visit function - prints Composite_Negate_Node contents to std::cout
void Print_Visitor::visit(const Composite_Negate_Node&)
{
    std::cout << '-';
}

// visit function - prints Composite_Add_Node contents to std::cout
void Print_Visitor::visit(const Composite_Add_Node&)
{
    std::cout << "+ ";
}

// visit function - prints Composite_Subtract_Node contents to std::cout
void Print_Visitor::visit(const Composite_Subtract_Node&)
{
    std::cout << "- ";
}

// visit function - prints Composite_Divide_Node contents to std::cout
void Print_Visitor::visit(const Composite_Divide_Node&)
{
    std::cout << "/ ";
}

// visit function - prints Composite_Multiply_Node contents to std::cout
void Print_Visitor::visit(const Composite_Multiply_Node&)
{
    std::cout << "* ";
}

// visit function - prints Composite_Pow_Node contents to std::cout
void Print_Visitor::visit(const Composite_Pow_Node&)
{
    std::cout << "^ ";
}

// visit function - prints Composite_Fact_Node contents to std::cout
void Print_Visitor::visit(const Composite_Fact_Node&)
{
    std::cout << '!';
}

// visit function - prints Composite_Fact_Node contents to std::cout
void Print_Visitor::visit(const Composite_Modulus_Node&)
{
    std::cout << '% ';
}

#endif // PRINT_VISITOR_CPP
