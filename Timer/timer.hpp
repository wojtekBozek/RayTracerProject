#pragma once

#include <chrono>
#include <iostream>
class Timer
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
        std::chrono::duration<double> duration;
    public:
        Timer()
        {
            start = std::chrono::high_resolution_clock::now();
        }
        std::chrono::duration<double> getTimeStamp()
        {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            return duration;
        }
        ~Timer()
        {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "Time elapsed: " << duration.count() << "\n";
        }        
};