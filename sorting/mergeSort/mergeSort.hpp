#ifndef mergeSort_hpp
#define mergeSort_hpp

#include <stdio.h>

namespace mergeSort {
    template <typename T>
    std::vector<T> sort(std::vector<T> &nums);
}

#include "mergeSort.cpp"

#endif /* mergeSort_hpp */
