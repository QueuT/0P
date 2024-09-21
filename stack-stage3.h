/*
 * stack-stage3.h
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


template <typename T>
class stack {
  public:

    //big 3
    //constructor
    stack() {
        _size = 0;
        _capacity = 1;
        _data = new T[_capacity];
    }
    //destructor
    ~stack() {
        delete[] _data;
    }
    //copy constructor
    stack (const stack<T> &other) {
        _size = other._size;
        _capacity = other._capacity;
        _data = new T[_capacity];

        for (size_t i=0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    //assignment operator

    stack& operator=(const stack<T> &other) {
        if (this!= &other) {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            _data = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }




    T top() {
        if (_size > 0) {
            return _data[_size-1];
        }
        return T(); // this is the tempalte vertsion of empty stack
    }
    // inline definitions, doing nothing at the moment
    void push(const T& value) {
        if (_size == _capacity) {
            resize();
        }
        _data[_size] = value;
        _size++;
    }
    void pop() {
        if (_size > 0) {
            _size--;
        }
    }
    size_t size() {
        return _size;
    }
    bool is_empty() {
        return _size == 0;
    }

    void resize() {
        size_t new_capacity = _capacity + 1; //ANALYSIS... ORIGINAL WAS: _capacity * 2
        T *new_data = new T[new_capacity];
        if (_size == _capacity) {
            
            for (size_t i = 0; i < _size; ++i) {
                new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
        }
    }
    
  private:
    T *_data; // turning to pointer makes array dynamic
    size_t _size; // index of top element
    size_t _capacity;
};

#endif
