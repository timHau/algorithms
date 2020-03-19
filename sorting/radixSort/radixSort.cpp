#include "radixSort.hpp"
#include <vector>
#include <string>
#include "math.h"

namespace radix {
    
    std::vector<int> sort(std::vector<int> &nums) {
        // there is no asymptotic difference between base < nums.size() and base == num.size();
        int base = nums.size();
        
        return nums;
    }
    
    int decToBase(int number, int base) {
        std::string res;
        
        int n = number;
        int q = floor(n / base);
        int r = n % base;
        res.append(std::to_string(r));
        
        while (q != 0) {
            n = q;
            q = floor(n / base);
            r = n % base;
            res.append(std::to_string(r));
        }
        
        std::reverse(res.begin(), res.end());
        
        return std::stoi(res);
    }
    
}
