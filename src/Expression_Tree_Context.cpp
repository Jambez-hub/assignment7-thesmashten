/* Copyright G. Hemingway @ 2019, All Rights Reserved */
#include "Expression_Tree_Context.h"
#include <cstdlib>
#include <string>

Expression_Tree_Context::Expression_Tree_Context()
    : treeState(new Uninitialized_State)
    , isFormatted(false)
{
}

void Expression_Tree_Context::format(const std::string& new_format)
{
    std::string command = "format " + new_format;
    store.push(command);
    treeState->format(*this, new_format);
    // we only reach here if the format was successful, and once
    // this is set, we will always have at least one valid format
    // because we store the last valid command (which would have
    // a valid format, if this format function has ever been successfully ran
    isFormatted = true;
}

void Expression_Tree_Context::make_tree(const std::string& expression)
{
    std::string command = "expr " + expression;
    store.push(command);
    treeState->make_tree(*this, expression);
}

void Expression_Tree_Context::print(const std::string& format)
{
    std::string command = "print " + format;
    store.push(command);
    treeState->print(*this, format);
}

void Expression_Tree_Context::evaluate(const std::string& format)
{
    std::string command = "eval " + format;
    store.push(command);
    treeState->evaluate(*this, format);
}

void Expression_Tree_Context::set(const std::string& key_value_pair)
{
    std::string command = "set " + key_value_pair;
    store.push(command);
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

void Expression_Tree_Context::get(const std::string& variable)
{
    std::string command = "get " + variable;
    store.push(command);
    if (!int_context.search(variable)) // check if variable is not in the map
    {
        std::cout << "Error: unknown variable " << variable;
    } else {
        int value = int_context.get(variable);
        std::cout << value << std::endl;
    }
}

void Expression_Tree_Context::list()
{
    std::string command = "list";
    store.push(command);
    std::cout << "\n";
    for (uint32_t i = 0; i < int_context.size(); ++i) {
        std::cout << int_context.getKey(i);
        std::cout << ": ";
        std::cout << int_context.getVal(i) << std::endl;
    }
    std::cout << "\n";
}

void Expression_Tree_Context::history()
{
    uint32_t count = 1;
    while (!store.empty()) {
        std::cout << "\t" << count << ") " << store.front() << "\n";
        store.pop();
        ++count;
    }
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
