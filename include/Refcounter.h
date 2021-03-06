// File name: Refcounter.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a Refcounter class
// Last Changed: 11/20/20
// Honor statement: I have neither given nor received any unauthorized aid on this assignment.
#ifndef REFCOUNTER_H
#define REFCOUNTER_H

/**
 * @class Refcounter
 * @brief This template class provides transparent reference counting
 *        of its template parameter T.
 *
 *        This class can be used to automate the implementation of the
 *        Bridge pattern in C++.
 */
template <typename T> class Refcounter {
public:
    // default Ctor
    Refcounter();

    // Ctor with refcounting functionality
    Refcounter(T* ptr, bool increase_count = false);

    // copy Ctor
    Refcounter(const Refcounter& rhs);

    // Dtor will delete pointer if refcount becomes 0
    virtual ~Refcounter();

    // assignment operator for times when you don't want
    // the reference increased for incoming ptr
    void operator=(T* ptr);

    // assignment operator
    void operator=(const Refcounter& rhs);

    // dereference operator
    T& operator*();

    // dereference operator
    const T& operator*() const;

    // mimic pointer dereferencing
    T* operator->();

    // mimic pointer dereferencing
    const T* operator->() const;

    // get the underlying pointer
    T* get_ptr();

    // get the underlying pointer
    const T* get_ptr() const;

private:
    // implementation of the increment operation
    void increment();

    // implementation of the decrement operation
    void decrement();

    // A shim class that keeps track of the reference count and a
    // pointer to the type T that's reference counted.
    struct Shim {
        // Constructor.
        Shim(T* t);

        // Destructor.
        ~Shim();

        // Pointer to the object that's being reference counted.
        T* t;

        // Current value of the reference count.
        int refcount;
    };

    // Pointer to the Shim.
    Shim* ptr;
};

#include "../src/Refcounter.cpp"

#endif // REFCOUNTER_H
