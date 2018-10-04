#include <iostream>
#include <type_traits>
#include <vector>


struct character {};

struct word{
    using child_t = character;

    std::vector<character> word_;

};


int main() {
    std::cout << std::boolalpha;
    
    std::cout << std::is_same<word, character>::value << std::endl;
    std::cout << std::is_same<word::child_t, character>::value << std::endl;
    getchar();
}