#include <iostream>

class foo {
    int x_;
public:
    foo(const int x)
        : x_(x)
    {
        std::cout << "constructor" << std::endl;
    }

    // copy constructor
    foo(const foo& other)
        : x_{other.x_}
    {
        std::cout << "copy constructor" << std::endl;
    }

    // move constructor
    foo(foo&& other) noexcept
        : x_{other.x_}
    {
        std::cout << "move constructor" << std::endl;
    }
};

foo bar1() {
    foo f(20);
    return f;
}

foo bar2() {
    foo f(20);
    return std::move(f);
}

foo bar3() {
    return foo(20);
}



int main()
{
    std::cout << "calling bar1 that returns f" << std::endl;
    auto f1 = bar1();
    std::cout << std::endl;
    std::cout << "calling bar2 that returns std::move(f)" << std::endl;
    auto f2 = bar2();
    std::cout << std::endl;
    std::cout << "calling bar3 that returns temporary object" << std::endl;
    auto f3 = bar3();

    getchar();
}