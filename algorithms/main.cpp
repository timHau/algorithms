#include <iostream>
#include <vector>
#include "BinHeap.hpp"

bool c(int a, int b) {
    return a <= b;
}

int main(int argc, const char * argv[]) {
//    std::vector<int> nums = utils::random_numbers(0, 100, 20);
    std::vector<int> nums = {
        2,7,26,25,19,17,1,90,3,36
    };
    BinHeap<int> h;
    h.from_vec(nums);
    h.print();
    int r = h.delete_root();
    h.print();
    std::cout << r << std::endl;
    
    return 0;
}
