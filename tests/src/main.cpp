#include "adt/stacktest.hpp"
#include "adt/binaryheaptest.hpp"

#include "algorithm/fibonaccitest.hpp"
#include "algorithm/equilibriumtest.hpp"

int main(int /*argc*/, char** /*argv*/)
{
    adt::StackTest stackTest;
    stackTest.run();

    adt::BinaryHeapTest binaryHeapTest;
    binaryHeapTest.run();

    algorithm::fibonacciTest();
    algorithm::equilibriumTest();
}