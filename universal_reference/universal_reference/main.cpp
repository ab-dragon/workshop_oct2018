#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

// -------------------------------NOTHING NEW HERE------------------------------------
struct foo {
    std::string x_ = "twinkle twinkle little start. How I wonder what you are!";

    foo(const std::string& x) : x_(x) {}

    // copy constructor
    foo(const foo& other)
        : x_{other.x_} {
        std::cout << "copy constructor" << std::endl;
    }

    // move constructor
    foo(foo&& other) noexcept
        : x_(std::move(other.x_)) {
        std::cout << "move constructor" << std::endl;
    }
};
// ----------------------------------------------------------------------------------

// two overloads of the func
void func(foo& a)
{
    std::cout << "func with foo&" << std::endl;
    foo b(a);
}

void func(foo&& a)
{
    std::cout << "func with foo&&" << std::endl;
    foo b(std::move(a));
}

// function bar with universal reference
template<typename T>
void bar(T&& x)
{
    // which of the following is the correct invocation????

    //func(x);
    func(std::forward<T&&>(x));
}

int main() {

    foo f("baby shark do do do do");
    std::cout << "f is - " << f.x_ << std::endl;

    bar(f);

    bar(foo("wheels on the bus"));







    std::cout << "now f is - " << f.x_ << std::endl;

    getchar();
}