#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
    ///Nothing to initialize
}

int* InsertionSort::intSort(int* array, long size)
{
    for(long i = 1; i < size; i++)
    {
        long counter = i;
        while( counter > 0 && array[counter-1] > array[counter])
        {
            int temp = array[counter];
            array[counter] = array[counter-1];
            array[counter-1] = temp;

            counter--;
        }
    }

    return array;
}

long* InsertionSort::longSort(long* array, long size)
{
    for(long i = 1; i < size; i++)
    {
        long counter = i;
        while( counter > 0 && array[counter-1] > array[counter])
        {
            long temp = array[counter];
            array[counter] = array[counter-1];
            array[counter-1] = temp;

            counter--;
        }
    }

    return array;
}
