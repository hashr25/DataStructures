#include "ShellSort.h"

ShellSort::ShellSort()
{
    //ctor
}

int* ShellSort::intSort(int* array, long size)
{
    ///Finding size of gaps
    long* gaps = new long[size];
    for(long i = 0; i < size; i++)
    {
        gaps[i] = size / pow(2,i);
    }


    /**
    cols = gaps
    k = outerLoop
    h = currentGapSize
    i = innerLoop
    v = temp
    j = counter
    */

    ///Actual Sort
    for(long outerLoop = 0; outerLoop < size; outerLoop++)
    {
        long currentGapSize = gaps[outerLoop];
        for(long innerLoop = currentGapSize; innerLoop < size; innerLoop++)
        {
            int temp = array[innerLoop];
            long counter = innerLoop;

            while(counter >= currentGapSize && array[counter-currentGapSize] > temp )
            {
                array[counter] = array[counter - currentGapSize];
                counter = counter - currentGapSize;
            }

            array[counter] = temp;
        }
    }

    delete gaps;

    return array;
}

long* ShellSort::longSort(long* array, long size)
{

}
