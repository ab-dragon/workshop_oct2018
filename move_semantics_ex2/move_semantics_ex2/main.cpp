#include <iostream>
#include <vector>
#include <ostream>

struct foo {
    int i_ = 10;

    explicit foo(const int i)
        : i_(i) {}

    foo(const foo& other)
        : i_(other.i_) {
        std::cout << "copy constructor" << std::endl;
    }

    foo(foo&& other)
        : i_(other.i_) {
        std::cout << "move constructor" << std::endl;
    }

    foo& operator=(const foo& other) {
        if (this == &other)
            return *this;
        i_ = other.i_;
        return *this;
    }

    foo& operator=(foo&& other) {
        if (this == &other)
            return *this;
        i_ = other.i_;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const foo& obj) {
        return os << "i_: " << obj.i_;
    }
};

int main() {
    std::vector<foo> vec_foo1;
    vec_foo1.reserve(10);
    for (auto i = 0; i< 10; i++) {
        vec_foo1.push_back(foo(i)); // calls to move constructor
    }

    std::cout << "-----------second loop-----------" << std::endl;

    for (auto i = 10; i< 20; i++) {
        vec_foo1.push_back(foo(i)); // calls to move constructor
    }
    getchar();


}