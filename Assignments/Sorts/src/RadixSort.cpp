#include "RadixSort.h"

RadixSort::RadixSort()
{
    //ctor
}

int* intSort(int* array, long size)
{
    int max = getMax(array, size);

    for(long exponent = 1; max/exponent > 0; exponent = exponent * 10)
    {
        countSort(array, size, exponent);
    }
}

long* longSort(long* array, long size)
{
    long max = getMax(array, size);

    for(long exponent = 1; max/exponent > 0; exponent = exponent * 10)
    {
        countSort(array, size, exponent);
    }
}


int getMax(int* array, long size)
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

long getMax(long* array, long size)
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


int* countSort(int* array, long size, long exponent)
{
    int* output = new int[size];
    int* count = new int[10];

    for(long i = 0; i < size; i++)
    {
        count[ (array[i]/exponent) % 10 ]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for( long i = size - 1; i > 0; i--)
    {
        output[count[ ( array[i] / exponent ) % 10 ] - 1] = array[i];
        count[ ( array[i] / exponent ) % 10 ]--;
    }

    for (i = 0; i < n; i++)
    {
        array[i] = output[i];
    }



}

long* countSort(long* array, long size, long exponent)
{

}
