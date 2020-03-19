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
    
    template <typename T>
    T select(std::vector<T> &nums, int k) {
        if (k > nums.size()) return NULL;
        int maxElement = (int)*std::max_element(nums.begin(), nums.end());
        int pivotIndex = utils::random_int(0, maxElement);
        T pivot = nums[pivotIndex];
        
        std::vector<T> smaller;
        for (T elem : nums) {
            if (elem < pivot) {
                smaller.push_back(elem);
            }
        }
        if (smaller.size() >= k) return select(smaller, k);
        
        std::vector<T> equals;
        for (T elem : nums) {
            if (elem == pivot) {
                equals.push_back(elem);
            }
        }
        if (smaller.size() + equals.size() >= k) return pivot;
        
        std::vector<T> larger;
        for (T elem : nums) {
            if (elem > pivot) {
                larger.push_back(elem);
            }
        }
        return select(larger, k - (int)smaller.size() - (int)equals.size());
    }
    
}
