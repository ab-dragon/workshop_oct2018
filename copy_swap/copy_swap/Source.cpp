#include <iostream>
#include <ostream>

class foo
{
    int size_;
    int* data_;

public:
    explicit foo(const int size)
        : size_(size), data_(size_ ? new int[size_]():nullptr){}

    foo(const foo& other)
        : size_(other.size_), data_(size_ ? new int[size_]():nullptr)
    {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    ~foo()
    {
        delete[] data_;
    }

    foo& operator=(const foo& other)
    {
        if (this == &other)
            return *this;

        delete[] data_;
        data_ = nullptr;

        size_ = other.size_;
        data_ = size_ ? new int[size_]() : nullptr;

        std::copy(other.data_, other.data_ + other.size_, data_);

        return *this;
    }

};

int main()
{
    int x = 10;

    foo f(x);

    std::cout << f << std::endl;
    getchar();
}
