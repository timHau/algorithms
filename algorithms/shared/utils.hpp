#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>


namespace utils {
    
    std::vector<int> random_numbers(int min, int max, int n);
    
    template <typename T> void swap(std::vector<T> &V, int i, int j) {
        T tmp = V[i];
        V[i] = V[j];
        V[j] = tmp;
    }
}

#endif /* utils_hpp */
