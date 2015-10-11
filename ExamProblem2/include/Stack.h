#ifndef STACK_H
#define STACK_H

#include <iostream> //std::cout, std::endl //Used for testing purposes

#include "Node.h"


class Stack
{
    public:
        Stack();
        ~Stack();

        void push(char);
        char pop();

        bool ifEmpty();
        void printStack();

    private:
        Node* head;
        int size;


        void crashStack();
};

#endif // STACK_H
