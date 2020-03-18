#ifndef insertionSort_hpp
#define insertionSort_hpp

#include <stdio.h>

namespace insertion {
    template <typename T>
    void sort(std::vector<T> &nums);
}

#include "insertionSort.cpp"

#endif /* insertionSort_hpp */
