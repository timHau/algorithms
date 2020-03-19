#include <iostream>
#include <vector>
#include "main.hpp"

int main(int argc, const char * argv[]) {
    Stack<int> s;
    s.push(2);
    s.push(5);
    s.push(9);
    s.print();
    s.pop();
    s.print();
    
    return 0;
}
