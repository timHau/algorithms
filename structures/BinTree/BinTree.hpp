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
    
    Node *find(T key) {
        Node *compare = root;
        bool found = false;
        while (!found) {
            if (key < compare->key) {
                if (!compare->left) throw "not found";
                compare = compare->left;
            }
            if (key > compare->key) {
                if (!compare->right) throw "not found";
                compare = compare->right;
            }
            if (key == compare->key) {
                found = true;
            }
        }
        return compare;
    }
    
    Node *find_parent(T key) {
        Node *parent = NULL;
        Node *compare = root;
        bool found = false;
        while (!found) {
            if (key < compare->key) {
                if (!compare->left) throw "not found";
                parent = compare;
                compare = compare->left;
            }
            if (key > compare->key) {
                if (!compare->right) throw "not found";
                parent = compare;
                compare = compare->right;
            }
            if (key == compare->key) {
                found = true;
            }
        }
        return parent;
    }
    
    void remove(T key) {
        Node *toDelete = find(key);
        Node *n = find_parent(key);
        
        int childs = get_nodetype(toDelete);
        // handle leaves
        if (childs == 0) {
            if (toDelete == n->left) {
                n->left = nullptr;
            } else {
                n->right = nullptr;
            }
        }
        if (childs == 1) {
            if (toDelete == n->left) {
                // remove left child
                if (toDelete->right) {
                    // that has itself a right child
                    n->left = toDelete->right;
                } else {
                    n->left = toDelete->left;
                }
            } else {
                if (toDelete->right) {
                    n->right = toDelete->right;
                } else {
                    n->right = toDelete->left;
                }
            }
        }
        if (childs == 2) {
            // naive implementation
            Node *leftSub = toDelete->left;
            Node *rightSub = toDelete->right;
            
            if (toDelete == n->left) {
                Node *leftRightLeave = toDelete->left;
                while (get_nodetype(leftRightLeave) != 0) {
                    leftRightLeave = leftRightLeave->left;
                }
                // put left subtree in position of toDelete
                n->left = leftSub;
                // put right subtree as a child of right most leave in left subtree
                leftRightLeave->right = rightSub;
            } else {
                Node *rightLeftLeave = toDelete->right;
                while (get_nodetype(rightLeftLeave) != 0) {
                    rightLeftLeave = rightLeftLeave->right;
                }
                n->right = rightSub;
                rightLeftLeave->left = leftSub;
            }
        }
        
        delete toDelete;
    }
    
    void pre_order(Node *node, std::function<void(T)> f)
    {
        f(node->key);
        if (node->left) pre_order(node->left, f);
        if (node->right) pre_order(node->right, f);
    }
    
    void in_order(Node *node, std::function<void(T)> f)
    {
        if (node->left) in_order(node->left, f);
        f(node->key);
        if (node->right) in_order(node->right, f);
    }
    
    void post_order(Node *node, std::function<void(T)> f)
    {
        if (node->left) post_order(node->left, f);
        if (node->right) post_order(node->right, f);
        f(node->key);
    }
    
    Node *get_root() {
        return root;
    }
    
    int get_nodetype(Node* n) {
        if (!n->left && !n->right) return 0;
        if ((n->left && !n->right) || (!n->left && n->right)) {
            return 1;
        }
        return 2;
    }
    
    
};

#endif /* BinTree_hpp */
