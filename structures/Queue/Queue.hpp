#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "Stack.hpp"

template <typename T>
class Queue {
    
private:
    Stack<T> s1;
    Stack<T> s2;
    
public:
    
    void push(T element) {
        while (!s1.empty()) {
            s2.push(s1.pop());
        }
        
        s1.push(element);
        
        while (!s2.empty()) {
            s1.push(s2.pop());
        }
    }
    
    T pop() {
        return s1.pop();
    }
    
    void print() {
        s1.print();
    }
    
};

#endif /* Queue_hpp */
