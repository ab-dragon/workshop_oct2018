#include <iostream>

int foo1()
{
    return 42;
}

int main()
{

    int&& f = foo1();
    std::cout << f << std::endl;
    std::cout << &f << std::endl;
    getchar();

}