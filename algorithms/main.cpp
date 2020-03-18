#include <iostream>
#include <vector>
#include "BinHeap.hpp"

bool c(int a, int b) {
    return a <= b;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = utils::random_numbers(0, 100, 20);
    BinHeap<int> h(c);
    h.from_vec(nums);
    h.print();
    
    auto f = [](int x, int y) -> int { return x + y; };
    std::cout << f(1, 2) << std::endl;
    
    return 0;
}
