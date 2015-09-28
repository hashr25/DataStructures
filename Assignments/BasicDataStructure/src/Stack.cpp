#include "Stack.h"

Stack::Stack()
{
    head = NULL;
}

Stack::~Stack()
{
    destroy();
}

/// //////////////////////////////////////////////////

void Stack::push(int value)
{
    Node* currentNode = head;

    while( currentNode -> getNext() != NULL )
    {
        currentNode = currentNode -> getNext();
    }

    Node* newNode = new Node(value);
    currentNode -> setNext(newNode);
}

int Stack::pop()
{
    if( !ifEmpty() )
    {
        int value = 42;

        Node* currentNode = head;
        Node* previousNode = NULL;

        while( currentNode -> getNext() != NULL )
        {
            previousNode = currentNode;
            currentNode = currentNode -> getNext();
        }

        previousNode -> setNext(NULL);

        value = currentNode -> getValue();

        delete currentNode;
        currentNode = NULL;

        return value;
    }
}

/// //////////////////////////////////////////////////

bool Stack::ifEmpty()
{
    bool isEmpty = true;

    if(head != NULL)
    {
        isEmpty = false;
    }

    return isEmpty;
}

int Stack::size()
{
    int listSize = 0;

    if( !ifEmpty() )
    {
        Node* counter = head;

        while(counter != NULL)
        {
            listSize++;
            counter = counter -> getNext();
        }
    }

    return listSize;
}

void Stack::destroy()
{
    Node* currentNode = head;
    Node* previousNode = NULL;

    while( currentNode -> getNext() != NULL )
    {
        previousNode = currentNode;
        currentNode = currentNode -> getNext();
        delete currentNode;
        currentNode = NULL;
    }

    delete currentNode;
    currentNode = NULL;
}

void Stack::print()
{
    Node* currentNode = head;
    std::cout << "Printing List" << std::endl;

    while( currentNode != NULL )
    {
        std::cout << "Node at: " << currentNode << "   Value: " << currentNode -> getValue() << std::endl;
        currentNode = currentNode -> getNext();
    }

    std::cout << "End List Printing" << std::endl;
}
