#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <assert.h>

#include "Node.h"

class Deque
{
public:
    Deque();
    ~Deque();

    void pushFront(int);
    void pushBack(int);

    int popFront();
    int popBack();

    bool ifEmpty();
    int size();
    void destroy();
    void print();

private:
    Node* head;

};
#endif // DEQUE_H
