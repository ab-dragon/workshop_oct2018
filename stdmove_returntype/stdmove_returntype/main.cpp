#include <iostream>

struct bar
{
    bar() = default;
    bar(const bar& other) {}

    bar(bar&& other) {}

    bar& operator=(const bar& other)
    {
        if (this == &other)
            return *this;
        return *this;
    }

    bar& operator=(bar&& other)
    {
        if (this == &other)
            return *this;
        return *this;
    }
};

bar foo() { return {}; }

const bar foo_2() { return {}; }

int main()
{
    bar a;
    bar& b = std::move(a); // arg to move is lvalue: move returns rvalue. rvalue DOES NOT BIND to lvalue reference

    bar& c = std::move(foo()); // arg to move is rvalue: move returns rvalue. rvalue DOES NOT BIND to lvalue reference

    const bar& d = std::move(foo()); // arg to move is rvalue: move returns rvalue. rvalue CAN BIND to lvalue reference to const

    const bar& e = std::move(foo_2()); // arg to move is const rvalue, move returns const rvalue. const rvalue CAN BIND to lvalue reference to const object

    std::getchar();
}