// File name: Interpreter.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements a Interpreter design pattern.
// Last Changed: 11/20/20

#ifndef INTERPRETER_CPP
#define INTERPRETER_CPP

#include "Interpreter.h"
#include "Component_Node.h"
#include "Composite_Add_Node.h"
#include "Composite_Divide_Node.h"
#include "Composite_Fact_Node.h"
#include "Composite_Modulus_Node.h"
#include "Composite_Multiply_Node.h"
#include "Composite_Negate_Node.h"
#include "Composite_Pow_Node.h"
#include "Composite_Subtract_Node.h"
#include "Composite_Unary_Node_Left.h"
#include "Expression_Tree_Context.h"
#include "Expression_Tree_Event_Handler.h"
#include "Leaf_Node.h"
#include <cstdlib>
#include <iostream>
#include <memory>

/**
 * @class Symbol
 * @brief Abstract base class of all parse tree nodes.
 */
class Symbol {
public:
    // constructor
    Symbol(Symbol* l, Symbol* r, int precedence = 0);
    // destructor
    virtual ~Symbol();
    // abstract method for returning precedence level (higher
    // value means higher precedence
    virtual int precedence()
    {
        return prec;
    }
    virtual int add_precedence(int accumulated_precedence) = 0;
    // abstract method for building an Expression Expression_Tree Node
    virtual Component_Node* build() = 0;
    // left and right pointers
    Symbol* left;
    Symbol* right;
    int prec;

private:
    size_t index;
};

/**
 * @class Operator
 * @brief Abstract base class for all parse tree node operators
 * @see   Add, Subtract, Multiply, Divide
 */
class Operator : public Symbol {
public:
    // constructor
    Operator(Symbol* left, Symbol* right, int index, int precedence = 1);
    // destructor
    ~Operator() override = default;

private:
    size_t index;
};

/**
 * @class Unary_Operator
 * @brief Abstract base class for all parse tree node operators
 * @see   Add, Subtract, Multiply, Divide
 */
class Unary_Operator : public Symbol {
public:
    // constructor
    explicit Unary_Operator(Symbol* right, int index, int precedence = 1);
    // destructor
    ~Unary_Operator() override = default;

private:
    size_t index;
};

class Unary_Left_Operator : public Symbol {
public:
    // constructor
    explicit Unary_Left_Operator(Symbol* left, int index, int precedence = 1);
    // destructor
    ~Unary_Left_Operator() override = default;

private:
    size_t index;
};

/**
 * @class Number
 * @brief Leaf node of parse tree
 */
class Number : public Symbol {
public:
    // constructors
    explicit Number(const std::string& input, int index);
    explicit Number(const int& input);
    // destructor
    ~Number() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Tree node
    Component_Node* build() override;

private:
    // contains the value of the leaf node
    int item;
    size_t index;
};

/**
 * @class Subtract
 * @brief Subtraction node of the parse tree
 */
class Subtract : public Operator {
public:
    // constructor
    Subtract(int index);
    // destructor
    ~Subtract() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Tree node
    Component_Node* build() override;

private:
    size_t index;
};

/**
 * @class Add
 * @brief Addition node of the parse tree
 */
class Add : public Operator {
public:
    // constructor
    Add(int index);
    // destructor
    ~Add() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Tree node
    Component_Node* build() override;

private:
    size_t index;
};

/**
 * @class Negate
 * @brief Negate node of the parse tree
 */
class Negate : public Unary_Operator {
public:
    // constructor
    Negate(int index);
    // destructor
    ~Negate() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Tree node
    Component_Node* build() override;

private:
    size_t index;
};

class Factorial : public Unary_Left_Operator {
public:
    // constructor
    Factorial(int index);
    // destructor
    ~Factorial() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Tree node
    Component_Node* build() override;

private:
    size_t index;
};

class Pow : public Operator {
public:
    // constructor
    Pow(int index);
    // destructor
    ~Pow() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Tree node
    Component_Node* build() override;

private:
    size_t index;
};

/**
 * @class Multiply
 * @brief Multiplication node of the parse tree
 */
class Multiply : public Operator {
public:
    // constructor
    Multiply(int index);
    // destructor
    ~Multiply() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Tree node
    Component_Node* build() override;

private:
    size_t index;
};

/**
 * @class Divide
 * @brief Division node of the parse tree
 */
