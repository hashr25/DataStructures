#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <assert.h>

#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void insertFront(int);
    void insertBack(int);
    void insertAfter(int, int);
    void insertBefore(int, int);

    void removeFront();
    void removeBack();
    void removeAfter(int);
    void removeBefore(int);
    void removeValue(int);

    bool ifEmpty();
    int size();
    void destroyList();
    void printList();

    bool ifNodeExists(int);

private:
    Node* head;
};
#endif // LINKEDLIST_H
