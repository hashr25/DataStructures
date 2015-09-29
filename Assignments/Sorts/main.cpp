#include <iostream>

#include "Timer.h"
#include "RandomNumberGenerator.h"

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "RadixSort.h"

#include "SortTest.h"

void printArray(int*, long);
void printArray(long*, long);

int main()
{
/*
    long size = 10;
    int* array = new int[size];

    Timer timer;
    RandomNumberGenerator rng;
    RadixSort sort;

    array = rng.createIntArray(size);

    printArray(array,size);

    timer.startTimer();
    sort.intSort(array, size);
    timer.endTimer();


    printArray(array,size);

    delete array;
*/

    Sort* sort = new RadixSort;
    SortTest test(sort);
    test.testSuite();

    return 0;
}

void printArray(int* array, long size)
{
    std::cout << "\n\n\nPrinting Array" << std::endl;
    for(long i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

void printArray(long* array, long size)
{
    std::cout << "\n\n\nPrinting Array" << std::endl;
    for(long i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}
