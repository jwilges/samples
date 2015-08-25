#include "framework.hpp"
#include "algorithm/fibonaccitest.hpp"
#include <algorithm/fibonacci.hpp>
#include <sstream>

namespace algorithm
{
    void fibonacciTest()
    {
        fibonacciFunction methods[] = {
            algorithm::fibonacciRecursive,
            algorithm::fibonacciIterative,
            algorithm::fibonacciIterativeCached
        };
        size_t methodsSize = sizeof(methods) / sizeof(fibonacciFunction);

        long long expectedValues[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
        size_t expectedValuesSize = sizeof(expectedValues) / sizeof(long long);

        for (size_t m = 0; m < methodsSize; m++)
        {
            for (size_t n = 0; n < expectedValuesSize; n++)
            {
                std::stringstream message;
                message << "method: " << m << "; n: " << n;
                ASSERT_EQUAL_DETAIL(expectedValues[n], methods[m](n), message.str());
            }
        }
    }
}