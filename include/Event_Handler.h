// File name: Event_Handler.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Event_Handler data structure.
// Last Changed: 11/20/20
#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

// Forward declaration.
class Reactor;

/**
 * @class Event_Handler
 * @brief Provides an abstract interface for handling various types of
 *        events, e.g., input events.
 *
 *         Subclasses read/write input/output on an I/O handle, etc.
 */
class Event_Handler {
public:
    // Destructor can be made private to ensure dynamic allocation.
    virtual ~Event_Handler() = default;

    // Called back by the Reactor when input events occur.
    virtual void handle_input() = 0;
};

#endif // EVENT_HANDLER_H
