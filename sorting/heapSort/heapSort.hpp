#ifndef heapSort_hpp
#define heapSort_hpp

#include <stdio.h>

namespace heapSort {
    template <typename T>
    std::vector<T> sort(std::vector<T> &nums);
}

#include "heapSort.cpp"

#endif /* heapSort_hpp */
