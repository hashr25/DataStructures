#include "Deque.h"

Deque::Deque()
{
    head = NULL;
}

Deque::~Deque()
{
    destroy();
}

/// ////////////////////////////////////

void Deque::pushFront(int value)
{
    Node* oldHead = head;

    Node* newHead = new Node;
    head = newHead;

    head -> setValue(value);
    head -> setNext(oldHead);
}

void Deque::pushBack(int value)
{
    Node* currentNode = head;

    while( currentNode -> getNext() != NULL )
    {
        currentNode = currentNode -> getNext();
    }

    Node* newNode = new Node(value);
    currentNode -> setNext(newNode);
}

int Deque::popFront()
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

int Deque::popBack()
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

/// ////////////////////////////////////

bool Deque::ifEmpty()
{
    bool isEmpty = true;

    if(head != NULL)
    {
        isEmpty = false;
    }

    return isEmpty;
}

int Deque::size()
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

void Deque::destroy()
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

void Deque::print()
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
