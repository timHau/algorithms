//
//  utils.hpp
//  algorithms
//
//  Created by tim on 18.03.20.
//  Copyright © 2020 tim. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <random>

namespace utils {
    
    std::vector<int> random_numbers(int min, int max, int n) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
        
        std::vector<int> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(dist(rng));
        }
        
        return res;
    }
    
    
    template <typename T> void swap(std::vector<T> &V, int i, int j)
    {
        T tmp = V[i];
        V[i] = V[j];
        V[j] = tmp;
    }
    
}


#endif /* utils_hpp */
