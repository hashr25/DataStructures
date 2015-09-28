#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
    ///Nothing to initalize
}


int* BubbleSort::intSort(int* array, long size)
{
    long counter = size;
    bool swapped = true;

    while(swapped)
    {
        swapped = false;

        for(int i = 1; i < counter; i++)
        {
            if(array[i-1] > array[i])
            {
                int temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                swapped = true;
            }
        }
    }

    return array;
}

long* BubbleSort::longSort(long array[], long size)
{
    long counter = size;
    bool swapped = true;

    while(swapped)
    {
        swapped = false;

        for(int i = 1; i < counter; i++)
        {
            if(array[i-1] > array[i])
            {
                long temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                swapped = true;
            }
        }
    }

    return array;
}
