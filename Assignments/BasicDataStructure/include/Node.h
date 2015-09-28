#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <assert.h>

class Node
{
public:
    Node();
    Node(int);
    Node(int, Node*);
    ~Node();

    void setValue(int);
    void setNext(Node*);

    int getValue();
    Node* getNext();

private:
    int value;
    Node* next;
};

#endif // NODE_H
