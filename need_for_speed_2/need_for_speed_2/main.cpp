#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;

int main() {
    std::string some_str = "twinkle";

    auto i = 0;
    auto million = 1000000;
    auto ten_million = 10000000;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    while (i < ten_million) {
        std::string some_str = "twinkle";
        std::string some_other_str = some_str;
        i++;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    std::cout << "copying the string takes - "
        << duration
        << " ms"
        << std::endl;

    i = 0;
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    while (i < ten_million) {
        std::string some_str = "twinkle";
        std::string some_other_str = std::move(some_str);
        i++;
    }
    high_resolution_clock::time_point t4 = high_resolution_clock::now();

    auto duration2 = duration_cast<milliseconds>(t4 - t3).count();
    std::cout << "moving the string takes - "
        << duration2
        << " ms"
        << std::endl;

    getchar();

}