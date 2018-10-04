#include <iostream>
// class that when compiled will contain the factorial
// as the static const value!
template <unsigned int n>
struct factorial {
    static const unsigned int value = n * factorial<n - 1>::value;
};

// template specialization - terminate the recursion
template <>
struct factorial<0> {
    static const unsigned int  value = 1;
};

int main() {
    unsigned int i = factorial<5>::value;
    std::cout << i << std::endl;
    getchar();
    return 0;
}