class Divide : public Operator {
public:
    // constructor
    Divide(int index);
    // destructor
    ~Divide() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Tree node
    Component_Node* build() override;

private:
    size_t index;
};

class Modulus : public Operator {
public:
    // constructor
    Modulus(int index);
    // destructor
    ~Modulus() override = default;
    // returns the precedence level
    int add_precedence(int accumulated_precedence) override;
    // builds an equivalent Expression_Treee node
    Component_Node* build() override;

private:
    size_t index;
};

// return the value of a variable
int Interpreter_Context::get(std::string variable)
{
    return map[variable];
}

// set the value of a variable
void Interpreter_Context::set(std::string variable, int value)
{
    map[variable] = value;
}

// print all variables and their values
void Interpreter_Context::print()
{
    for (auto i = map.begin(); i != map.end(); ++i)
        std::cout << i->first << "=" << i->second << std::endl;
}

// clear all variables and their values
void Interpreter_Context::reset()
{
    map.clear();
}

bool Interpreter_Context::search(std::string variable)
{
    if (map.find(variable) == map.end()) {
        return false;
    }
    return true;
}

int Interpreter_Context::size()
{
    uint32_t count = 0;
    for (auto i = map.begin(); i != map.end(); ++i) {
        ++count;
    }
    return count;
}

std::string Interpreter_Context::getKey(uint32_t index)
{
    auto i = map.begin();
    for (uint32_t j = 0; j < index; ++j) {
        ++i;
    }
    return i->first;
}
uint32_t Interpreter_Context::getVal(uint32_t index)
{
    auto i = map.begin();
    for (uint32_t j = 0; j < index; ++j) {
        ++i;
    }
    return i->second;
}

// constructor
Symbol::Symbol(Symbol* l, Symbol* r, int precedence)
    : left(l)
    , right(r)
    , prec(precedence)
{
}

// destructor
Symbol::~Symbol()
{
    delete left;
    delete right;
}

// constructor
Operator::Operator(Symbol* left, Symbol* right, int pos, int precedence)
    : Symbol(left, right, precedence)
{
    index = pos;
}

// constructor
Unary_Operator::Unary_Operator(Symbol* right, int pos, int precedence)
    : Symbol(nullptr, right, precedence)
{
    index = pos;
}

Unary_Left_Operator::Unary_Left_Operator(Symbol* left, int pos, int precedence)
    : Symbol(nullptr, left, precedence)
{
    index = pos;
}

// constructor
Number::Number(const std::string& input, int pos)
    : Symbol(nullptr, nullptr, 7)
{
    index = pos;
    item = ::atoi(input.c_str());
}

// constructor
Number::Number(const int& input)
    : Symbol(nullptr, nullptr, 7)
    , item(input)
{
}

// returns the precedence level
int Number::add_precedence(int accumulated_precedence)
{
    return this->prec = 7 + accumulated_precedence;
}

// builds an equivalent Expression_Tree node
Component_Node* Number::build()
{
    return new Leaf_Node(item);
}
// constructor
Factorial::Factorial(int pos)
    : Unary_Left_Operator(nullptr, index, 5)
{
    index = pos;
}

// returns the precedence level
int Factorial::add_precedence(int accumulated_precedence)
{
    return this->prec = 5 + accumulated_precedence;
}

Component_Node* Factorial::build()
{
    if (left == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting left operand to !\n";
        return new Composite_Fact_Node(nullptr);
    }
    return new Composite_Fact_Node(left->build());
}

// constructor
Negate::Negate(int pos)
    : Unary_Operator(nullptr, index, 3)
{
    index = pos;
}

// returns the precedence level
int Negate::add_precedence(int accumulated_precedence)
{
    return this->prec = 3 + accumulated_precedence;
}

// builds an equivalent Expression_Tree node
Component_Node* Negate::build()
{
    if (right == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting left operand to -\n";
        return new Composite_Negate_Node(nullptr);
    }
    return new Composite_Negate_Node(right->build());
}

// constructor
Add::Add(int pos)
    : Operator(nullptr, nullptr, index, 1)
{
    index = pos;
}

// returns the precedence level
int Add::add_precedence(int accumulated_precedence)
{
    return this->prec = 1 + accumulated_precedence;
}

