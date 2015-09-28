#include "Queue.h"

Queue::Queue()
{
    head = NULL;
}

Queue::~Queue()
{
    destroy();
}

/// //////////////////////////////////////

void Queue::insert(int value)
{
    Node* currentNode = head;

    while( currentNode -> getNext() != NULL )
    {
        currentNode = currentNode -> getNext();
    }

    Node* newNode = new Node(value);
    currentNode -> setNext(newNode);
}

int Queue::remove()
{
    if( !ifEmpty() )
    {
        int value = 42;

        Node* currentNode = head;

        value = currentNode -> getValue();

        head = currentNode -> getNext();

        delete currentNode;
        currentNode = NULL;

        return value;
    }
}

/// //////////////////////////////////////

bool Queue::ifEmpty()
{
    bool isEmpty = true;

    if(head != NULL)
    {
        isEmpty = false;
    }

    return isEmpty;
}

int Queue::size()
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

void Queue::destroy()
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

void Queue::print()
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
