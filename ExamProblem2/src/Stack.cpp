#include "Stack.h"

Stack::Stack()
{
    ///Nothing to initialize
}

Stack::~Stack()
{
    crashStack();
}

void Stack::push(char value)
{
    std::cout << "Before push: "; printStack();
    Node* newNode = new Node(value);
    newNode -> setNext(head);
    head = newNode;
    std::cout << "After push: "; printStack();
}

char Stack::pop()
{std::cout << "Before pop: "; printStack();
    char popped = head -> getValue();
    Node* gettingPopped = head;
    head = head -> getNext();

    delete gettingPopped;
    std::cout << "After pop: "; printStack();
    return popped;
}

bool Stack::ifEmpty()
{
    bool empty = false;

    if(head == NULL)
    {
        empty = true;
    }

    return empty;
}

void Stack::printStack()
{
    Node* currentNode = head;

    while(currentNode != NULL)
    {
        std::cout << currentNode -> getValue() << " ";
        currentNode = currentNode -> getNext();
    }

    std::cout << std::endl;
}

void Stack::crashStack()
{
    while(head != NULL)
    {
        pop();
    }
}
