#include <iostream>
#include <ostream>

class foo {
    int size_;
    int* data_;

public:
    explicit foo(const int size)
        : size_(size), data_(size_ ? new int[size_]() : nullptr) {}

    foo(const foo& other)
        : size_(other.size_), data_(size_ ? new int[size_]() : nullptr) {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    ~foo() {
        delete[] data_;
    }

    friend void swap(foo& lhs, foo& rhs) noexcept
    {
        using std::swap;
        swap(lhs.size_, rhs.size_);
        swap(lhs.data_, rhs.data_);
    }

    foo& operator=(const foo& other) {

        foo temp(other);
        std::swap(temp, *this);

        return *this;
    }

};


int main() {
    int x = 10;

    foo f(x);

    std::cout << f << std::endl;
    getchar();
}
