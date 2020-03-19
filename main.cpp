#include <iostream>
#include <vector>
#include "main.hpp"

int main(int argc, const char * argv[]) {
    SimpleList<int> L;
    L.add_value(2);
    L.add_value(4);
    L.add_value(6);
    L.insert_after(L.get_head(), 99);
    L.pop();
    L.print();
    
    
    return 0;
}
