#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>

class Vector
{
public:
    Vector();
    ~Vector();

    void initialize();
    void assign(int, int);
    int at(int);
    void insert(int);

    void increaseSize();
    int size();
    void print();
    void destroy();

private:
    int* nums;
    int vectorSize;
    int maxSize;

};

#endif // VECTOR_H
