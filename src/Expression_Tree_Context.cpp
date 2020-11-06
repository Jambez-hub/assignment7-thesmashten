/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Expression_Tree_Context.h"
#include <cstdlib>

Expression_Tree_Context::Expression_Tree_Context()
    : treeState(new Uninitialized_State)
    , isFormatted(false)
{
}

void Expression_Tree_Context::format(const std::string& new_format)
{
    treeState->format(*this, new_format);
    // we only reach here if the format was successful, and once
    // this is set, we will always have at least one valid format
    // because we store the last valid command (which would have
    // a valid format, if this format function has ever been successfully ran
    isFormatted = true;
}

void Expression_Tree_Context::make_tree(const std::string& expression)
{
    treeState->make_tree(*this, expression);
}

void Expression_Tree_Context::print(const std::string& format)
{
    treeState->print(*this, format);
}

void Expression_Tree_Context::evaluate(const std::string& format)
{
    treeState->evaluate(*this, format);
}

void Expression_Tree_Context::set(const std::string& key_value_pair)
{
    // this is quite enough function calls.
    // we'll just go ahead and parse all of this now.
    std::string input = key_value_pair;
    // used for keeping track of found characters
    std::string::size_type pos;
    // get rid of all spaces
    while ((pos = input.find(' ')) != std::string::npos)
        input.erase(pos, 1);

    // input should be key=value
    if ((pos = input.find('=')) != std::string::npos) {
        // if the position is not the first char (eg '=value')
        // and position is not the last char (eg 'key=')
        // then split the string and set the interpreter context
        // accordingly
        if (pos != 0 && pos < input.length() - 1) {
            std::string key = input.substr(0, pos);
            std::string value = input.substr(pos + 1);

            int_context.set(key, atoi(value.c_str()));
        } else
            throw std::domain_error("Must be in the form key=value");
    } else
        throw std::domain_error("Must have = sign present");
}

Expression_Tree_State* Expression_Tree_Context::state() const
{
    return treeState.get();
}

void Expression_Tree_Context::state(Expression_Tree_State* state)
{
    treeState.reset(state);
}

Expression_Tree& Expression_Tree_Context::tree()
{
    return expTree;
}

void Expression_Tree_Context::tree(const Expression_Tree& tree)
{
    expTree = tree;
}
