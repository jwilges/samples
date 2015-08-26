#ifndef __ADT_BINARY_HEAP_TEST_HPP__
#define __ADT_BINARY_HEAP_TEST_HPP__

namespace adt
{
    enum HeapSortTraits;

    class BinaryHeapTest
    {
    public:
        BinaryHeapTest();
        void run();

        template<HeapSortTraits SortTrait>
        void testPushPopTopEmptySize(bool reverseTest);
        void testPushPopTopEmptySize();
        void testVectorConstructor();
        void testOutputStreamOperator();
    };
}

#endif