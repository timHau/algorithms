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
    
    int random_int(int min, int max) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
        
        return dist(rng);
    }
    
}


