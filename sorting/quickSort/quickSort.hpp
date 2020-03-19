#ifndef quickSort_hpp
#define quickSort_hpp

#include <stdio.h>

namespace quick {
    template <typename T>
    std::vector<T> sort(std::vector<T> &nums);
}

#include "quickSort.cpp"

#endif /* quickSort_hpp */
