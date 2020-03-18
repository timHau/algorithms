#include <vector>
#include "utils.hpp"

namespace bubble {
    
    template <typename T>
    void sort(std::vector<T> &nums)
    {
        int active = 1;
        while(active) {
            active = 0;
            
            for(int j = 0; j < nums.size() - 1; ++j) {
                if(nums[j] > nums[j+1]) {
                    utils::swap(nums, j, j+1);
                    active = 1;
                }
            }
        }
    }
    
    
}
