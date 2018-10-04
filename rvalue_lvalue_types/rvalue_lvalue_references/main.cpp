#include <iostream>

template<typename T>
void print_to_screen(T&& t)
{
    std::cout << t << std::endl;
}

// foo takes lvalue reference as argument: ONLY LVALUES CAN BIND TO LVALUE REFERENCE
void foo(int& a) {
    print_to_screen("foo(int& a)");
    print_to_screen(a);
}

// overload of foo that takes rvalue reference. ONLY RVALUES CAN BIND TO RVALUE REFERENCE
void foo(int&& a) {
    print_to_screen("foo(int&& a)");
    print_to_screen(a);
}

// overload of foo that takes lvalue reference to const. RVALUES CAN AND DO  BIND TO RVALUE REFERENCE
//void foo(const int& a)
//{
//    print_to_screen("foo(const int& a)");
//    print_to_screen(a);
//}

int bar() { return 42; }
const int bar2() { return 42; }

int main() {

    int x = 10;
    foo(x); // this will invoke foo(int& a)
    foo(bar()); // this will invoke foo(int&& a)
    foo(4); // this will invoke foo(int&& a)

    const int y = 55;
    foo(y); // this will invoke foo(const int& a)

    std::getchar();
}
