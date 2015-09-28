#include "Array.h"


Array::Array(int arraySize)
{
    initialize(arraySize);
}

Array::~Array()
{
    destroy();
}

/// ////////////////////////////////////////

void Array::initialize(int arraySize)
{
    nums - new int[arraySize];
    this -> arraySize = arraySize;
}

void Array::assign(int position, int value)
{
    if( position >= 0 && position < arraySize )
    {
        nums[position] = value;
    }
    else
    {
        std::cout << "Out of bounds!" << std::endl;
    }
}

int Array::at(int position)
{
    if( position >= 0 && position < arraySize )
    {
        return nums[position];
    }
    else
    {
        std::cout << "Out of bounds!" << std::endl;
        return 0;
    }
}

int Array::size()
{
    return arraySize;
}

void Array::print()
{
    for(int i = 0; i < arraySize; i++)
    {
        std::cout << nums[i] << std::endl;
    }
}

void Array::destroy()
{
    delete nums;
}
