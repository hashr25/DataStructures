#include "Timer.h"

Timer::Timer()
{
    ///Nothing to initialize
}

void Timer::startTimer()
{
    time(&startTime);
    startClock = clock();
    startTicks = GetTickCount();

    startChrono = std::chrono::high_resolution_clock::now();

    gettimeofday(&startTimeVal, NULL);

    std::cout << "Starting time at " << startTime << std::endl;
}


void Timer::endTimer()
{
    time(&endTime);
    endClock = clock();
    endTicks = GetTickCount();
    endChrono = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> microseconds = std::chrono::duration_cast<duration<double>>(endChrono - startChrono);
    gettimeofday(&endTimeVal, NULL);

    std::cout << "Time   result = " << difftime(endTime, startTime) << std::endl;
    std::cout << "Clock  result = " << (endClock - startClock) / CLOCKS_PER_SEC << std::endl;
    std::cout << "Ticks  result = " << endTicks - startTicks << std::endl;
    std::cout << "Chrono result = " << microseconds.count() << std::endl;
    std::cout << "gettimeofday  = " << ((endTimeVal.tv_sec * 1000000 + endTimeVal.tv_usec) - (startTimeVal.tv_sec * 1000000 + startTimeVal.tv_usec));

    float clockTicks = endTime - startTime;std::cout << "\nclockTicks = " << clockTicks << std::endl;
    timeInSeconds = clockTicks / CLOCKS_PER_SEC;
    std::cout << "Ending time at " << endTime << std::endl;
}

double Timer::getTime()
{
    return timeInSeconds;
}
