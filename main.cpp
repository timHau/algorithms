#include <iostream>
#include <vector>
#include "main.hpp"

#include "math.h"


int main(int argc, const char * argv[]) {
// std::vector<int> nums = utils::random_numbers(0, 100, 20);
    std::vector<int> nums = {
        32, 8, 44, 90, 10, 11, 96, 72, 26, 66, 3, 74, 4, 40, 39, 99
    };
    for(int v : nums)
        std::cout << v << " ";
    std::cout << "" << std::endl;
    
    BinTree<int> B(nums);
    B.pre_order(B.get_root(), [](int n) { std::cout << n << std::endl; });
    
    return 0;
}
