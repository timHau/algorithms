#include <vector>
#include "utils.hpp"

namespace selection {
    
    template <typename T>
    void sort(std::vector<T> &nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            T smallest = nums[i];
            int smallestIndex = i;
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[j] < smallest) {
                    smallest = nums[j];
                    smallestIndex = j;
                }
            }
            utils::swap<T>(nums, i, smallestIndex);
        }
    }
    
}
