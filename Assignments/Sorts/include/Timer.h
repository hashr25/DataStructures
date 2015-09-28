#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <ratio>

using namespace std::chrono;


class Timer
{
    public:
        Timer();

        void startTimer();
        void endTimer();
        double getTime();

    private:
        time_t startTime;
        time_t endTime;

        clock_t startClock;
        clock_t endClock;

        int startTicks;
        int endTicks;

        std::chrono::high_resolution_clock::time_point startChrono;
        std::chrono::high_resolution_clock::time_point endChrono;

        struct timeval startTimeVal;
        struct timeval endTimeVal;

        float timeInSeconds;
};

#endif // TIMER_H
