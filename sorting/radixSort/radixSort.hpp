#ifndef radixSort_hpp
#define radixSort_hpp

#include <stdio.h>
#include <vector>

namespace radix {
    // works only with integers
    void sort(std::vector<int> &nums);
    std::vector<int> decToBase(int number, int base);
    int baseToInt(std::vector<int> &numInBase, int base);
}

#endif /* radixSort_hpp */
