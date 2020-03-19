#include <iostream>
#include <vector>
#include "main.hpp"

int main(int argc, const char * argv[]) {
    std::vector<int> nums = utils::random_numbers(0, 100, 20);
    for(int v : nums)
        std::cout << v << " ";
    std::cout << "" << std::endl;
    
    distCount::sort(nums);
    
    for(int v : nums)
        std::cout << v << " ";
    std::cout << "" << std::endl;
    
   
    
    //    std::vector<int> res = radix::sort(nums);
    //    for(int v : res)
    //        std::cout << v << " ";
    //    std::cout << "" << std::endl;
    //
    //    std::cout << radix::decToBase(1025, 15) << std::endl;
    //
    return 0;
}
