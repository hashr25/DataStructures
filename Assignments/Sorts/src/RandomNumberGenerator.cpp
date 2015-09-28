#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
{
    srand(time(NULL));
}

int* RandomNumberGenerator::createIntArray(long size)
{
    unsigned int max = 65535;
    int* newArray = new int[size];
srand(time(NULL));
    for(long i = 0; i <size; i++)
    {

        newArray[i] = rand() % max;
    }

    return newArray;
}

long* RandomNumberGenerator::createLongArray(long size)
{
    unsigned long max = 4294967295;
    long* newArray = new long[size];

    for(long i = 0; i<size; i++)
    {
        newArray[i] = rand() % max;
    }

    return newArray;
}

