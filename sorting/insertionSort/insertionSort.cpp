#include <vector>
#include "utils.hpp"

namespace insertion {
    
    template <typename T>
    void sort(std::vector<T> &nums)
    {
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i; j > 0; --j) {
                if (nums[j-1] <= nums[j]) break;
                utils::swap(nums, j-1, j);
            }
        }
    }
    
}
