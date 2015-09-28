#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    destroyList();
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void LinkedList::insertFront(int value)
{
    Node* oldHead = head;

    Node* newHead = new Node;
    head = newHead;

    head -> setValue(value);
    head -> setNext(oldHead);
}

void LinkedList::insertBack(int value)
{
    Node* currentNode = head;

    while( currentNode -> getNext() != NULL )
    {
        currentNode = currentNode -> getNext();
    }

    Node* newNode = new Node(value);
    currentNode -> setNext(newNode);
}

void LinkedList::insertAfter(int valueToInsert, int valueBefore)
{
    if( ifNodeExists(valueBefore) )
    {
        Node* currentNode = head;
        Node* nodeAfter = NULL;

        while( currentNode -> getValue() != valueBefore )
        {
            currentNode = currentNode -> getNext();
        }

        nodeAfter = currentNode -> getNext();
        Node* newNode = new Node(valueToInsert);

        newNode -> setNext(nodeAfter);
        currentNode -> setNext(newNode);
    }
}

void LinkedList::insertBefore(int valueToInsert, int valueAfter)
{
    if( ifNodeExists(valueAfter) )
    {
        Node* currentNode = head;
        Node* nodeAfter = currentNode -> getNext();
        Node* nodeToInsert = new Node(valueToInsert);

        while( currentNode -> getNext() -> getValue() != valueAfter )
        {
            currentNode = currentNode -> getNext();
            nodeAfter = nodeAfter -> getNext();
        }

        currentNode -> setNext(nodeToInsert);
        nodeToInsert -> setNext(nodeAfter);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void LinkedList::removeFront()
{
    Node* oldHead = head;
    head = head -> getNext();
    delete oldHead;
    oldHead = NULL;
}

void LinkedList::removeBack()
{
    Node* currentNode = head;
    Node* previousNode = NULL;

    while( currentNode -> getNext() != NULL )
    {
        previousNode = currentNode;
        currentNode = currentNode -> getNext();
    }

    previousNode -> setNext(NULL);
    delete currentNode;
    currentNode = NULL;
}

void LinkedList::removeAfter(int valueBefore)
{
    if( ifNodeExists(valueBefore) )
    {
        Node* currentNode = head;
        Node* previousNode = NULL;

        while( currentNode -> getValue() != valueBefore )
        {
            previousNode = currentNode;
            currentNode = currentNode -> getNext();
        }

        previousNode = currentNode;
        currentNode = currentNode -> getNext();

        previousNode -> setNext( currentNode -> getNext() );
        delete currentNode;
        currentNode = NULL;
    }

}

void LinkedList::removeBefore(int valueAfter)
{
    if( ifNodeExists(valueAfter) )
    {
        Node* currentNode = head;
        Node* previousNode = NULL;

        while( currentNode -> getNext() -> getValue() != valueAfter ) ///This will end when the 'currentNode' is the node before the value
        {
            previousNode = currentNode;
            currentNode = currentNode -> getNext();
        }

        previousNode -> setNext( currentNode -> getNext() );
        delete currentNode;
        currentNode = NULL;
    }
}

void LinkedList::removeValue(int value)
{
    if( ifNodeExists(value) )
    {
        Node* currentNode = head;
        Node* previousNode = NULL;

        while( currentNode -> getValue() != value )
        {
            previousNode = currentNode;
            currentNode = currentNode -> getNext();
        }

        if( currentNode == head )
        {
            head = currentNode -> getNext();
            delete currentNode;
            currentNode = NULL;
        }
        else
        {
            previousNode -> setNext( currentNode -> getNext() );
            delete currentNode;
            currentNode = NULL;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////

bool LinkedList::ifEmpty()
{
    bool isEmpty = true;

    if(head != NULL)
    {
        isEmpty = false;
    }

    return isEmpty;
}

int LinkedList::size()
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

void LinkedList::printList()
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

void LinkedList::destroyList()
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

bool LinkedList::ifNodeExists(int value)
{
    bool nodeExists = false;
    Node* currentNode = head;

    while( currentNode -> getNext() != NULL )
    {
        if( currentNode -> getValue() == value )
        {
            nodeExists = true;
        }

        currentNode = currentNode -> getNext();
    }

    return nodeExists;
}
