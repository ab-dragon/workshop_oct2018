#include<iostream>
#include <string>
#include <type_traits>

struct foo
{
    foo()
    {
        std::cout << "called constructor" << std::endl;
    }

    foo(const foo& other)
    {
        std::cout << "called copy constructor" << std::endl;
    }

    foo(foo&& other)
    {
        std::cout << "called move constructor" << std::endl;
    }
};

void bar(foo& f)
{
    {
        // block of code
    }

    std::cout << "calling copy constructor" << std::endl;
    foo g = f;

    std::cout << "calling move constructor" << std::endl;
    foo h = std::move(f);

    {
        //block of code
    }
}

int main()
{
    std::cout << "calling constructor" << std::endl;
    foo f;

    bar(f);

    //foo x = std::move(bar(f));

    std::getchar();
    
}
