#ifndef bubbleSort_hpp
#define bubbleSort_hpp

#include <stdio.h>

namespace bubble {
    template <typename T>
    void sort(std::vector<T> &nums);
}

#include "bubbleSort.cpp"

#endif /* bubbleSort_hpp */
