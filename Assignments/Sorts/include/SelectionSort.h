#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Sort.h"


class SelectionSort : public Sort
{
    public:
        SelectionSort();

        int* intSort(int*, long);
        long* longSort(long*, long);
    private:
};

#endif // SELECTIONSORT_H
