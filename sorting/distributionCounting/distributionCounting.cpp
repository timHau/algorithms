#include "distributionCounting.hpp"
#include <vector>
#include <iostream>

namespace distCount {
    
    void sort(std::vector<int> &nums) {
        int max = *std::max_element(nums.begin(), nums.end()) + 1;
        int where = 0;
        int counting[max];
        
        // initializing
        for (unsigned int i = 0; i < max; ++i)
            counting[i] = 0;
        
        for (int val : nums)
            counting[val]++;
        
        for (unsigned int i = 0; i < max; ++i) {
            for (unsigned int j = 0; j < counting[i]; ++j) {
                nums[where + j] = i;
                where += counting[i];
            }
        }
        
    }
    
}
