// todo 
// Vector
// Directory
// Key value pair
// Hashmap
// Project euler
#include <iostream>
#include "euler.h"
#include "timer.h"

int main()
{
    std::cout << "Hello? Is this thing on?" << std::endl << std::endl << std::endl;

    // #1
    Timer::Start();
    int sum3and5 = Euler::Multiples3And5();
    Timer::Stop();
    std::cout << "1: Sum of multiples of 3 and 5 under 1000:" << std::endl << sum3and5 << std::endl;
    Timer::PrintDuration();
    std::cout << std::endl << std::endl;

    // #2
    Timer::Start();
    int sumEvenFibo = Euler::EvenFibonacci();
    Timer::Stop();
    std::cout << "2: Sum of even Fibonacci numbers under 4,000,000:" << std::endl << sumEvenFibo << std::endl;
    Timer::PrintDuration();
    std::cout << std::endl << std::endl;

    // #3
    Timer::Start();
    int largestFactor = Euler::LargestFactor();
    Timer::Stop();
    std::cout << "The largest prime factor of 600851475143:" << std::endl << largestFactor << std::endl;
    Timer::PrintDuration();
    std::cout << std::endl << std::endl;

    // #4 
    Timer::Start();
    int palindromeProd = Euler::PalindromeProd();
    Timer::Stop();
    std::cout << "The largest palindrome of a 3 digit product:" << std::endl << palindromeProd << std::endl;
    Timer::PrintDuration();
    std::cout << std::endl << std::endl;

    // #5
    Timer::Start();
    int divBy1To20 = Euler::DivBy1To20();
    Timer::Stop();
    std::cout << "First number dividable by 1 to 20:" << std::endl << divBy1To20 << std::endl;
    Timer::PrintDuration();
    std::cout << std::endl << std::endl;

    // #6
    Timer::Start();
    int sumSquareDifference = Euler::SumSquareDifference();
    Timer::Stop();
    std::cout << "The sum sqare sqaure sum difference of the first 100 natural numbers is:" << std::endl << sumSquareDifference << std::endl;
    Timer::PrintDuration();
    std::cout << std::endl << std::endl;

    // #7
    Timer::Start();
    int nthPrime = Euler::TenKOnePrime();
    Timer::Stop();
    std::cout << "The 10001th prime:" << std::endl << nthPrime << std::endl;
    Timer::PrintDuration();
    std::cout << std::endl << std::endl;

    return 0;
}