#include <iostream>
#include <vector>
#include "main.hpp"

#include "math.h"


int main(int argc, const char * argv[]) {
// std::vector<int> nums = utils::random_numbers(0, 100, 20);
    std::vector<int> nums = {
        7,0,5,3,2,1,12,9,8,10,13,15
    };
//    for(int v : nums)
//        std::cout << v << " ";
//    std::cout << "" << std::endl;
    
    BinTree<int> B(nums);
    B.pre_order(B.get_root(), [](int n) { std::cout << n << " "; });
    std::cout << "" << std::endl;
    
    B.in_order(B.get_root(), [](int n) { std::cout << n << " "; });
    std::cout << "" << std::endl;
    
    B.post_order(B.get_root(), [](int n) { std::cout << n << " "; });
    std::cout << "" << std::endl;
    
    return 0;
}