// builds an equivalent Expression_Tree node
Component_Node* Add::build()
{
    if (right == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting right operand to +\n";
        return new Composite_Add_Node(nullptr, nullptr);
    }
    if (left == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting left operand to +\n";
        return new Composite_Add_Node(nullptr, nullptr);
    }
    return new Composite_Add_Node(left->build(), right->build());
}

// constructor
Subtract::Subtract(int pos)
    : Operator(nullptr, nullptr, index, 1)
{
    index = pos;
}

// returns the precedence level
int Subtract::add_precedence(int accumulated_precedence)
{
    return this->prec = 1 + accumulated_precedence;
}

// builds an equivalent Expression_Tree node
Component_Node* Subtract::build()
{
    if (right == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting right operand to -\n";
        return new Composite_Subtract_Node(nullptr, nullptr);
    }
    if (left == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting left operand to -\n";
        return new Composite_Subtract_Node(nullptr, nullptr);
    }
    return new Composite_Subtract_Node(left->build(), right->build());
}

// constructor
Multiply::Multiply(int pos)
    : Operator(nullptr, nullptr, index, 2)
{
    index = pos;
}

// returns the precedence level
int Multiply::add_precedence(int accumulated_precedence)
{
    return this->prec = 2 + accumulated_precedence;
}

// builds an equivalent Expression_Tree node
Component_Node* Multiply::build()
{
    if (right == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting right operand to *\n";
        return new Composite_Multiply_Node(nullptr, nullptr);
    }
    if (left == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting left operand to *\n";
        return new Composite_Multiply_Node(nullptr, nullptr);
    }
    return new Composite_Multiply_Node(left->build(), right->build());
}

// constructor
Pow::Pow(int pos)
    : Operator(nullptr, nullptr, index, 4)
{
    index = pos;
}

// builds an equivalent Expression_Tree node
Component_Node* Pow::build()
{
    if (right == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting right operand to ^\n";
        return new Composite_Pow_Node(nullptr, nullptr);
    }
    if (left == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting left operand to ^\n";
        return new Composite_Pow_Node(nullptr, nullptr);
    }
    return new Composite_Pow_Node(left->build(), right->build());
}

// returns the precedence level
int Pow::add_precedence(int accumulated_precedence)
{
    return this->prec = 4 + accumulated_precedence;
}

// constructor
Divide::Divide(int pos)
    : Operator(nullptr, nullptr, index, 2)
{
    index = pos;
}

// returns the precedence level
int Divide::add_precedence(int accumulated_precedence)
{
    return this->prec = 2 + accumulated_precedence;
}

// builds an equivalent Expression_Tree node
Component_Node* Divide::build()
{
    if (right == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting right operand to /\n";
        return new Composite_Divide_Node(nullptr, nullptr);
    } else if (left == nullptr) {
        std::cout << "--^";
        std::cout << "Error: Expecting left operand to /\n";
        return new Composite_Divide_Node(nullptr, nullptr);
    }
    return new Composite_Divide_Node(left->build(), right->build());
}

// constructor
Modulus::Modulus(int pos)
    : Operator(nullptr, nullptr, index, 3)
{
    index = pos;
}

// returns the precedence level
int Modulus::add_precedence(int accumulated_precedence)
{
    return this->prec = 2 + accumulated_precedence;
}

