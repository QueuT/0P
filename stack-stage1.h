/*
 * stack-stage1.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Quincy Breaux
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t
#include <string>  // for stage 1


class stack {
  public:
std::string top(); // non-inline, implemented in stack-stage1.cpp

    // inline definitions, doing nothing at the moment
void push(const std::string &);
    void pop();
    size_t size();
    bool is_empty();
    void resize();

    stack();
    ~stack();
  private:
    std::string *_data; // turning to pointer makes array dynamic
    size_t _size; // index of top element
    size_t _capacity;
};

#endif
