#include <utility>
#include <chrono>
#include <iostream>
#include <vector>

struct Point {
    std::vector<double> v;
    double x;
    double y;
};

Point go_left(const Point& p) {
    Point tmp;
    tmp.x = p.x + 1;
    tmp.y = p.y;
    tmp.v = p.v;
    return tmp;
}
Point go_up(const Point& p) {
    Point tmp;
    tmp.x = p.x;
    tmp.y = p.y + 1;
    tmp.v = p.v;
    return tmp;
}

//Point go_left(Point&& p) {
//    p.x++;
//    return std::move(p);
//}
//Point go_up(Point&& p) {
//    p.y++;
//    return std::move(p);
//}
using namespace std::chrono;
int main() {

    auto ten_million = 100000000;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Point P3;
    P3.x = 0;
    P3.y = 0;
    P3.v.resize(200);
    for (unsigned i = 0; i < ten_million; i++) {
        P3 = go_left(go_up(go_left(P3)));
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    std::cout << P3.x << std::endl;
    std::cout << duration
        << " ms"
        << std::endl;

    getchar();
}