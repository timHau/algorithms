#ifndef quickSort_hpp
#define quickSort_hpp

#include <stdio.h>

namespace quick {
    template <typename T>
    std::vector<T> sort(std::vector<T> &nums);
    
    template <typename T>
    T select(std::vector<T> &nums, int k);
}

#include "quickSort.cpp"

#endif /* quickSort_hpp */
