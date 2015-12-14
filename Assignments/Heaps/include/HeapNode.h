#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>

class HeapNode
{
    public:
        HeapNode(int);

        int value;
        HeapNode* leftChild;
        HeapNode* rightChild;
};

#endif // HEAPNODE_H
