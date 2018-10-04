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

    foo& operator=(const foo& other) {

        int size_temp = other.size_;
        int* data_temp = size_ ? new int[size_]() : nullptr;

        std::copy(other.data_, other.data_ + other.size_, data_temp);

        delete[] data_;

        data_ = data_temp;
        size_ = size_temp;

        return *this;
    }

};


int main() {
    int x = 10;

    foo f(x);

    std::cout << f << std::endl;
    getchar();
}
