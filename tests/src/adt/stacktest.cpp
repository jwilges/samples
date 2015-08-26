#include "framework.hpp"
#include "adt/stacktest.hpp"
#include <adt/stack.hpp>
#include <ostream>
#include <sstream>

namespace adt
{
    StackTest::StackTest()
    {
    }

    void StackTest::run()
    {
        testPushRValuePop();
        testPushPopTopSize();
        testCopyConstructor();
        testMoveConstructor();
        testAssignmentOperator();
        testOutputStreamOperator();
    }

    void StackTest::testPushRValuePop()
    {
        adt::Stack<int> stack;

        stack.push(1);
        stack.push(2);
        stack.push(3);

        for (int n = 3; static_cast<size_t>(n) > 0; n--)
        {
            std::stringstream detail;
            detail << "n: " << n;
            const int* lastTop = stack.pop();
            ASSERT_NOT_NULL(lastTop);
            if (lastTop)
            {
                ASSERT_EQUAL_DETAIL(n, *lastTop, detail);
            }
        }
    }

    void StackTest::testPushPopTopSize()
    {
        adt::Stack<int> stack;

        ASSERT_NULL(stack.top());
        ASSERT_NULL(stack.pop());
        ASSERT_EQUAL(static_cast<size_t>(0), stack.size());

        size_t stackSizeToTest = adt::Stack<int>::DEFAULT_RESERVED_SIZE * 2 + 1;
        for (int n = 1; static_cast<size_t>(n) <= stackSizeToTest; n++)
        {
            std::stringstream detail;
            detail << "n: " << n;
            stack.push(n);
            ASSERT_EQUAL_DETAIL(static_cast<size_t>(n), stack.size(), detail);
        }

        for (int n = stackSizeToTest; static_cast<size_t>(n) > 0; n--)
        {
            std::stringstream detail;
            detail << "n: " << n;
            const int* lastTop = stack.pop();
            ASSERT_NOT_NULL(lastTop);
            if (lastTop)
            {
                ASSERT_EQUAL_DETAIL(n, *lastTop, detail);
            }
        }

        ASSERT_NULL(stack.top());
        ASSERT_NULL(stack.pop());
        ASSERT_EQUAL(static_cast<size_t>(0), stack.size());
    }

    void StackTest::testCopyConstructor()
    {
        adt::Stack<int> stackA;

        ASSERT_EQUAL(static_cast<size_t>(0), stackA.size());
        stackA.push(1);
        stackA.push(2);
        stackA.push(3);
        ASSERT_EQUAL(static_cast<size_t>(3), stackA.size());

        adt::Stack<int> stackB(stackA);

        ASSERT_EQUAL(static_cast<size_t>(3), stackB.size());
        for (int n = 3; static_cast<size_t>(n) > 0; n--)
        {
            std::stringstream detail;
            detail << "n: " << n;
            const int* lastTop = stackB.pop();
            ASSERT_NOT_NULL(lastTop);
            if (lastTop)
            {
                ASSERT_EQUAL_DETAIL(n, *lastTop, detail);
            }
        }
    }

    void StackTest::testMoveConstructor()
    {
        adt::Stack<int> stackA;

        ASSERT_EQUAL(static_cast<size_t>(0), stackA.size());
        stackA.push(1);
        stackA.push(2);
        stackA.push(3);
        ASSERT_EQUAL(static_cast<size_t>(3), stackA.size());

        adt::Stack<int> stackB(std::move(stackA));

        ASSERT_EQUAL(static_cast<size_t>(3), stackB.size());
        for (int n = 3; static_cast<size_t>(n) > 0; n--)
        {
            std::stringstream detail;
            detail << "n: " << n;
            const int* lastTop = stackB.pop();
            ASSERT_NOT_NULL(lastTop);
            if (lastTop)
            {
                ASSERT_EQUAL_DETAIL(n, *lastTop, detail);
            }
        }
    }

    void StackTest::testAssignmentOperator()
    {
        adt::Stack<int> stackA;

        ASSERT_EQUAL(static_cast<size_t>(0), stackA.size());
        stackA.push(1);
        stackA.push(2);
        stackA.push(3);
        ASSERT_EQUAL(static_cast<size_t>(3), stackA.size());

        adt::Stack<int> stackB;
        stackB = stackA;

        ASSERT_EQUAL(static_cast<size_t>(3), stackB.size());
        for (int n = 3; static_cast<size_t>(n) > 0; n--)
        {
            std::stringstream detail;
            detail << "n: " << n;
            const int* lastTop = stackB.pop();
            ASSERT_NOT_NULL(lastTop);
            if (lastTop)
            {
                ASSERT_EQUAL_DETAIL(n, *lastTop, detail);
            }
        }
    }

    void StackTest::testOutputStreamOperator()
    {
        static const std::string EMPTY_STRING;
        adt::Stack<int> stack;
        std::stringstream result;

        result << stack;
        ASSERT_EQUAL(EMPTY_STRING, result.str());
        std::stringstream().swap(result);

        stack.push(1);
        result << stack;
        ASSERT_EQUAL(std::string("1"), result.str());
        std::stringstream().swap(result);

        stack.push(2);
        result << stack;
        ASSERT_EQUAL(std::string("1, 2"), result.str());
        std::stringstream().swap(result);

        stack.push(3);
        result << stack;
        ASSERT_EQUAL(std::string("1, 2, 3"), result.str());
        std::stringstream().swap(result);

        stack.pop();
        result << stack;
        ASSERT_EQUAL(std::string("1, 2"), result.str());
        std::stringstream().swap(result);

        stack.pop();
        result << stack;
        ASSERT_EQUAL(std::string("1"), result.str());
        std::stringstream().swap(result);

        stack.pop();
        result << stack;
        ASSERT_EQUAL(EMPTY_STRING, result.str());
        std::stringstream().swap(result);
    }
}