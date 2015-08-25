#include "framework.hpp"
#include "algorithm/equilibriumtest.hpp"
#include <algorithm/equilibrium.hpp>

#define TEST(list, expectedOffset) ASSERT_EQUAL(static_cast<size_t>(expectedOffset), algorithm::equilibrium(list))

namespace algorithm
{
    void equilibriumTest()
    {
        {
            std::vector<int> list = { 1 };
            TEST(list, 0);
        }
        {
            std::vector<int> list = { 1, 2 };
            TEST(list, 0);
        }
        {
            std::vector<int> list = { 1, 2, 4 };
            TEST(list, 1);
        }
        {
            std::vector<int> list = { 2, 2, 1 };
            TEST(list, 0);
        }
        {
            std::vector<int> list = { 0, 0, 1, -1, 2, -1 };
            TEST(list, 3);
        }
        {
            std::vector<int> list = { -1, 1, 2, 4, -3, 2 };
            TEST(list, 4);
        }
        {
            std::vector<int> list = { -5, 3, -1, -1, 9, -2, 1 };
            TEST(list, 5);
        }
    }
}