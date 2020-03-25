#ifndef SimpleList_hpp
#define SimpleList_hpp

#include <iostream>

template<typename T>
class SimpleList
{
    
    struct Node {
        T label;
        Node *next;
    };
    
public:
    SimpleList() {
        head = NULL;
    }
    
    void insert_after(Node *prev_node, T value) {
        Node *n = new Node();
        n->label = value;
        n->next = prev_node->next;
        prev_node->next = n;
    }
    
    void add_value(T value) {
        Node *n = new Node();
        n->label = value;
        n->next = head;
        
        head = n;
    }
    
    T pop() {
        Node *n = head;
        T result = n->label;
        head = head->next;
        delete n;
        return result;
    }
    
    T peek() {
        return head->label;
    }
    
    int size() {
        int res = 0;
        
        Node *current = head;
        while (current) {
            res++;
            current = current->next;
        }
        
        return res;
    }
    
    Node *get_head() {
        return head;
    }
    
    bool empty() {
        return head == NULL;
    }
    
    void print() {
        Node *current = head;
        while (current) {
            std::cout << current->label << " ";
            current = current->next;
        }
        std::cout << "-----" << std::endl;
    }
    
private:
    Node *head;
};


#endif /* SimpleList_hpp */
