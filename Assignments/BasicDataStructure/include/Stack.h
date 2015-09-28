#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>

#include "Node.h"

class Stack
{
public:
    Stack();
    ~Stack();

    void push(int);
    int pop();

    bool ifEmpty();
    int size();
    void destroy();
    void print();

private:
    Node* head;

};

#endif // STACK_H
