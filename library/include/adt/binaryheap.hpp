#ifndef __ADT_BINARY_HEAP_HPP__
#define __ADT_BINARY_HEAP_HPP__

#include <ostream>
#include <vector>

namespace adt
{
    enum HeapSortTraits
    {
        MinimumHeap,
        MaximumHeap
    };

    template<typename T, HeapSortTraits SortTrait = HeapSortTraits::MinimumHeap>
    class BinaryHeap
    {
    public:
        BinaryHeap();
        BinaryHeap(const std::vector<T>& values);

        inline const T& end() const
        {
            return _heap[0];
        }

        inline bool empty() const
        {
            return (_heapSize == 0);
        }

        inline size_t size() const
        {
            return _heapSize;
        }

        T top() const;
        void push(T value);
        T pop();
        std::ostream& write(std::ostream& out) const;

    private:
        size_t maximumChildIndex(size_t index) const;
        size_t minimumChildIndex(size_t index) const;
        void percolateDown(size_t index);
        void percolateUp(size_t index);
        void print(size_t index) const;

        std::vector<T> _heap;
        size_t _heapSize;
    };
}

template<typename T, adt::HeapSortTraits SortTrait>
std::ostream& operator<<(std::ostream& out, const adt::BinaryHeap<T, SortTrait>& heap);

#include "adt/binaryheap.inc.hpp"

#endif