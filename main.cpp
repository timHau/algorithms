#include <iostream>
#include <vector>
#include "main.hpp"

int main(int argc, const char * argv[]) {
    std::vector<int> nums = utils::random_numbers(0, 100, 20);
    std::for_each(nums.begin(), nums.end(), [](int v){ std::cout << v << " ";});
    std::cout << "" << std::endl;
    
    int res = quick::select<int>(nums, 4);
    std::cout << res << std::endl;
    
    return 0;
}

