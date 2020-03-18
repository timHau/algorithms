#ifndef selectionSort_hpp
#define selectionSort_hpp

#include <stdio.h>

namespace selection {
    template <typename T>
    void sort(std::vector<T> &nums);
}

#include "selectionSort.cpp"

#endif /* selectionSort_hpp */
