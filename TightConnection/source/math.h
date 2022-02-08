#pragma once
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>

// long long max
// uint64 max
// 9223372036854775807
// 18446744073709551615 

// TODO: Make more efficient use of memory
// Returns the size of outResult, which contains all prime numbers under max
size_t EratosthenesPrime(size_t max, size_t** outResult)
{
    if (max < 2)
        return 0;

    size_t outSize = 0;
    bool* numbers = (bool*)malloc(max);
    if (numbers)
    {
        memset(numbers, 1, max);
        memset(numbers, 0, 2); // 0 and 1 are not prime 

        size_t sqrtMax = (size_t)ceil(sqrt((double)max));
        for (size_t i = 0; i < sqrtMax; ++i)
        {
            if (numbers[i])
            {
                for (size_t j = 2;; ++j)
                {
                    size_t multiple = i * j;
                    if (multiple < max)
                        numbers[multiple] = false;
                    else
                        break;
                }
            }
        }

        for (size_t i = 0; i < max; ++i)
            if (numbers[i])
                ++outSize;

        *outResult = (size_t*)malloc(outSize);
        if (*outResult)
            for (size_t i = 0, j = 0; i < max; ++i)
                if (numbers[i] && j < outSize)
                    (*outResult)[j++] = i;

    }
    else
    {
        std::cout << "failed to alloc " << max << std::endl;
    }
    return outSize;
}

bool IsPrimeSlow(size_t candidate)
{
    if (candidate == 2)
        return true;

    for (int i = 2; i < candidate; ++i)
        if (candidate % i == 0)
            return false;
    return true;
}

bool IsPrime(size_t can)
{
    if (can == 1)
        return false;
    else if (can < 4)
        return true; // 2, 3
    else if (can % 2)
        return false; // 2 is the only even prime
    else if (can % 3)
        return false; 
    else
    {
        // Every prime bigger than 3 is 6k+/-1 
        size_t max = (size_t)sqrt(can), f = 5;

        while (f <= max)
        {
            if (can % f == 0)
                return false;
            if (can % (f + 2) == 0)
                return false;
            f += 6;
        }
    }
    return true;
}

// max 128 digits long
bool IsPalinDrome(size_t num)
{
    if (num <= 10)
        return false;

    // Determin the amount of digits or create a vector implementation (do the vector thing)
    // Put every digit 
    char digits[128];
    memset(digits, 0, 128);
    int count = 0;
    for (; num > 0; ++count)
    {
        digits[count] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < count / 2; ++i)
    {
        if (digits[i] != digits[count - 1 - i])
        {
            return false;
        }
    }

    return true;
}

size_t NthPrime(size_t index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 2;

    size_t n = 3, currentIndex = 2;
    while (currentIndex != index)
    {
        n += 2; 

        if (IsPrimeSlow(n))
            ++currentIndex;
    }

    return n;
}

