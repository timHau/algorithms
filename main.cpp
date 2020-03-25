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

    Queue<int> q;
    q.push(2);
    q.push(3);
    q.print();
    std::cout << q.pop() << std::endl;
    q.print();
    
    return 0;
}
