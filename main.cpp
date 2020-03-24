#include <iostream>
#include <vector>
#include "main.hpp"

#include "math.h"


int main(int argc, const char * argv[]) {
// std::vector<int> nums = utils::random_numbers(0, 100, 20);
    std::vector<int> nums = {
        5,4,6,9,7
    };
//    for(int v : nums)
//        std::cout << v << " ";
//    std::cout << "" << std::endl;
    
    BinTree<int> B(nums);
    B.pre_order(B.get_root(), [](int n) { std::cout << n << " "; });
    std::cout << "" << std::endl;
    
    B.remove(6);
    
    B.pre_order(B.get_root(), [](int n) { std::cout << n << " "; });
    std::cout << "" << std::endl;
    
    return 0;
}
