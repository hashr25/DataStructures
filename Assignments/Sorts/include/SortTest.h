#ifndef SORTTEST_H
#define SORTTEST_H

#include "Timer.h"
#include "RandomNumberGenerator.h"
#include "Sort.h"

class SortTest
{
    public:
        SortTest(Sort*);

        void testSuite();

    private:
        Timer time;
        RandomNumberGenerator rng;
        Sort* sort;

};

#endif // SORTTEST_H
