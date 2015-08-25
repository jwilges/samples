#ifndef __ALGORITHM_EQUILIBRIUM_HPP__
#define __ALGORITHM_EQUILIBRIUM_HPP__

#include <vector>

namespace algorithm
{
    // returns the right-most pivot offset in the values vector such that 
    // the difference between the sums of the values around the pivot offset,
    // i.e. sum of values (pivot, end] less sum of values [begin, pivot]),
    // is the minimum.
    //
    // linear time; O(n)
    size_t equilibrium(const std::vector<int>& values);
}

#endif