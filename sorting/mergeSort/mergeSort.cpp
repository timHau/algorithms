#include <iostream>
#include <vector>
#include "math.h"

namespace mergeSort {
    template <typename T>
    std::vector<T> merge(std::vector<T> &a, std::vector<T> &b) {
        std::vector<T> c;
        
        long n = a.size() + b.size();
        while(c.size() < n) {
            if (a.size() == 0) {
                c.insert(c.end(), b.begin(), b.end());
                continue;
            }
            if (b.size() == 0) {
                c.insert(c.end(), a.begin(), a.end());
                continue;
            }
            if (a.front() <= b.front()) {
                c.push_back(a.front());
                a.erase(a.begin());
            } else {
                c.push_back(b.front());
                b.erase(b.begin());
            }
        }
        
        return c;
    }
    
    template <typename T>
    std::vector<T> sort(std::vector<T> &nums) {
        if (nums.size() == 1) return nums;
        int nHalf = floor(nums.size() / 2);
        std::vector<T> n1 = std::vector<T>(nums.begin(), nums.begin() + nHalf);
        std::vector<T> n2 = std::vector<T>(nums.begin() + nHalf, nums.end());
        
        std::vector<T> s1 = sort(n1);
        std::vector<T> s2 = sort(n2);
        
        return merge(s1, s2);
    }
    
}
