#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <assert.h>

#include "Node.h"

class Queue
{
public:
    Queue();
    ~Queue();

    void insert(int);
    int remove();

    bool ifEmpty();
    int size();
    void destroy();
    void print();

private:
    Node* head;

};
#endif // QUEUE_H
