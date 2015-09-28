#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>

#include "Sort.h"


class BubbleSort : public Sort
{
    public:
        BubbleSort();

        int* intSort(int*, long);
        long* longSort(long*, long);
};

#endif // BUBBLESORT_H
