#include <iostream>
#include <vector>
#include "utils.hpp"

namespace quick {
    
    template <typename T>
    std::vector<T> sort(std::vector<T> &nums)
    {
        if (nums.size() <= 1) return nums;
        T pivot = nums[utils::random_int(0, (int) nums.size())];

        std::vector<T> smaller;
        std::vector<T> equals;
        std::vector<T> larger;
        for (T elem : nums) {
            if (elem < pivot) {
                smaller.push_back(elem);
                continue;
            }
            if (elem == pivot) {
                equals.push_back(elem);
                continue;
            }
            if (elem > pivot) {
                larger.push_back(elem);
                continue;
            }
        }
        
        std::vector<T> s1 = sort(smaller);
        std::vector<T> s2 = sort(larger);
        
        s1.insert(s1.end(), equals.begin(), equals.end());
        s1.insert(s1.end(), s2.begin(), s2.end());
        
        return s1;
    }
    
}
