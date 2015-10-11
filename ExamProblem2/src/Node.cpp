#include "Node.h"

Node::Node(char value)
{
    setValue(value);
    setNext(NULL);
}

char Node::getValue()
{
    return value;
}

void Node::setValue(char value)
{
    this -> value = value;
}


Node* Node::getNext()
{
    return next;
}

void Node::setNext(Node* next)
{
    this -> next = next;
}
