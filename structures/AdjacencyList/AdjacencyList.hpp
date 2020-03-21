#ifndef AdjacencyList_hpp
#define AdjacencyList_hpp

#include <stdio.h>
#include <vector>
#include "SimpleList.hpp"

class AdjacencyList
{
    
public:
    AdjacencyList(int numberVertices, std::vector<std::vector<int>> &edges) {
        for (int i = 0; i < numberVertices; ++i) {
            SimpleList<int> empty;
            data.push_back(empty);
        }
        
        for (std::vector<int> edge : edges) {
            int from = edge[0];
            int to = edge[1];
            data[from].add_value(to);
        }
    }
    
    
    void print() {
        for (SimpleList<int> l : data)
            l.print();
    }
    
private:
    std::vector<SimpleList<int>> data;
    
};

#endif /* AdjacencyList_hpp */
