#include <iostream>

class foo
{
    int x_;

public:
    explicit foo(const int x)
        : x_(x)
    {
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

foo bar1()
{
    std::cout << "bar1" << std::endl;
    foo f(20);
    return f;
}

foo bar2()
{
    std::cout << "bar2" << std::endl;
    foo f(20);
    return std::move(f);
}

//foo bar3(foo&& f)
//{
//    std::cout << "bar3" << std::endl;
//    {
//        // do something to or using f
//    }
//    return f;
//}
//
//foo bar4(foo&& f)
//{
//    std::cout << "bar4" << std::endl;
//    {
//        // do something to or using f
//    }
//    return std::move(f);
//}

foo bar5(foo f)
{
    std::cout << "bar5" << std::endl;
    {
        // do something to or using f
    }
    return f;
}

foo bar6(foo f)
{
    std::cout << "bar6" << std::endl;
    {
        // do something to or using f
    }
    return std::move(f);
}
int main()
{
    std::cout << "calling bar1" << std::endl;
    foo f1 = bar1();
    std::cout << "calling bar2 which uses std::move" << std::endl;
    foo f2 = bar2();
    //std::cout << "calling bar3 which takes rvalue reference" << std::endl;
    //foo f3 = bar3(bar1());
    //std::cout << "calling bar4 which takes rvalue reference and uses std::move" << std::endl;
    //foo f4 = bar4(bar1());
    std::cout << "calling bar5 which takes by value" << std::endl;
    foo f5 = bar5(f1);
    std::cout << "calling bar6 which takes by value and uses std::move" << std::endl;
    foo f6 = bar6(f1);

    std::getchar();
    return 0;
}