#include "QuickSort.h"

QuickSort::QuickSort()
{
    //ctor
}

int* QuickSort::intSort(int* array, long size)
{
    qSort(array, 0, size);
}

long* QuickSort::longSort(long* array, long size)
{
    //qSort(array, 0, size);
}

void QuickSort::qSort(int* array, long left, long right)
{
    long swapLeft = left;
    long swapRight = right;
    long pivot = array[(left+right)/2];

    while(swapLeft <= swapRight)
    {
        while(array[swapLeft] < pivot)
        {
            swapLeft++;
        }
        while(array[swapRight] > pivot)
        {
            swapRight--;
        }
        if(swapLeft <= swapRight)
        {
            int temp = array[swapLeft];
            array[swapLeft] = array[swapRight];
            array[swapRight] = temp;

            swapLeft++;
            swapRight--;
        }
    }

    if(left < swapRight)
    {
        qSort(array, left, swapRight);
    }
    if(swapLeft < right)
    {
        qSort(array, swapLeft, right);
    }
}
