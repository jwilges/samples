namespace adt
{
    template<typename T>
    Stack<T>::Stack(size_t reservedSize = DEFAULT_RESERVED_SIZE) noexcept :
        _size(0),
        _reservedSize(reservedSize)
    {
        _stack = std::unique_ptr<T[]>(new T[reservedSize]);
    }

    template<typename T>
    Stack<T>::Stack(const Stack& other) noexcept
    {
        *this = other;
    }

    template<typename T>
    Stack<T>::Stack(Stack&& other) noexcept :
        _size(std::move(other._size)),
        _reservedSize(std::move(other._reservedSize))
    {
        _stack.swap(other._stack);
    }

    template<typename T>
    Stack<T>::~Stack() noexcept
    {
    }

    template<typename T>
    Stack<T>& Stack<T>::operator=(const Stack& other) noexcept
    {
        _size = other._size;
        _reservedSize = other._reservedSize;
        _stack = std::unique_ptr<T[]>(new T[_reservedSize]);
        memcpy(_stack.get(), other._stack.get(), _size * sizeof(T));
        return *this;
    }

    template<typename T>
    const T* Stack<T>::top() const
    {
        if (_size == 0)
        {
            return nullptr;
        }
        return &_stack[_size - 1];
    }

    template<typename T>
    void Stack<T>::push(const T& value)
    {
        if (_size + 1 > _reservedSize)
        {
            grow(_size * 2);
        }
        _stack[_size++] = value;
    }

    template<typename T>
    void Stack<T>::push(const T&& value)
    {
        if (_size + 1 > _reservedSize)
        {
            grow(_size * 2);
        }
        _stack[_size++] = std::move(value);
    }

    template<typename T>
    const T* Stack<T>::pop()
    {
        if (_size == 0)
        {
            return nullptr;
        }
        return &_stack[--_size];
    }

    template<typename T>
    void Stack<T>::grow(size_t newReservedSize)
    {
        if (newReservedSize > _reservedSize)
        {
            _reservedSize = newReservedSize;
            std::unique_ptr<T[]> stack = std::unique_ptr<T[]>(new T[_reservedSize]);
            memcpy(stack.get(), _stack.get(), _size * sizeof(T));
            _stack.swap(stack);
        }
    }

    template<typename T>
    std::ostream& Stack<T>::write(std::ostream& out) const
    {
        if (_size <= 0)
        {
            return out;
        }

        out << _stack[0];
        for (size_t index = 1; index < _size; index++)
        {
            out << ", " << _stack[index];
        }

        return out;
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const adt::Stack<T>& stack)
{
    return stack.write(out);
}