// builds an equivalent Expression_Tree node
Component_Node* Modulus::build()
{
    if (right == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Error: Expecting right operand to %\n";
        return new Composite_Modulus_Node(nullptr, nullptr);
    }
    if (left == nullptr) {
        for (uint32_t i = 0; i < index + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "^";
        std::cout << "Left identifier expected.";
        return new Composite_Modulus_Node(nullptr, nullptr);
    }
    return new Composite_Modulus_Node(left->build(), right->build());
}

// method for checking if a character is a valid operator
bool Interpreter::is_operator(char input)
{
    return input == '+' || input == '-' || input == '*' || input == '/' || input == '%'
        || input == '^' || input == '!' || input == '%';
}

// method for checking if a character is a number
bool Interpreter::is_number(char input)
{
    return input >= '0' && input <= '9';
}

// method for checking if a character is a candidate
// for a part of a variable name
bool Interpreter::is_alphanumeric(char input)
{
    return (input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') || (input == '_')
        || (input >= '0' && input <= '9');
}

// inserts a terminal into the parse tree
void Interpreter::terminal_insert(Symbol* terminal, std::list<Symbol*>& list)
{
    if (!list.empty()) {
        // Something exists in the list, so make this number the rightmost child

        Symbol* symbol = list.back();

        if (symbol) {
            // while there is a right child, continue down
            for (; symbol->right; symbol = symbol->right)
                continue;

            // symbol right will be this terminal and that's all we have
            // to do.
            symbol->right = terminal;
        }
    } else
        // a number appeared first
        list.push_back(terminal);
}

// inserts a variable (leaf node / number) into the parse tree
void Interpreter::variable_insert(Interpreter_Context& context, const std::string& input,
    std::string::size_type& i, int& accumulated_precedence, std::list<Symbol*>& list,
    Symbol*& lastValidInput)
{
    // merge all consecutive number chars into a single
    // Number symbol, eg '123' = int (123). Scope of j needs
    // to be outside of the for loop.

    std::string::size_type j = 1;

    for (; i + j <= input.length() && is_alphanumeric(input[i + j]); ++j)
        continue;

    // lookup the variable in the context

    int value = context.get(input.substr(i, j));

    // make a Number out of the integer

    auto number = new Number(value);
    number->add_precedence(accumulated_precedence);

    lastValidInput = number;

    // update i to the last character that was a number. the ++i will
    // update the i at the end of the loop to the next check.

    i += j - 1;

    precedence_insert(number, list);
}

// inserts a leaf node / number into the parse tree
void Interpreter::number_insert(const std::string& input, std::string::size_type& i,
    int& accumulated_precedence, std::list<Symbol*>& list, Symbol*& lastValidInput)
{
    // merge all consecutive number chars into a single Number symbol,
    // eg '123' = int (123). Scope of j needs to be outside of the for
    // loop.

    std::string::size_type j = 1;

    for (; i + j <= input.length() && is_number(input[i + j]); ++j)
        continue;

    Number* number = new Number(input.substr(i, j), j);
    number->add_precedence(accumulated_precedence);

    lastValidInput = number;

    // update i to the last character that was a number. the ++i will
    // update the i at the end of the loop to the next check.

    i += j - 1;

    precedence_insert(number, list);
}

// inserts a multiplication or division into the parse tree
void Interpreter::precedence_insert(Symbol* op, std::list<Symbol*>& list)
{
    if (!list.empty()) {
        // if last element was a number, then make that our left_

        Symbol* parent = list.back();
        Symbol* child = parent->right;

        if (child) {
            // while there is a child of parent, keep going down the right side
            for (; child && child->precedence() < op->precedence(); child = child->right)
                parent = child;
        }

        if (parent->precedence() < op->precedence()) {

            // op left will be the old child. new parent child will be
            // the op. To allow infinite negations, we have to check for
            // unary_operator.

            // **************** This is the culprit

            if (!op->left)
                op->left = child;

            parent->right = op;
        } else {
            // this can be one of two things, either we are the same
            // precedence or we are less precedence than the parent.
            // this also means different things for unary ops. The
            // most recent unary op (negate) has a higher precedence

            if (dynamic_cast<Unary_Operator*>(op)) {
                for (; child && child->precedence() == op->precedence(); child = child->right)
                    parent = child;

                // I can't think of a valid reason that parent->right would
                // be possible !0

                parent->right = op;
            } else {
                // everything else is evaluated the same. For instance, if
                // this is 5 * 4 / 2, and we currently have Mult (5,4) in the
                // list, we need to make parent our left child.

                op->left = parent;
                list.pop_back();
                list.push_back(op);
            }
        }
    } else {
        list.push_back(op);
    }
}

void Interpreter::main_loop(Interpreter_Context& context, const std::string& input,
    std::string::size_type& i, Symbol*& lastValidInput, bool& handled, int& accumulated_precedence,
    std::list<Symbol*>& list)
{
    handled = false;
    if (is_number(input[i])) {
        handled = true;
        // leaf node
        number_insert(input, i, accumulated_precedence, list, lastValidInput);
    } else if (is_alphanumeric(input[i])) {
        handled = true;
        // variable leaf node
        variable_insert(context, input, i, accumulated_precedence, list, lastValidInput);
    } else if (input[i] == '+') {
        handled = true;
        // addition operation
        auto op = new Add(i);
        op->add_precedence(accumulated_precedence);

        lastValidInput = nullptr;

        // insert the op according to left-to-right relationships
        precedence_insert(op, list);
    } else if (input[i] == '-') {
        handled = true;

        Symbol* op = nullptr;
        if (!lastValidInput) {
            // Negate
            op = new Negate(i);
            op->add_precedence(accumulated_precedence);
        } else {
            // Subtract
            op = new Subtract(i);
            op->add_precedence(accumulated_precedence);
        }

        lastValidInput = nullptr;

        // insert the op according to left-to-right relationships
        precedence_insert(op, list);

    } else if (input[i] == '*') {
        handled = true;
        // multiplication operation
        auto op = new Multiply(i);
        op->add_precedence(accumulated_precedence);

        lastValidInput = nullptr;

        // insert the op according to precedence relationships
        precedence_insert(op, list);
        // associative_insert (op);
    } else if (input[i] == '/') {
        handled = true;
        // division operation
        auto op = new Divide(i);
        op->add_precedence(accumulated_precedence);

        lastValidInput = nullptr;

        // insert the op according to precedence relationships
        precedence_insert(op, list);
    } else if (input[i] == '(') {
        handled = true;
        handle_parenthesis(
            context, input, i, lastValidInput, handled, accumulated_precedence, list);
    } else if (input[i] == ' ' || input[i] == '\n') {
        handled = true;
        // skip whitespace
    } else if (input[i] == '^') {
        handled = true;
        auto op = new Pow(i);
        op->add_precedence(accumulated_precedence);
        lastValidInput = nullptr;
        precedence_insert(op, list);
    } else if (input[i] == '!') {
        handled = true;
        auto op = new Factorial(i);
        op->add_precedence(accumulated_precedence);
        lastValidInput = nullptr;
        precedence_insert(op, list);
    } else if (input[i] == '%') {
        handled = true;
        auto op = new Modulus(i);
        op->add_precedence(accumulated_precedence);
        lastValidInput = nullptr;
        precedence_insert(op, list);
    }
}

void Interpreter::handle_parenthesis(Interpreter_Context& context, const std::string& input,
    std::string::size_type& i, Symbol*& lastValidInput, bool& handled, int& accumulated_precedence,
    std::list<Symbol*>& master_list)
{
    /* handle parenthesis is a lot like handling a new interpret.
       the difference is that we have to worry about how the calling
       function has its list setup */
    // std::cerr << "Handling an opening parenthesis.\n";

    accumulated_precedence += 6;
    std::list<Symbol*> list;
    handled = false;
    for (++i; i < input.length(); ++i) {
        main_loop(context, input, i, lastValidInput, handled, accumulated_precedence, list);
        if (input[i] == ')') {
            // std::cerr << "Handling a closing parenthesis.\n";
            handled = true;
            //++i;
            accumulated_precedence -= 6;
            break;
        }
    }

    if (master_list.size() > 0 && list.size() > 0) {
        Symbol* lastSymbol = master_list.back();
        auto op = dynamic_cast<Operator*>(lastSymbol);
        auto unary = dynamic_cast<Unary_Operator*>(lastSymbol);

        // is it a node with 2 children?
        if (op) {
            precedence_insert(list.back(), master_list);
        } else if (unary)
        // is it a unary node (like negate)
        {
            precedence_insert(list.back(), master_list);
        } else {
            // is it a terminal node (Number)
            // error
        }
    } else if (list.size() > 0)
        master_list = list;

    list.clear();
}

// Converts a string and context into a parse tree and builds an
// expression tree out of the parse tree.
Expression_Tree Interpreter::interpret(Interpreter_Context& context, const std::string& input)
{
    std::list<Symbol*> list;
    // list.clear ();
    Symbol* lastValidInput = nullptr;
    bool handled = false;
    int accumulated_precedence = 0;

    for (std::string::size_type i = 0; i < input.length(); ++i) {
        main_loop(context, input, i, lastValidInput, handled, accumulated_precedence, list);
    }

    // if the list has an element in it, then return the back of the list.
    if (!list.empty()) {
        // Invoke a recursive Expression_Tree build starting with the
        // root symbol. This is an example of the builder pattern. See
        // pg 97 in GoF book.

        Expression_Tree tree = Expression_Tree(list.back()->build());
        delete list.back();
        return tree;
    }

    // If we reach this, we didn't have any symbols.
    return Expression_Tree();
}

#endif // INTERPRETER_CPP
