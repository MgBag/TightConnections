#include "euler.h"
#include "math.h"
#include <iostream>

int Euler::Multiples3And5()
{
    int sum = 0, i = 0, three = 0, five = 0;
    while (++i)
    { 
        three = i * 3;
        five = i * 5;

        if (three < 1000)
        {
            sum += three;
        }
        if (five < 1000 && five % 3 != 0)
        {
            sum += five;
        }
        if (!(five < 1000 || three < 1000))
        {
            break;
        }

    }
    return sum;
}

int Euler::EvenFibonacci()
{
    int sum = 0;
    int newFib = 0, fib = 1, lastFib = 1;
    while ((newFib = fib + lastFib) < 4000000)
    {
        lastFib = fib;
        fib = newFib;
        if (!(fib % 2))
        {
            sum += fib;
        }
    }
    return sum;
}

int Euler::LargestFactor()
{
    //// Find biggest prime factor of 600851475143: 1110.47ms
    //const size_t num = 600851475143;
    //for (size_t i = 2; i < num; ++i)
    //    if (num % i == 0)
    //        if (IsPrimeSlow(num / i))
    //            return num/i;

    // Euler pdf first entry to compare speeds: 0.072ms
    size_t factor = 2, lastFactor = 1, n = 600851475143;
    while (n > 1)
    {
        if (n % factor == 0)
        {
            lastFactor = factor;
            n /= factor;
            while (n % factor == 0)
                n /= factor;
        }
        ++factor;
    }
    return (int)lastFactor;

    return 0;
}

int Euler::SumSquareDifference()
{
    int sumSquare = 0, squareSum = 0;

    for (int i = 1; i <= 100; ++i)
    {
        sumSquare += i * i;
        squareSum += i;
    }
    return squareSum* squareSum - sumSquare;
}

int Euler::DivBy1To20()
{
    //// First try before reading pdf explaining prime factorization 586ms
    //size_t i = 2520;
    //while (i += 20)
    //{
    //    bool divByAll = true;
    //    for (size_t j = 1; j <= 20; ++j)
    //    {
    //        if (i % j)
    //        {
    //            divByAll = false;
    //            break;
    //        }
    //    }

    //    if (divByAll)
    //        return (int)i;
    //}
    //return 0;
    
    // Second try after reading pdf: 0.016ms
    size_t* primes;
    size_t primeSize = EratosthenesPrime(20, &primes);
    size_t max = 20, result = 1;
    for (size_t i = 0; i < primeSize; ++i)
    {
        for (size_t j = 2;; ++j)
        {
            if ((size_t)pow(primes[i], j) > max)
            {
                result *= (size_t)pow(primes[i], j - 1);
                break;
            }
        }
    }
    return result;

}

int Euler::PalindromeProd()
{
    // try in steps of 100, 
    int max = 0;

    for (int k = 9; k > 0; --k)
    {
        int step = k * 100;

        for (int i = 99; i >= 0; --i)
        {
            for (int j = 99; j >= 0; --j)
            {
                int prod = (i + step) * (j + step);
                if (prod > max && IsPalinDrome(prod))
                {
                    max = prod;
                }
            }
        }
    }

    return max;
}

int Euler::TenKOnePrime()
{
    // finding the 10001th prime
    //printf("%u %u %u %u %u %u %u %u %u %u \n", NthPrime(1), NthPrime(2), NthPrime(3), NthPrime(4), NthPrime(5), NthPrime(6), NthPrime(7), NthPrime(8), NthPrime(9), NthPrime(10));
    
    return NthPrime(10001);
}
