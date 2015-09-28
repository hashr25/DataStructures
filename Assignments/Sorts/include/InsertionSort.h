#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sort.h"


class InsertionSort : public Sort
{
    public:
        InsertionSort();

        int* intSort(int*, long);
        long* longSort(long*, long);
    private:
};

#endif // INSERTIONSORT_H
