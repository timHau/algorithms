#include <vector>
#include "BinHeap.hpp"

namespace heapSort {
    
    template <typename T>
    std::vector<T> sort(std::vector<T> &nums)
    {
        BinHeap<T> H;
        H.from_vec(nums);
        
        std::vector<T> result;
        while(H.size() > 0) {
            T root = H.delete_root();
            result.push_back(root);
        }
        
        return result;
    }
    
}
