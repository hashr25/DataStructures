#include "Node.h"

Node::Node()
{
    next = new Node;
}

Node::Node(int val) : value(val)
{
    next = new Node;
}

Node::Node(int val, Node* nex) : value(val), next(nex)
{
    //Init list assignment
}

Node::~Node()
{
    delete next; ///Self Destructing Linked Lists via Node Destructors.
}

void Node::setValue(int value)
{
    this -> value = value;
}

void Node::setNext(Node* next)
{
    this -> next = next;
}

int Node::getValue()
{
    return value;
}

Node* Node::getNext()
{
    return next;
}
