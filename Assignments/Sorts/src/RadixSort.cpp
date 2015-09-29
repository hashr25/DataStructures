#include "RadixSort.h"

RadixSort::RadixSort()
{
    //ctor
}

int* RadixSort::intSort(int* array, long size)
{
    int max = getMax(array, size);

    for(long exponent = 1; max/exponent > 0; exponent = exponent * 10)
    {
        countSort(array, size, exponent);
    }

    return array;
}

long* RadixSort::longSort(long* array, long size)
{
    long max = getMax(array, size);

    for(long exponent = 1; max/exponent > 0; exponent = exponent * 10)
    {
        countSort(array, size, exponent);
    }

    return array;
}


int RadixSort::getMax(int* array, long size)
{
    int max = array[0];

    for(long i = 0; i < size; i++)
    {
        if(max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}

long RadixSort::getMax(long* array, long size)
{
    long max = array[0];

    for(long i = 0; i < size; i++)
    {
        if(max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}


int* RadixSort::countSort(int* array, long size, long exponent)
{
    int* output = new int[size];
    int count[10] = {0};

/// /////////////////////////////////////////////
/// Loop 1
/// Counts occurrences in count array
    for(long i = 0; i < size; i++)
    {
        count[ ((array[i]/exponent) % 10 ) ]++;
    }


/// /////////////////////////////////////////////
/// Loop 2
/// Switches count array to show actual position in output array
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }


/// /////////////////////////////////////////////
/// Loop 3
/// Builds the output array
    for(long i = size - 1; i >= 0; i--)
    {
        output[count[ (array[i]/exponent)%10 ] - 1] = array[i];

        count[ (array[i]/exponent)%10 ]--;
    }

/// /////////////////////////////////////////////
/// Loop 4
/// Copies output array to actual array
    for (long i = 0; i < size; i++)
    {
        array[i] = output[i];
    }


    delete output;


    return array;
}

long* RadixSort::countSort(long* array, long size, long exponent)
{

    return array;
}
