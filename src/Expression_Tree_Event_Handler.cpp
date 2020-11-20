// File name: Expression_Tree_Event_Handler.cpp
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class implements an Expression_Tree_Event_Handler class.
// Last Changed: 11/20/20

#ifndef EXPRESSION_TREE_EVENT_HANDLER_CPP
#define EXPRESSION_TREE_EVENT_HANDLER_CPP

#include "Expression_Tree_Event_Handler.h"
#include "Options.h"
#include "Reactor.h"
#include <iostream>

Expression_Tree_Event_Handler* Expression_Tree_Event_Handler::make_handler(bool verbose)
{
    if (verbose)
        return new Verbose_Expression_Tree_Event_Handler;
    else
        return new Macro_Command_Expression_Tree_Event_Handler;
}

void Expression_Tree_Event_Handler::handle_input()
{
    prompt_user();
    std::string input;
    if (!get_input(input))
        Reactor::instance()->end_event_loop();

    Expression_Tree_Command command = make_command(input);
    try {
        if (!execute_command(command)) {
            if (input.empty() || input == "quit") {
                Reactor::instance()->end_event_loop();
            } else {
                std::cout << "Invalid Input" << std::endl;
                tree_context.state()->print_valid_commands(tree_context);
            }
        } else {
            last_valid_command = command;
            if (Options::instance()->verbose())
                tree_context.state()->print_valid_commands(tree_context);
        }
    } catch (Expression_Tree::Invalid_Iterator& e) {
        std::cout << "\nERROR: Bad traversal type (" << e.what() << ")\n";
        tree_context.state()->print_valid_commands(tree_context);
    } catch (Expression_Tree_State::Invalid_State& e) {
        std::cout << "\nERROR: " << e.what() << std::endl;
        tree_context.state()->print_valid_commands(tree_context);
    }
}

bool Expression_Tree_Event_Handler::get_input(std::string& input)
{
    if (input == "quit") {
        return std::cin.fail();
    }
    std::getline(std::cin, input);
    int num = input.find_first_of(" ");
    std::string first;
    std::string second;
    if (num == -1) { // handle error if cannot find the first ocurrence
        first = input;
    } else {
        first = input.substr(0, num);
        second = input.substr(num);
    }
    toLowerCase(first);
    input = first + second;
    return !std::cin.fail();
}

std::string Expression_Tree_Event_Handler::toLowerCase(std::string& input)
{
    std::transform(
        input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c); });
    return input;
}

bool Expression_Tree_Event_Handler::execute_command(Expression_Tree_Command& command)
{
    return command.execute();
}

Expression_Tree_Event_Handler::Expression_Tree_Event_Handler()
    : tree_context()
    , command_factory(tree_context)
    , last_valid_command(new Null_Command(tree_context))
{
}

Verbose_Expression_Tree_Event_Handler::Verbose_Expression_Tree_Event_Handler()
    : prompted(false)
{
}

void Verbose_Expression_Tree_Event_Handler::prompt_user()
{
    if (!prompted) {
        tree_context.state()->print_valid_commands(tree_context);
        prompted = true;
    }
    std::cout << "> ";
    std::cout.flush();
}

Expression_Tree_Command Verbose_Expression_Tree_Event_Handler::make_command(
    const std::string& input)
{
    return command_factory.make_command(input);
}

void Macro_Command_Expression_Tree_Event_Handler::prompt_user()
{
    std::cout << "> ";
    std::cout.flush();
}

Expression_Tree_Command Macro_Command_Expression_Tree_Event_Handler::make_command(
    const std::string& input)
{
    if (input == "")
        return command_factory.make_quit_command(input);

    return command_factory.make_macro_command(input);
}

#endif // EXPRESSION_TREE_EVENT_HANDLER_CPP
