//#include "utils.h"
//
//// foo takes lvalue reference as argument: ONLY LVALUES CAN BIND TO LVALUE REFERENCE
//void foo(int& a)
//{
//    pts("foo(int& a)");
//    pts(a);
//}
//
//// overload of foo that takes rvalue reference. ONLY RVALUES CAN BIND TO RVALUE REFERENCE
//void foo(int&& a)
//{
//    pts("foo(int&& a)");
//    std::cout << a << std::endl;
//}
//
//int bar()
//{
//    return 42;
//}
//
//
//template <typename T>
//void func(T&& in)
//{
//    std::cout << my_typeid(in) << std::endl;
//}
//
//int main()
//{
//    //int x = 10;
//    //foo(x);
//    //foo(bar());
//    //foo(4);
//
//
//    int a = 10;
//    func(a);
//
//    const int b = 20;
//    func(b);
//
//
//    std::getchar();
//
//
//    
//}
