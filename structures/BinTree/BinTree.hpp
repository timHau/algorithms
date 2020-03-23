#ifndef BinTree_hpp
#define BinTree_hpp

#include <stdio.h>
#include <vector>
#include <functional>
#include "mergeSort.hpp"
#include "math.h"

#include <iostream>

template <typename T>
class BinTree {
    
private:
    struct Node {
        T key;
        Node *left;
        Node *right;
    };
    Node *root;
    
public:
    BinTree(std::vector<T> &nums) {
        build_tree(nums);
    }
    
    void build_tree(std::vector<T> nums) {
        // initialise root
        T key = nums[0];
        nums.erase(nums.begin());
        Node *n = new Node();
        n->key = key;
        root = n;
        
        while (nums.size()) {
            T key = nums[0];
            nums.erase(nums.begin());
            insert(key);
        }
    }
    
    void insert(T key) {
        Node *n = new Node();
        n->key = key;
        Node **comparePtr = &root;
        
        bool found = false;
        while (!found) {
            Node *compare = *comparePtr;
                
            if (n->key <= compare->key) {
                // search the left subtree
                if (!compare->left) {
                    // if there is no left node -> insert n there
                    compare->left = n;
                    found = true;
                } else {
                    // continue with left node
                    comparePtr = &compare->left;
                }
            } else {
                // search right subtree
                if (!compare->right) {
                    compare->right = n;
                    found = true;
                } else {
                    // continue with right node
                    comparePtr = &compare->right;
                }
            }
        }
    }
    
    void pre_order(Node *node, std::function<void(T)> f)
    {
        f(node->key);
        if (node->left) pre_order(node->left, f);
        if (node->right) pre_order(node->right, f);
    }
    
    Node *get_root() {
        return root;
    }
    
    
};

#endif /* BinTree_hpp */
