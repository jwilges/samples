#ifndef __ADT_STACK_HPP__
#define __ADT_STACK_HPP__

#include <iostream>
#include <memory>

namespace adt
{
    template<typename T>
    class Stack
    {
    public:
        static const size_t DEFAULT_RESERVED_SIZE = 16;

        Stack(size_t reservedSize = DEFAULT_RESERVED_SIZE) noexcept;
        Stack(const Stack& other) noexcept;
        Stack(Stack&& other) noexcept;
        virtual ~Stack() noexcept;

        Stack& operator=(const Stack& other) noexcept;

        inline size_t size() const noexcept
        {
            return _size;
        }

        const T* top() const;
        void push(const T& value);
        void push(const T&& value);
        const T* pop();

        std::ostream& write(std::ostream& out) const;

    private:
        void grow(size_t newReservedSize);

        std::unique_ptr<T[]> _stack;
        size_t _size;
        size_t _reservedSize;
    };
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const adt::Stack<T>& stack);

#include "stack.inc.hpp"

#endif