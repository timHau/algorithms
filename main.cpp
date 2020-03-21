#include <iostream>
#include <vector>
#include "main.hpp"

#include <sstream>

int main(int argc, const char * argv[]) {
    std::vector<int> nums = utils::random_numbers(0, 100, 20);
    for(int v : nums)
        std::cout << v << " ";
    std::cout << "" << std::endl;
    
    radix::sort(nums);
    for(int v : nums)
        std::cout << v << " ";
    std::cout << "" << std::endl;
    
    return 0;
}
