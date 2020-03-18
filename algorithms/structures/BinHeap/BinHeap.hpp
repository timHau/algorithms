#ifndef BinHeap_hpp
#define BinHeap_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <functional>
#include "utils.hpp"

// template classes have to be written inside the header file (i guess)
// https://stackoverflow.com/questions/1353973/c-template-linking-error

template<typename T>
class BinHeap
{
public:
    BinHeap() {
        std::vector<T> d;
        data = d;
    }
    
    BinHeap(std::function<bool(T, T)> f) {
        std::vector<T> d;
        data = d;
        comp = f;
    }
    
    void insert(T elem) {
        data.push_back(elem);
        siftUp((int) data.size() - 1);
    }
    
    void from_vec(std::vector<T> elems) {
        // create a heap from a std::vector in O(n)
        for (T e : elems)
            insert(e);
    }
    
    void siftUp(int i) {
        if (i == 0 || comp(data[floor(i/2)], data[i])) return;
        utils::swap(data, i, floor(i/2));
        siftUp(floor(i/2));
    }
    
    void print() {
        std::for_each(data.begin(), data.end(), [](T d) { std::cout << d << " "; });
        std::cout << "-----" << std::endl;
    }
    
private:
    std::vector<T> data;
    std::function<bool(T, T)> comp;
};

#endif /* BinHeap_hpp */
