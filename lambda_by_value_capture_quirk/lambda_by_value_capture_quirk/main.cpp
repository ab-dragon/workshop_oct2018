#include <iostream>

int main()
{
    const int x = 10;
    auto foo = [=] () mutable
    {
        x = 20;
        std::cout << x << std::endl;
    };

    foo();
    getchar();
}