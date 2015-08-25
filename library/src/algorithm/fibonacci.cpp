#include "algorithm/fibonacci.hpp"
#include <vector>

namespace algorithm
{
    long long fibonacciRecursive(size_t n)
    {
        if (n < 2)
        {
            return n;
        }
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    long long fibonacciIterative(size_t n)
    {
        if (n < 2)
        {
            return n;
        }
        int r0 = 0;
        int r1 = 1;
        for (size_t i = 2; i <= n; i++)
        {
            int r2 = r0 + r1;
            r0 = r1;
            r1 = r2;
        }
        return r1;
    }

    long long fibonacciIterativeCached(size_t n)
    {
        static std::vector<long long> cache = { 0, 1 };
        if (n < cache.size())
        {
            return cache[n];
        }
        for (size_t i = cache.size(); i <= n; i++)
        {
            cache.push_back(cache[n - 2] + cache[n - 1]);
        }
        return cache.back();
    }
}