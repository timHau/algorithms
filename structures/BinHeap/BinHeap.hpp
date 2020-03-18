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
        // defaults to min Heap meaning smallest element is root
        // pass a compare function to the constructor if you want to change it
        compare = [](int a, int b) -> bool { return a <= b; };
    }
    
    BinHeap(std::function<bool(T, T)> &f) {
        std::vector<T> d;
        data = d;
        compare = f;
    }
    
    void insert(T elem) {
        data.push_back(elem);
        sift_up((int) data.size() - 1);
    }
    
    void from_vec(std::vector<T> &elems) {
        for (T e : elems)
            insert(e);
    }
    
    T delete_root() {
        utils::swap(data, 0, (int)(data.size() - 1));
        T result = data.back();
        data.pop_back();
        sift_down(0);
        return result;
    }
    
    void sift_up(int i) {
        if (i == 0 || compare(data[floor(i/2)], data[i])) return;
        utils::swap(data, i, floor(i/2));
        sift_up(floor(i/2));
    }
    
    void sift_down(int i) {
        if (2 * i <= data.size()) {
            int m;
            if (2 * i + 1 > data.size() - 1 || compare(data[2 * i], data[2 * i + 1])) {
                m = 2 * i;
            } else {
                m = 2 * i + 1;
            }
            
            if (!compare(data[i], data[m])) {
                utils::swap(data, i, m);
                sift_down(m);
            }
        }
    }
    
    long size() {
        return data.size();
    }
    
    void print() {
        std::for_each(data.begin(), data.end(), [](T d) { std::cout << d << " "; });
        std::cout << "" << std::endl;
        std::cout << "-----" << std::endl;
    }
    
private:
    std::vector<T> data;
    std::function<bool(T, T)> compare;
};


#endif /* BinHeap_hpp */
