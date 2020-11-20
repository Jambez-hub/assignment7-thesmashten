// File name: Print_Visitor.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Print_Visitor class
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#ifndef PRINT_VISITOR_H
#define PRINT_VISITOR_H

#include "Visitor.h"

/**
 * @class Print_Visitor
 * @brief This class serves as a visitor for printing the contents of
 *        nodes to std::cout.
 */

class Print_Visitor : public Visitor {
public:
    // Visits a Leaf_Node and prints it contents to std::cout.
    void visit(const Leaf_Node& node) override;

    // Visit a Composite_Negate_Node and prints its contents to std::cout.
    void visit(const Composite_Negate_Node& node) override;

    // Visit a Composite_Add_Node and prints its contents to std::cout.
    void visit(const Composite_Add_Node& node) override;

    // Visit a Composite_Subtract_Node and prints its contents to @a
    // std::cout.
    void visit(const Composite_Subtract_Node& node) override;

    // Visit a Composite_Divide_Node and prints its contents to std::cout.
    void visit(const Composite_Divide_Node& node) override;

    // visit function - prints Composite_Multiply_Node contents to std::cout
    void visit(const Composite_Multiply_Node& node) override;

    // visit function - prints Composite_Pow_Node contents to std::cout
    void visit(const Composite_Pow_Node& node) override;

    // visit function - prints Composite_Fact_Node contents to std::cout
    void visit(const Composite_Fact_Node& node) override;

    // visit function - prints Composite_Modulus_Node contents to std::cout
    void visit(const Composite_Modulus_Node& node) override;
};

#endif // PRINT_VISITOR_H
