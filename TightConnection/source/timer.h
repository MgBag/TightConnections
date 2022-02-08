#pragma once
#include <chrono>
#include <iostream>

class Timer
{
    Timer();
    ~Timer();

    static bool m_isRunning;
    static std::chrono::system_clock::time_point m_startTime;
    static std::chrono::system_clock::time_point m_endTime;
public:
    static void Start()
    {
        m_isRunning = true;
        m_startTime = std::chrono::system_clock::now();
    }

    static void Stop()
    {
        m_endTime = std::chrono::system_clock::now();
        m_isRunning = false;
    }

    static void PrintDuration()
    {
        if (m_isRunning)
        {
            std::cout << "Carefull now, the timer is running, please implement more features" << std::endl;
        }

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(m_endTime - m_startTime).count();
        if (duration != 0)
        {
            double decimalMs = static_cast<double>(duration) / 1000.0;
            std::cout << "Operation took " << decimalMs << "ms" << std::endl;
        }
        else
        {
            std::cout << "Operation was super fast k" << std::endl;
        }
    }

};

bool Timer::m_isRunning = false;
std::chrono::system_clock::time_point Timer::m_startTime;
std::chrono::system_clock::time_point Timer::m_endTime;
