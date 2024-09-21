/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Quincy Breaux
 */

#include "stack-stage1.h"
#include <string>


stack::stack() {
    _size = 0;
    _capacity = 1;
    _data = new std::string[_capacity];

    }


stack::~stack() {
    delete[] _data;
} //BIG 3
std::string stack::top() {
    if (_size > 0) {
        return _data[_size-1];
    }
    return "";
}


void stack::push(const std::string &value) {
    if (_size == _capacity) {
        resize();
    } 
    _data[_size] = value;
    _size++;
}


void stack::resize(){
    _capacity *= 2;
    std::string *new_data = new std::string[_capacity];

    for (size_t i = 0; i < _size; i++) {
        new_data[i] = _data[i];
    }

    delete[] _data;
    _data = new_data;

}



void stack::pop() {
    if (_size > 0) {
        _size--;

    } 
}

size_t stack::size() {
    return _size;
}

bool stack::is_empty() {
    return _size == 0;
}





