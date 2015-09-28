#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <stdlib.h>
#include <time.h>
#include <climits>

class RandomNumberGenerator
{
    public:
        RandomNumberGenerator();

        int* createIntArray(long);
        long* createLongArray(long);
    private:
};

#endif // RANDOMNUMBERGENERATOR_H
