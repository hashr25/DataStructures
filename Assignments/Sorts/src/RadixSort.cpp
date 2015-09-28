#include "RadixSort.h"

RadixSort::RadixSort()
{
    //ctor
}

int* RadixSort::intSort(int* array, long size)
{
    int max = getMax(array, size);

    for(long exponent = 1; max/exponent > 0; exponent = exponent * 10)
    {std::cout << "Count sort on exponent " << exponent << std::endl;
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
    int* output = new int[size];std::cout << "Created output array" << std::endl;
    int* count = new int[10];std::cout << "Created count array" << std::endl;

    for(long i = 0; i < size; i++)
    {
        count[ (array[i]/exponent) % 10 ]++;
    }std::cout << "First loop done" << std::endl;

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }std::cout << "Second loop done" << std::endl;

    for(long i = size - 1; i > 0; i--)
    {
        output[count[ ( array[i] / exponent ) % 10 ] - 1] = array[i];
        count[ ( array[i] / exponent ) % 10 ]--;
    }std::cout << "Third loop done" << std::endl;

    for (long i = 0; i < size; i++)
    {
        array[i] = output[i];
    }std::cout << "Fourth loop done" << std::endl;

    std::cout << "Function done" << std::endl;
    return array;
}

long* RadixSort::countSort(long* array, long size, long exponent)
{

    return array;
}
