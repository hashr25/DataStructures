#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

#include "Sort.h"


class QuickSort : public Sort
{
    public:
        QuickSort();

        int* intSort(int*, long);
        long* longSort(long*, long);

    private:
        void qSort(int*, long, long);
        void qSort(long*, long, long);
        long partition(int*, long, long);
        long partition(long*, long, long);
};

#endif // QUICKSORT_H
