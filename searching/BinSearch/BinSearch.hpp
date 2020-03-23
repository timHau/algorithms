#ifndef binSearch_hpp
#define binSearch_hpp

#include <stdio.h>
#include <vector>
#include "mergeSort.hpp"
#include "math.h"

#include <iostream>

template <typename T>
class BinSearch
{
public:
    BinSearch(std::vector<T> &nums) {
        std::vector<T> sorted = mergeSort::sort<T>(nums);
        data = &sorted;
        build_tree();
    }
    
private:
    struct Node {
        T key;
        Node *leftChild;
        Node *rightChild;
    };
    
    std::vector<T> *data;
    Node *root;

    
    void build_tree() {
        
    }
};

#endif /* binSearch_hpp */
