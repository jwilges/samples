#include "adt/stacktest.hpp"

#include "algorithm/fibonaccitest.hpp"
#include "algorithm/equilibriumtest.hpp"

int main(int /*argc*/, char** /*argv*/)
{
    adt::StackTest stackTest;
    stackTest.run();

    algorithm::fibonacciTest();
    algorithm::equilibriumTest();
}