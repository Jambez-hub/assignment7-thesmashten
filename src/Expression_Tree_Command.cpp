// File name: Expression_Tree_Command.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements an Expression_Tree_Command class
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#ifndef EXPRESSION_TREE_COMMAND_CPP
#define EXPRESSION_TREE_COMMAND_CPP

#include "Expression_Tree_Command.h"

Expression_Tree_Command::Expression_Tree_Command(Expression_Tree_Command_Impl* impl)
    : command_impl(impl)
{
}

Expression_Tree_Command::Expression_Tree_Command(const Expression_Tree_Command& rhs)
    : command_impl(rhs.command_impl)
{
}

Expression_Tree_Command& Expression_Tree_Command::operator=(const Expression_Tree_Command& rhs)
{
    // check for self assignment first
    if (this != &rhs)
        // we just make use of the Refcounter functionality here
        command_impl = rhs.command_impl;
    return *this;
}

bool Expression_Tree_Command::execute()
{
    return command_impl->execute();
}

#endif // EXPRESSION_TREE_COMMAND_CPP
