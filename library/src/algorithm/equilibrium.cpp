#include "algorithm/equilibrium.hpp"
#include <vector>

namespace algorithm
{
    size_t equilibrium(const std::vector<int>& values)
    {
        if (values.size() < 3)
        {
            return 0;
        }

        int sumLeft = values[0];
        int sumRight = values[1];
        int delta;

        for (size_t i = 2; i < values.size(); i++)
        {
            sumRight += values[i];
        }
        delta = abs(sumRight - sumLeft);

        int minimumPivot = 0;
        int minimumDelta = delta;

        for (size_t pivot = 1; pivot < values.size() - 1; pivot++)
        {
            sumLeft += values[pivot];
            sumRight -= values[pivot];
            delta = abs(sumRight - sumLeft);

            if (delta <= minimumDelta)
            {
                minimumPivot = pivot;
                minimumDelta = delta;
            }
        }

        return minimumPivot;
    }
}