#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> vec{1,2,3,4,5,6};
    int multiplier = 2;

    auto print_to_screen = [multiplier = multiplier] (const int& i) {std::cout << i * multiplier << std::endl; };
    std::for_each(std::begin(vec),
                  std::end(vec),
                  print_to_screen);
    return 0;
}
