#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <typeinfo>

template<typename T>
void pts(T&& t)
{
    std::cout << t << std::endl;
}

template <class T>
std::string type_name() {
    using TR = typename std::remove_reference<T>::type;

    std::string r = typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

#define my_typeid(var) type_name<decltype(var)>()

#endif