#include "SelectionSort.h"

SelectionSort::SelectionSort()
{
    //ctor
}

int* SelectionSort::intSort(int* array, long size)
{
    for(long i = 0; i < size; i++)
    {
        long currentMin = i;

        for(int j = i+1; j < size; j++)
        {
            if(array[j] < array[currentMin])
            {
                currentMin = j;
            }
        }

        if(currentMin != i)
        {
            int temp = array[i];
            array[i] = array[currentMin];
            array[currentMin] = temp;
        }
    }
}

long* SelectionSort::longSort(long* array, long size)
{
    for(long i = 0; i < size; i++)
    {
        long currentMin = i;

        for(int j = i+1; j < size; j++)
        {
            if(array[j] < array[currentMin])
            {
                currentMin = j;
            }
        }

        if(currentMin != i)
        {
            long temp = array[i];
            array[i] = array[currentMin];
            array[currentMin] = temp;
        }
    }
}
