#include "framework.hpp"

namespace framework
{
    void assertFalse(bool actualValue, const std::string& fileName, size_t line, const std::string& detail)
    {
        if (actualValue)
        {
            if (detail.size() == 0)
            {
                std::cout << "failure: expected: false; " << fileName.c_str() << ":" << line << std::endl;
            }
            else
            {
                std::cout << "failure: expected: false; " << fileName.c_str() << ":" << line << " (" << detail.c_str() << ")" << std::endl;
            }
        }
    }

    void assertFalse(bool actualValue, const std::string& fileName, size_t line, const std::stringstream& detail)
    {
        assertFalse(actualValue, fileName, line, detail.str());
    }

    void assertTrue(bool actualValue, const std::string& fileName, size_t line, const std::string& detail)
    {
        if (!actualValue)
        {
            if (detail.size() == 0)
            {
                std::cout << "failure: expected: true; " << fileName.c_str() << ":" << line << std::endl;
            }
            else
            {
                std::cout << "failure: expected: true; " << fileName.c_str() << ":" << line << " (" << detail.c_str() << ")" << std::endl;
            }
        }
    }

    void assertTrue(bool actualValue, const std::string& fileName, size_t line, const std::stringstream& detail)
    {
        assertTrue(actualValue, fileName, line, detail.str());
    }

    template<>
    void assertEqual(const std::string& expectedValue, const std::string& actualValue, const std::string& fileName, size_t line, const std::string& detail)
    {
        if (expectedValue.compare(actualValue) != 0)
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
}