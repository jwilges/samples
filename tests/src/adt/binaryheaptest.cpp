#include "framework.hpp"
#include "adt/binaryheaptest.hpp"
#include <adt/binaryheap.hpp>
#include <ostream>
#include <sstream>
#include <vector>

namespace adt
{
    BinaryHeapTest::BinaryHeapTest()
    {
    }

    void BinaryHeapTest::run()
    {
        testPushPopTopEmptySize();
        testVectorConstructor();
        testOutputStreamOperator();
    }

    template<HeapSortTraits SortTrait>
    void BinaryHeapTest::testPushPopTopEmptySize(bool reverseTest)
    {
        std::vector<int> pushValues = { 4, 2, 9, 1, 3, 5, 8, 6, 7 };

        if (reverseTest)
        {
            std::reverse(pushValues.begin(), pushValues.end());
        }

        auto writeDetail = [reverseTest](std::ostream& out, int i = -1) -> void {
            out <<
                ((SortTrait == HeapSortTraits::MinimumHeap) ? "minimum; " : "maximum; ") <<
                ((reverseTest) ? "reverse test" : "forward test");

            if (i >= 0)
            {
                out << "; i: " << i;
            }
        };

        std::stringstream detail;
        writeDetail(detail);

        BinaryHeap<int, SortTrait> heap;

        ASSERT_EQUAL_DETAIL(static_cast<size_t>(0), heap.size(), detail);
        ASSERT_TRUE_DETAIL(heap.empty(), detail);
        ASSERT_EQUAL_DETAIL(heap.end(), heap.top(), detail);

        for (size_t i = 0; i < pushValues.size(); i++)
        {
            std::stringstream detailLoop;
            writeDetail(detailLoop, i);
            heap.push(pushValues[i]);
            ASSERT_EQUAL_DETAIL(i + 1, heap.size(), detailLoop);
            ASSERT_FALSE_DETAIL(heap.empty(), detailLoop);
        }

        for (size_t i = 0; i < pushValues.size(); i++)
        {
            std::stringstream detailLoop;
            writeDetail(detailLoop, i);
            int expectedTop = (SortTrait == HeapSortTraits::MinimumHeap) ?
                static_cast<int>(i + 1) : pushValues.size() - i;
            ASSERT_EQUAL_DETAIL(expectedTop, heap.top(), detailLoop);
            ASSERT_EQUAL_DETAIL(expectedTop, heap.pop(), detailLoop);
            ASSERT_EQUAL_DETAIL(pushValues.size() - i - 1, heap.size(), detailLoop);
        }

        ASSERT_EQUAL_DETAIL(static_cast<size_t>(0), heap.size(), detail);
        ASSERT_TRUE_DETAIL(heap.empty(), detail);
        ASSERT_EQUAL_DETAIL(heap.end(), heap.top(), detail);
    }

    void BinaryHeapTest::testPushPopTopEmptySize()
    {
        testPushPopTopEmptySize<HeapSortTraits::MinimumHeap>(false);
        testPushPopTopEmptySize<HeapSortTraits::MinimumHeap>(true);
        testPushPopTopEmptySize<HeapSortTraits::MaximumHeap>(false);
        testPushPopTopEmptySize<HeapSortTraits::MaximumHeap>(true);
    }

    void BinaryHeapTest::testVectorConstructor()
    {
        std::vector<int> pushValues = { 4, 2, 9, 1, 3, 5, 8, 6, 7 };

        BinaryHeap<int, HeapSortTraits::MinimumHeap> heapA;
        for (size_t i = 0; i < pushValues.size(); i++)
        {
            heapA.push(pushValues[i]);
        }

        BinaryHeap<int, HeapSortTraits::MinimumHeap> heapB(pushValues);

        for (size_t i = 0; i < pushValues.size(); i++)
        {
            std::stringstream detail;
            detail << "i: " << i;
            ASSERT_EQUAL_DETAIL(heapA.pop(), heapB.pop(), detail);
        }

        ASSERT_TRUE(heapA.empty());
        ASSERT_TRUE(heapB.empty());
    }

    void BinaryHeapTest::testOutputStreamOperator()
    {
        static const std::string EMPTY_STRING;
        adt::BinaryHeap<int, HeapSortTraits::MinimumHeap> heap;
        std::stringstream result;

        result << heap;
        ASSERT_EQUAL(EMPTY_STRING, result.str());
        std::stringstream().swap(result);

        heap.push(1);
        result << heap;
        ASSERT_EQUAL(std::string("1"), result.str());
        std::stringstream().swap(result);

        heap.push(2);
        result << heap;
        ASSERT_EQUAL(std::string("1, 2"), result.str());
        std::stringstream().swap(result);

        heap.push(3);
        result << heap;
        ASSERT_EQUAL(std::string("1, 2, 3"), result.str());
        std::stringstream().swap(result);

        heap.pop();
        result << heap;
        ASSERT_EQUAL(std::string("2, 3"), result.str());
        std::stringstream().swap(result);

        heap.pop();
        result << heap;
        ASSERT_EQUAL(std::string("3"), result.str());
        std::stringstream().swap(result);

        heap.pop();
        result << heap;
        ASSERT_EQUAL(EMPTY_STRING, result.str());
        std::stringstream().swap(result);
    }
}