#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <math.h>

#include "HeapNode.h"

using namespace std;

/**
 *
 *  Some algorithms help used from
 *  http://www.algolist.net/
 *
 */

class Heap
{
public:
    Heap(int);
    ~Heap();

    int left(int);
    int right(int);
    int parent(int);

    void insertMinHeap(int);
    void insertMaxHeap(int);

    void deleteMinHeap(int);
    void deleteMaxHeap(int);

    void heapSort();

    ///Traversals
    void BreadthFirstTraversal();
    void DepthFirstPreOrder();
    void DepthFirstPostOrder();
    void DepthFirstInOrder();

private:
    int* data;
    int heapSize;
    int arraySize;

    int leftChildIndexOf(int);
    int rightChildIndexOf(int);
    int parentIndexOf(int);
    int findIndexOf(int);
    bool ifValueExists(int);

    void minInsertHeapify(int);
    void maxInsertHeapify(int);
    void minDeleteHeapify(int);
    void maxDeleteHeapify(int);

    void minHeapify(int, int);
    void heapify();

    void PreOrder(int);
    void PostOrder(int);
    void InOrder(int);
};

#endif // HEAP_H
