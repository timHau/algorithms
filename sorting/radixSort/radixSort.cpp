#include "radixSort.hpp"
#include <vector>
#include "math.h"

#include <iostream>

namespace radix {
    
    
    int baseToInt(std::vector<int> &numInBase, int base) {
        int result = 0;
        std::reverse(numInBase.begin(), numInBase.end());
        for (int i = 0; i < numInBase.size(); ++i) {
            result += numInBase[i] * pow(base, i);
        }
        return result;
    }
    
    
    void sort(std::vector<int> &nums) {
        // there is no asymptotic difference between base < nums.size() and base == num.size();
      //  int base = (int) nums.size();
        int base = 2;
        int maxNum = *std::max_element(nums.begin(), nums.end());
        int maxBaseLen = floor(log(maxNum) / log(base)); // max number of base element <=> length of base vectors
        
        std::vector<std::vector<int>> numsInBase;
        for (int i = (int) nums.size()-1; i >= 0; --i) {
            int n = nums[i];
            std::vector<int> inBase = decToBase(n, base);
            // buffer with 0's s.t. all vectors have the same size.
            std::vector<int> buffer;
            for (int i = (int)inBase.size(); i <= maxBaseLen; ++i){
                buffer.push_back(0);
            }
            inBase.insert(inBase.begin(), buffer.begin(), buffer.end());
            numsInBase.push_back(inBase);
            nums.pop_back();
        }
        
        std::vector<std::vector<int>> queues [base];
        // initialise
        for (int i = 0; i < base; ++i) {
            std::vector<std::vector<int>> empty;
            queues[i] = empty;
        }
            
        for (int k = maxBaseLen; k >= 0; --k) {

            for (std::vector<int> n : numsInBase){
                queues[n[k]].push_back(n);
            }
            numsInBase.erase(numsInBase.begin(), numsInBase.end());
            
            for (int s = 0; s < base; ++s) {
                std::vector<std::vector<int>> *q = &queues[s];
                numsInBase.insert(numsInBase.end(), q->begin(), q->end());
                q->erase(q->begin(), q->end());
            }
        }
        
        for (std::vector<int> nb : numsInBase) {
            nums.push_back(baseToInt(nb, base));
        }
        
    }
    
    
    std::vector<int> decToBase(int number, int base) {
        std::vector<int> res;
        
        int n = number;
        int q = floor(n / base);
        int r = n % base;
        res.push_back(r);
        
        while (q != 0) {
            n = q;
            q = floor(n / base);
            r = n % base;
            res.push_back(r);
        }
        
        std::reverse(res.begin(), res.end());
        
        return res;
    }
    
}
