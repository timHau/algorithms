#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

template<typename T>
class Stack
{
public:
    void push(T value) {
        data.add_value(value);
    }
    
    T pop() {
        return data.pop();
    }
    
    void print() {
        data.print();
    }
    
    T peek() {
        return data.peek();
    }
    
    
private:
    SimpleList<T> data;
};

#endif /* Stack_hpp */
