#include "utils.h"
#include "type_deduction.h"

#include <utility>
#include <string>

namespace atd
{
    using s = std::string;

    template<class T, class U>
    auto add(T t, U u)
    {
        return t + u;
    } // the return type is the type of operator+(T, U)

    struct foo
    {
        int get_x() const
        {
            return x_;
        }
        
        int& get_rx()
        {
            return x_;
        }

        const int& get_crx() const
        {
            return x_;
        }

    private:
        int x_ = 10;
    };

    int auto_type_deduction_main() {

        std::cout << "***********************auto type deduction*************************" << std::endl;

        // equivalent to tempate<typename T> void foo(T param){}
        auto a = 1 + 2;
        auto b = add(1, 1.2);
        auto c = {1, 2};

        pts("a is of type: " + my_typeid(a));
        pts("b is of type: " + my_typeid(b));
        pts("c is of type: " + my_typeid(c));

        foo f;

        // equivalent to template<typename T> void foo(T param){}
        auto foo1 = f.get_x();
        auto foo2 = f.get_rx();
        auto foo3 = f.get_crx();

        // equivalent to template<typename T> void foo(T& param){}
        //auto& x4 = f.get_x(); // error -> get_x() returns rvalue, we cannot bind rvalue to lvalue reference
        auto& bar1 = f.get_rx();
        auto& bar2 = f.get_crx();


        // equivalent to template<typename T> void foo(const T& param){}
        const auto& baz1 = f.get_x();
        const auto& baz2 = f.get_rx();
        const auto& baz3 = f.get_crx();

        //UNIVERSAL REFERENCE
        // equivalent to template<typename T> void foo(T&& param){}
        auto&& x6 = f.get_x();

        pts("foo1 is of type: " + my_typeid(foo1));
        pts("foo2 is of type: " + my_typeid(foo2));
        pts("foo3 is of type: " + my_typeid(foo3));
        pts("bar1 is of type: " + my_typeid(bar1));
        pts("bar2 is of type: " + my_typeid(bar2));
        pts("baz1 is of type: " + my_typeid(baz1));
        pts("baz2 is of type: " + my_typeid(baz2));
        pts("baz3 is of type: " + my_typeid(baz3));


        //decltype(auto) e = f.get_bar();
        //pts("e is of type: " + my_typeid(e));

        return 0;
    }
}
