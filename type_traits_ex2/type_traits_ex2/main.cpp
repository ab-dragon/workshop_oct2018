#include <iostream>
#include <type_traits>
#include <vector>


template<typename T>
std::enable_if_t<std::is_floating_point_v<T>>
foo(T x)
{
    //only for floating point type
}


int main()
{
    int a = 10;
    foo(a); // this should give you compiler error
    float b = 42.2;
    foo(b); // this should work

    getchar();
}