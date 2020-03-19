#include <iostream>
#include <vector>
#include "main.hpp"

int main(int argc, const char * argv[]) {
    std::vector<int> nums = utils::random_numbers(0, 100, 20);
    
    std::vector<int> res = quick::sort<int>(nums);
    std::cout << "RESULT: " << std::endl;
    std::for_each(res.begin(), res.end(), [](int v) { std::cout << v << " ";});
    std::cout << "\n" << std::endl;
    
    return 0;
}
