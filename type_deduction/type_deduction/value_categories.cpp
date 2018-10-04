#include <iostream>
#include <functional>
#include <type_traits>

int foo()
{
    return 42;
}
void bar() {

    int a = 10;
    int& ra = a;

    int&& rb = a + 2;

    int b = foo();
}