#include "Heap.h"

Heap::Heap(int size)
{
    arraySize = size;
    data = new int[size];
    heapSize = 0;
}

Heap::~Heap()
{
    delete data;
}

/// ////////////////////////////////////////////////////
/// Methods
int Heap::left(int value)
{
    if(ifValueExists(value))
    {
        return data[leftChildIndexOf(findIndexOf(value))];
    }
}

int Heap::right(int value)
{
    if(ifValueExists(value))
    {
        return data[rightChildIndexOf(findIndexOf(value))];
    }
}

int Heap::parent(int value)
{
    if(ifValueExists(value) && data[0] != value)
    {
        return data[parentIndexOf(findIndexOf(value))];
    }
}


void Heap::insertMinHeap(int value)
{
    if(heapSize == arraySize)
    {
        cout << "Heap FULL" << endl;
    }
    else
    {
        data[heapSize] = value;
        minInsertHeapify(heapSize);
        heapSize++;
    }
}

void Heap::insertMaxHeap(int value)
{
    if(heapSize == arraySize)
    {
        cout << "Heap FULL" << endl;
    }
    else
    {
        data[heapSize] = value;
        maxInsertHeapify(heapSize);
        heapSize++;
    }
}



void Heap::deleteMinHeap(int value)
{
    if(ifValueExists(value))
    {
        heapSize--;
        int valueIndex = findIndexOf(value);
        data[valueIndex] = data[heapSize];
        if(heapSize > 0)
        {
            minDeleteHeapify(valueIndex);
        }
    }
}

void Heap::deleteMaxHeap(int value)
{
    if(ifValueExists(value))
    {
        heapSize--;
        int valueIndex = findIndexOf(value);
        data[valueIndex] = data[heapSize];
        if(heapSize > 0)
        {
            maxDeleteHeapify(valueIndex);
        }
    }
}

///Algorithm help taken from wikipedia
void Heap::heapSort()
{
    ///Not sure if I really need to heapify to start sort, since it should already be a heap
    heapify();

    int end = heapSize - 1;
    while(end > 0)
    {
        int swapTemp = data[0];
        data[0] = data[end];
        data[end] = swapTemp;
        minHeapify(0, --end);
    }
}


/// ////////////////////////////////////////////////////
/// Traversals
void Heap::BreadthFirstTraversal()
{
    int depth = 0;
    int counter = 0;

    while(counter <= heapSize)
    {
        for(int i = 0; i < pow(2, depth); i++)
        {
            if(counter < heapSize)
            {
                ///Offsets on first of each line
                if(i == 0)
                {
                    int baseOffset = 30 - (2 * pow(2,depth));
                    for(int j = 0; j < baseOffset; j++)
                        cout << " ";
                }

                cout << " " << data[counter] << " ";
            }

            counter++;
        }
        cout << endl;
        depth++;
    }
}

void Heap::DepthFirstPreOrder()
{
    cout << "Depth-First Pre-Order: " << endl;

    PreOrder(0);

    cout << endl;

}

void Heap::DepthFirstPostOrder()
{
    cout << "Depth-First Post-Order: " << endl;

    PostOrder(0);

    cout << endl;
}

void Heap::DepthFirstInOrder()
{
    cout << "Depth-First In-Order: " << endl;

    InOrder(0);

    cout << endl;
}

/// /////////////////////////////////////////////////
/// Helpers
int Heap::leftChildIndexOf(int baseIndex)
{
    return ((2 * baseIndex) + 1);
}

int Heap::rightChildIndexOf(int baseIndex)
{
    return ((2 * baseIndex) + 2);
}

int Heap::parentIndexOf(int baseIndex)
{
    cout << "parent index of " << baseIndex << " is " << floor((baseIndex - 1) / 2) << endl;
    return floor((baseIndex - 1) / 2);
}

int Heap::findIndexOf(int value)
{
    for(int index = 0; index < heapSize; index++)
    {
        if(data[index] == value)
        {
            return index;
        }
    }
}

