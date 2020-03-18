#include <iostream>
#include <vector>
#include "main.hpp"

bool c(int a, int b) {
    return a <= b;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = utils::random_numbers(0, 100, 20);
    selection::sort(nums);
    std::for_each(nums.begin(), nums.end(), [](int v) { std::cout << v << " ";});
    
    return 0;
}
