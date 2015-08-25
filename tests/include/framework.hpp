#ifndef __FRAMEWORK_HPP__
#define __FRAMEWORK_HPP__

#include <iostream>
#include <sstream>
#include <string>

namespace framework
{
    void assertFalse(bool actualValue, const std::string& fileName, size_t line, const std::string& detail = "");
    void assertFalse(bool actualValue, const std::string& fileName, size_t line, const std::stringstream& detail);
    void assertTrue(bool actualValue, const std::string& fileName, size_t line, const std::string& detail = "");
    void assertTrue(bool actualValue, const std::string& fileName, size_t line, const std::stringstream& detail);

    template<typename T>
    void assertNull(T* actualValue, const std::string& fileName, size_t line, const std::string& detail = "")
    {
        if (actualValue != nullptr)
        {
            if (detail.size() == 0)
            {
                std::cout << "failure: expected: nullptr; " << fileName.c_str() << ":" << line << std::endl;
            }
            else
            {
                std::cout << "failure: expected: nullptr; " << fileName.c_str() << ":" << line << " (" << detail.c_str() << ")" << std::endl;
            }
        }
    }

    template<typename T>
    void assertNull(T* actualValue, const std::string& fileName, size_t line, const std::stringstream& detail)
    {
        assertNull(actualValue, fileName, line, detail.str());
    }

    template<typename T>
    void assertNotNull(T* actualValue, const std::string& fileName, size_t line, const std::string& detail = "")
    {
        if (actualValue == nullptr)
        {
            if (detail.size() == 0)
            {
                std::cout << "failure: expected: non-nullptr; " << fileName.c_str() << ":" << line << std::endl;
            }
            else
            {
                std::cout << "failure: expected: non-nullptr; " << fileName.c_str() << ":" << line << " (" << detail.c_str() << ")" << std::endl;
            }
        }
    }

    template<typename T>
    void assertNotNull(T* actualValue, const std::string& fileName, size_t line, const std::stringstream& detail)
    {
        assertNotNull(actualValue, fileName, line, detail.str());
    }

    template<typename ValueType>
    void assertEqual(ValueType expectedValue, ValueType actualValue, const std::string& fileName, size_t line, const std::string& detail = "")
    {
        if (expectedValue != actualValue)
        {
            if (detail.size() == 0)
            {
                std::cout << "failure: expected: " << expectedValue << "; actual: " << actualValue << "; " << fileName.c_str() << ":" << line << std::endl;
            }
            else
            {
                std::cout << "failure: expected: " << expectedValue << "; actual: " << actualValue << "; " << fileName.c_str() << ":" << line << " (" << detail.c_str() << ")" << std::endl;
            }
        }
    }

    template<typename ValueType>
    void assertEqual(ValueType expectedValue, ValueType actualValue, const std::string& fileName, size_t line, const std::stringstream& detail)
    {
        assertEqual(expectedValue, actualValue, fileName, line, detail.str());
    }
}

#define ASSERT_NULL(expression) framework::assertNull((expression), __FILE__, __LINE__)
#define ASSERT_NULL_DETAIL(expression, detail) framework::assertNull((expression), __FILE__, __LINE__, (detail))
#define ASSERT_NOT_NULL(expression) framework::assertNotNull((expression), __FILE__, __LINE__)
#define ASSERT_NOT_NULL_DETAIL(expression, detail) framework::assertNotNull((expression), __FILE__, __LINE__, (detail))
#define ASSERT_FALSE(expression) framework::assertFalse((expression), __FILE__, __LINE__)
#define ASSERT_FALSE_DETAIL(expression, detail) framework::assertFalse((expression), __FILE__, __LINE__, (detail))
#define ASSERT_TRUE(expression) framework::assertTrue((expression), __FILE__, __LINE__)
#define ASSERT_TRUE_DETAIL(expression, detail) framework::assertTrue((expression), __FILE__, __LINE__, (detail))
#define ASSERT_EQUAL(expectedValue, actualValue) framework::assertEqual((expectedValue), (actualValue), __FILE__, __LINE__)
#define ASSERT_EQUAL_DETAIL(expectedValue, actualValue, detail) framework::assertEqual((expectedValue), (actualValue), __FILE__, __LINE__, (detail))

#endif