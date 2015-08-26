#ifndef __ADT_STACK_TEST_HPP__
#define __ADT_STACK_TEST_HPP__

namespace adt
{
    class StackTest
    {
    public:
        StackTest();
        void run();

        void testPushRValuePop();
        void testPushPopTopSize();
        void testCopyConstructor();
        void testMoveConstructor();
        void testAssignmentOperator();
        void testOutputStreamOperator();
    };
}

#endif