#include <iostream>
#include <vector>
#include "main.hpp"

#include <sstream>

int main(int argc, const char * argv[]) {
//    std::vector<int> nums = utils::random_numbers(0, 100, 20);
//    for(int v : nums)
//        std::cout << v << " ";
//    std::cout << "" << std::endl;
    
    std::vector<std::vector<int>> edges = {
        {0,1},
        {0,2},
        {1,2},
        {2,1}
    };
    AdjacencyList A(3, edges);
    A.print();
    
    return 0;
}
