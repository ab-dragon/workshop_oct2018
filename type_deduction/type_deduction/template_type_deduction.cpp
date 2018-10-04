#include "utils.h"
#include "type_deduction.h"
namespace ttd
{
    template<typename T>
    void foo(T param, const std::string& name)
    {
        pts(name + " is of type: " + my_typeid(param));
    }

    template<typename T>
    void bar(T& param, const std::string& name)
    {
        pts(name + " is of type: " + my_typeid(param));
    }

    template<typename T>
    void baz(const T& param, const std::string& name)
    {
        pts(name + " is of type: " + my_typeid(param));
    }

    template<typename T>
    void uref(T&& param, const std::string& name)
    {
        pts(name + " is of type: " + my_typeid(param));
    }

    int template_type_deduction_main()
    {
        std::cout << "***********************template type deduction*************************" << std::endl;
        int x = 42;
        const int cx = 42;
        int& rx = x;
        const int& crx = x;

        std::cout << "----------- foo(T param) --------------" << std::endl;
        foo(x,"x");
        foo(cx,"cx"); // constness is ignored in deducing type of T
        foo(rx,"rx"); // referenceness is ignored in deducing type of T
        foo(crx,"crx"); // constness and referenceness is ignored in deducing type of T

        std::cout << "----------- bar(T& param) --------------" << std::endl;
        bar(x,"x");
        bar(cx,"cx"); // constness is preserved in deducing type of T
        bar(rx, "rx"); // referenceness is ignored in deducing type of T
        bar(crx, "crx"); // constness is preserved in deducing type of T

        // rule if param is reference type: ignore the referenceness of the expr
        std::cout << "----------- baz(const T& param) --------------" << std::endl;
        baz(x,"x");
        baz(cx,"cx"); // constness is ignored in deducing type of T
        baz(rx, "rx"); // referenceness is ignored in deducing type of T
        baz(crx, "crx"); // constness and referenceness both are ignored in deducing type T

        // rule if param is const type: ignore the constness of the expr
        //------------------------------------------------
        // general rule -> in deducing type of T, ignore all the adornements common to both expr and paramType

        std::cout << "----------- uref(T&& param) --------------" << std::endl;
        uref(x,"x");
        uref(cx,"cx"); // constness is ignored in deducing type of T
        uref(rx, "rx"); // referenceness is ignored in deducing type of T
        uref(crx, "crx"); // constness and referenceness both are ignored in deducing type T
        uref(42, "42"); // constness and referenceness both are ignored in deducing type T

        // if expr is lvalue, then T is deduced as a reference, and param is deduced as lvalue reference
        // if expr is rvalue, then param is deduced as rvalue reference

        return 0;
    }
}
