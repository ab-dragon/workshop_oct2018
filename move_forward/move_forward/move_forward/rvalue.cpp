#include <iostream>
#include <string>
#include <utility>
#include <type_traits>
#include <typeinfo>
#include <vector>
using namespace std;
struct bar
{
    int i_;

    explicit bar(const int i)
        : i_(i)
    {
        std::cout << "construction" << std::endl;
    }

    bar(const bar& other)
        : i_{other.i_}
    {
        std::cout << "copy construction" << std::endl;
    }

    bar(bar&& other) noexcept
        : i_(std::move(other.i_))
    {
        std::cout << "move construction" << std::endl;
    }

    bar& operator=(bar other)
    {
        std::cout << "copy assignment" << std::endl;
        using std::swap;
        swap(*this, other);
        return *this;
    }

};

void foo(const bar& b)
{
    std::string str = "do something with bar";
    std::cout << str << std::endl;
}

void foo(bar&& b)
{
    std::cout << "do something with bar" << std::endl;
}

bar baz()
{
    return bar{2};
}

//int main()
//{
//
//    bar b(1);
//    //auto b2 = b;
//    //foo(b);
//
//
//
//    std::getchar();
//    return 0;
//
//}
