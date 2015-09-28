#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "Sort.h"


class RadixSort : public Sort
{
    public:
        RadixSort();

        int* intSort(int*, long);
        long* longSort(long*, long);

    private:
        int getMax(int*, long);
        long getMax(long*, long);

        int* countSort(int*, long, long);
        long* countSort(long*, long, long);


};

#endif // RADIXSORT_H
