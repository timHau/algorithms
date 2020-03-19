#ifndef radixSort_hpp
#define radixSort_hpp

#include <stdio.h>
#include <vector>

namespace radix {
    // works only with integers
    std::vector<int> sort(std::vector<int> &nums);
    int decToBase(int number, int base);
}

#endif /* radixSort_hpp */