bool Heap::ifValueExists(int value)
{
    bool ifExists = false;

    for(int i = 0; i < heapSize; i++)
    {
        if(data[i] == value)
        {
            ifExists = true;
        }
    }

    return ifExists;
}

void Heap::minInsertHeapify(int index)
{
    if(index != 0)
    {
        int parentIndex = parentIndexOf(index);

        if(data[parentIndex] > data[index])
        {
            int swapTemp = data[index];
            data[index] = data[parentIndex];
            data[parentIndex] = swapTemp;
            minInsertHeapify(parentIndex);
        }
    }
}

void Heap::maxInsertHeapify(int index)
{
    if(index != 0)
    {
        int parentIndex = parentIndexOf(index);

        if(data[parentIndex] < data[index])
        {
            int swapTemp = data[index];
            data[index] = data[parentIndex];
            data[parentIndex] = swapTemp;
            maxInsertHeapify(parentIndex);
        }
    }
}

void Heap::minDeleteHeapify(int index)
{
    int leftChildIndex = leftChildIndexOf(index);
    int rightChildIndex = rightChildIndexOf(index);
    int minimumIndex = 0;

    if(rightChildIndex >= heapSize)
    {
        if(leftChildIndex < heapSize)
        {
            minimumIndex = leftChildIndex;
        }
    }
    else
    {
        if(data[leftChildIndex] <= data[rightChildIndex])
        {
            minimumIndex = leftChildIndex;
        }
        else
        {
            minimumIndex = rightChildIndex;
        }
    }

    if(data[index] > data[minimumIndex])
    {
        int swapTemp = data[index];
        data[index] = data[minimumIndex];
        data[minimumIndex] = swapTemp;
        minDeleteHeapify(minimumIndex);
    }
}

void Heap::maxDeleteHeapify(int index)
{
    int leftChildIndex = leftChildIndexOf(index);
    int rightChildIndex = rightChildIndexOf(index);
    int maximumIndex = 0;

    if(rightChildIndex >= heapSize)
    {
        if(leftChildIndex < heapSize)
        {
            maximumIndex = leftChildIndex;
        }
    }
    else
    {
        if(data[leftChildIndex] >= data[rightChildIndex])
        {
            maximumIndex = leftChildIndex;
        }
        else
        {
            maximumIndex = rightChildIndex;
        }
    }

    if(data[index] > data[maximumIndex])
    {
        int swapTemp = data[index];
        data[index] = data[maximumIndex];
        data[maximumIndex] = swapTemp;
        maxDeleteHeapify(maximumIndex);
    }
}

void Heap::minHeapify(int start, int end)
{
    int beginning = start;
    while(leftChildIndexOf(beginning) <= end)
    {
        int child = leftChildIndexOf(beginning);

        if(child < end && data[child] < data[child + 1])
        {
            child++;
        }

        if(data[beginning] < data[child])
        {
            int swapTemp = data[child];
            data[child] = data[beginning];
            data[beginning] = swapTemp;
            beginning = child;
        }
    }
}

void Heap::heapify()
{
    for(int start = heapSize / 2; start >= 0; --start)
    {
        minHeapify(start, heapSize-1);
    }
}

void Heap::PreOrder(int index)
{
    if(index < heapSize)
    {
        cout << data[index] << " - ";
        PreOrder(leftChildIndexOf(index));
        PreOrder(rightChildIndexOf(index));
    }
}

void Heap::PostOrder(int index)
{
    if(index < heapSize)
    {
        PostOrder(leftChildIndexOf(index));
        PostOrder(rightChildIndexOf(index));
        cout << data[index] << " - ";
    }
}

void Heap::InOrder(int index)
{
    if(index < heapSize)
    {
        InOrder(leftChildIndexOf(index));
        cout << data[index] << " - ";
        InOrder(rightChildIndexOf(index));
    }
}
