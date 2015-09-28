#include "Vector.h"

Vector::Vector()
{
    initialize();
}

Vector::~Vector()
{
    destroy();
}

/// /////////////////////////////////////////////////////////////////////////////

void Vector::initialize()
{
    nums = new int(2);
    vectorSize = 0;
    maxSize = 2;
}

void Vector::assign(int position, int value)
{
    if( position >= 0 && position < vectorSize )
    {
        nums[position] = value;
    }
    else
    {
        std::cout << "Out of bounds!" << std::endl;
    }
}

int Vector::at(int position)
{
    if( position >= 0 && position < vectorSize )
    {
        return nums[position];
    }
    else
    {
        std::cout << "Out of bounds!" << std::endl;
        return 0;
    }
}

void Vector::insert(int value)
{
    if( vectorSize == maxSize )
    {
        increaseSize();
    }

    assign(vectorSize, value);
    vectorSize++;
}

/// /////////////////////////////////////////////////////////////////////////////

void Vector::increaseSize()
{
    int* newNums = new int[maxSize*2];
    int* oldNums = nums;

    for(int i = 0; i < vectorSize; i++)
    {
        newNums[i] = oldNums[i];
    }

    delete oldNums;
    nums = newNums;
    maxSize = maxSize * 2;
}

int Vector::size()
{
    return vectorSize;
}

void Vector::print()
{
    for(int i = 0; i < vectorSize; i++)
    {
        std::cout << nums[i] << std::endl;
    }
}

void Vector::destroy()
{
    delete nums;
}
