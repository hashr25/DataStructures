#include <iostream>

#include "Heap.h"

using namespace std;

Heap createTestMinHeap();
Heap createTestMaxHeap();

int main()
{
    Heap minHeap = createTestMinHeap();
    Heap maxHeap = createTestMaxHeap();

    cout << "Min Heap Test: " << endl;
    minHeap.BreadthFirstTraversal();
    minHeap.DepthFirstPreOrder();
    minHeap.DepthFirstInOrder();
    minHeap.DepthFirstPostOrder();

    cout << "\n\n\nInserting 21 in min heap" << endl;
    minHeap.insertMinHeap(21);
    minHeap.BreadthFirstTraversal();
    minHeap.DepthFirstPreOrder();
    minHeap.DepthFirstInOrder();
    minHeap.DepthFirstPostOrder();

    cout << "\n\n\nDeleteing 65 from min heap" << endl;
    minHeap.deleteMaxHeap(65);
    minHeap.BreadthFirstTraversal();
    minHeap.DepthFirstPreOrder();
    minHeap.DepthFirstInOrder();
    minHeap.DepthFirstPostOrder();

    /** HeapSort Broken
    cout << "\n\n\nRunning sort on min heap" << endl;
    minHeap.heapSort();
    minHeap.BreadthFirstTraversal();
    minHeap.DepthFirstPreOrder();
    minHeap.DepthFirstInOrder();
    minHeap.DepthFirstPostOrder();*/




    ///Max Heap
    cout << "\n\n\n\n\n\n\n\nMax Heap Test: " << endl;
    maxHeap.BreadthFirstTraversal();
    maxHeap.DepthFirstPreOrder();
    maxHeap.DepthFirstInOrder();
    maxHeap.DepthFirstPostOrder();

    cout << "\n\n\nInserting 72 in max heap" << endl;
    maxHeap.insertMaxHeap(72);
    maxHeap.BreadthFirstTraversal();
    maxHeap.DepthFirstPreOrder();
    maxHeap.DepthFirstInOrder();
    maxHeap.DepthFirstPostOrder();

    cout << "\n\n\nDeleting 50 from max heap" << endl;
    maxHeap.deleteMaxHeap(50);
    maxHeap.BreadthFirstTraversal();
    maxHeap.DepthFirstPreOrder();
    maxHeap.DepthFirstInOrder();
    maxHeap.DepthFirstPostOrder();

    return 0;
}

Heap createTestMinHeap()
{
    Heap toReturn(100);

    toReturn.insertMinHeap(50);
    toReturn.insertMinHeap(40);
    toReturn.insertMinHeap(30);
    toReturn.insertMinHeap(20);
    toReturn.insertMinHeap(10);
    toReturn.insertMinHeap(5);
    toReturn.insertMinHeap(15);
    toReturn.insertMinHeap(25);
    toReturn.insertMinHeap(35);
    toReturn.insertMinHeap(45);
    toReturn.insertMinHeap(55);
    toReturn.insertMinHeap(65);
    toReturn.insertMinHeap(75);
    toReturn.insertMinHeap(85);
    toReturn.insertMinHeap(95);

    return toReturn;
}

Heap createTestMaxHeap()
{
    Heap toReturn(100);

    toReturn.insertMaxHeap(50);
    toReturn.insertMaxHeap(40);
    toReturn.insertMaxHeap(30);
    toReturn.insertMaxHeap(20);
    toReturn.insertMaxHeap(10);
    toReturn.insertMaxHeap(5);
    toReturn.insertMaxHeap(15);
    toReturn.insertMaxHeap(25);
    toReturn.insertMaxHeap(35);
    toReturn.insertMaxHeap(45);
    toReturn.insertMaxHeap(55);
    toReturn.insertMaxHeap(65);
    toReturn.insertMaxHeap(75);
    toReturn.insertMaxHeap(85);
    toReturn.insertMaxHeap(95);

    return toReturn;
}
