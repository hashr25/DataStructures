#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <math.h> //pow

#include "Sort.h"


class ShellSort : public Sort
{
    public:
        ShellSort();

        int* intSort(int*, long);
        long* longSort(long*, long);
    private:
};

#endif // SHELLSORT_H
