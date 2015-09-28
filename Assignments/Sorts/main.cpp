#include <iostream>

#include "Timer.h"
#include "RandomNumberGenerator.h"

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "QuickSort.h"

#include "SortTest.h"

void printArray(int*, long);
void printArray(long*, long);

int main()
{
/*
    long size = 10000;
    int* array = new int[size];

    Timer timer;
    RandomNumberGenerator rng;
    QuickSort sort;

    array = rng.createIntArray(size);

    //printArray(array,size);

    timer.startTimer();
    sort.intSort(array, size);
    timer.endTimer();


    //printArray(array,size);

    std::cout << "It took " << timer.getTime() << " seconds." << std::endl;

    delete array;
*/

    Sort* sort = new ShellSort;
    SortTest test(sort);
    test.testSuite();

    return 0;
}

void printArray(int* array, long size)
{
    for(long i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

void printArray(long* array, long size)
{
    for(long i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}
