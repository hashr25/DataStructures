#include "SortTest.h"

SortTest::SortTest(Sort* sort)
{
    this -> sort = sort;
}

void SortTest::testSuite()
{
    long size = 10;

    for(int i = 0; i < 6; i++) ///This is just to go from 10 to 1M
    {
        int* array = new int[size];
        array = rng.createIntArray(size);

        time.startTimer();
        sort -> intSort(array,size);

        std::cout << "***************************************" << std::endl;
        std::cout << "Results for set " << size << std::endl;
        time.endTimer();
        std::cout << "***************************************" << std::endl;

        delete array;
        size = size * 10;
    }
}
