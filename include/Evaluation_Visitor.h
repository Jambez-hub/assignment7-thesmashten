/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#ifndef EVALUATION_VISITOR_H
#define EVALUATION_VISITOR_H

#include "Composite_Add_Node.h"
#include "Composite_Divide_Node.h"
#include "Composite_Multiply_Node.h"
#include "Composite_Negate_Node.h"
#include "Composite_Pow_Node.h"
#include "Composite_Subtract_Node.h"
#include "Leaf_Node.h"
#include "Visitor.h"
#include <stack>

// forward declarations of nodes
// solves circular include problem

class Component_Node;
class Composite_Negate_Node;
class Composite_Add_Node;
class Composite_Subtract_Node;
class Composite_Divide_Node;
class Composite_Multiply_Node;
class Composite_Pow_Node;

/**
 * @class Evaluation_Visitor
 * @brief This plays the role of a visitor for evaluating
 *        nodes in an expression tree that is being iterated in
 *        post-order fashion (and does not work correctly with any
 *        other iterator).
 */
class Evaluation_Visitor : public Visitor {
public:
    // Visit a Leaf_Node.
    void visit(const Leaf_Node& node) override;

    // Visit a Composite_Negate_Node.
    void visit(const Composite_Negate_Node& node) override;

    // Visit a Composite_Add_Node.
    void visit(const Composite_Add_Node& node) override;

    // Visit a Composite_Subtract_Node.
    void visit(const Composite_Subtract_Node& node) override;

    // Visit a Composite_Divide_Node.
    void visit(const Composite_Divide_Node& node) override;

    // Visit a Composite_Multiply_Node.
    void visit(const Composite_Multiply_Node& node) override;

    // Visit a Composite_Pow_Node.
    void visit(const Composite_Pow_Node& node) override;

    // Visit a Composite_Fact_Node.
    void visit(const Composite_Fact_Node& node) override;

    // Visit a Composite_Modulus_Node.
    void visit(const Composite_Modulus_Node& node) override;

    // Print the total of the evaluation.
    int total();

    // Resets the evaluation to it can be reused.
    void reset();

private:
    // Stack used for temporarily storing evaluations.
    std::stack<int> stack;
};

#endif // EVALUATION_VISITOR_H
