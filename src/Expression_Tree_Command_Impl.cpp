// File name: Expression_Tree_Command_Impl.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements an Expression_Tree_Command_Impl class
// Last Changed: 11/20/20
#include "Expression_Tree_Command_Impl.h"
#include "Expression_Tree_Command_Factory_Impl.h"
#include "Expression_Tree_Context.h"
#include <algorithm>
#include <functional>
#include <iostream>

Expression_Tree_Command_Impl::Expression_Tree_Command_Impl(Expression_Tree_Context& context)
    : tree_context(context)
{
}

Format_Command::Format_Command(Expression_Tree_Context& context, const std::string& new_format)
    : Expression_Tree_Command_Impl(context)
    , format(new_format)
{
}

bool Format_Command::execute()
{
    tree_context.format(format);
    return true;
}

Expr_Command::Expr_Command(Expression_Tree_Context& context, const std::string& new_expr)
    : Expression_Tree_Command_Impl(context)
    , expr(new_expr)
{
}

bool Expr_Command::execute()
{
    tree_context.make_tree(expr);
    return true;
}

Print_Command::Print_Command(Expression_Tree_Context& context, const std::string& print_format)
    : Expression_Tree_Command_Impl(context)
    , format(print_format)
{
}

bool Print_Command::execute()
{
    tree_context.print(format);
    return true;
}

Eval_Command::Eval_Command(Expression_Tree_Context& context, const std::string& eval_format)
    : Expression_Tree_Command_Impl(context)
    , format(eval_format)
{
}

bool Eval_Command::execute()
{
    tree_context.evaluate(format);
    return true;
}

Set_Command::Set_Command(Expression_Tree_Context& context, const std::string& pair)
    : Expression_Tree_Command_Impl(context)
    , key_value_pair(pair)
{
}

bool Set_Command::execute()
{
    tree_context.set(key_value_pair);
    return true;
}

Get_Command::Get_Command(Expression_Tree_Context& context, const std::string& key_value_pair)
    : Expression_Tree_Command_Impl(context)
    , variable(key_value_pair)
{
}

List_Command::List_Command(Expression_Tree_Context& context)
    : Expression_Tree_Command_Impl(context)
{
}

bool List_Command::execute()
{
    tree_context.list();
    return true;
}

History_Command::History_Command(Expression_Tree_Context& context)
    : Expression_Tree_Command_Impl(context)
{
}

bool History_Command::execute()
{
    tree_context.history();
    return true;
}

bool Get_Command::execute()
{
    tree_context.get(variable);
    return true;
}

Quit_Command::Quit_Command(Expression_Tree_Context& context)
    : Expression_Tree_Command_Impl(context)
{
}

bool Quit_Command::execute()
{
    return false;
}

Macro_Command::Macro_Command(
    Expression_Tree_Context& context, const std::vector<Expression_Tree_Command>& macro_commands)
    : Expression_Tree_Command_Impl(context)
    , macro_commands_(macro_commands)
{
}

bool Macro_Command::execute()
{
    std::for_each(macro_commands_.begin(), macro_commands_.end(),
        std::mem_fn(&Expression_Tree_Command::execute));

    return true;
}

Null_Command::Null_Command(Expression_Tree_Context& context)
    : Expression_Tree_Command_Impl(context)
{
}

bool Null_Command::execute()
{
    return true;
}
