#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <assert.h>

class Array
{
public:
    Array(int);
    ~Array();

    void initialize(int);
    void assign(int, int);
    int at(int);
    int size();
    void print();
    void destroy();

private:
    int* nums;
    int arraySize;
};

#endif // ARRAY_H
