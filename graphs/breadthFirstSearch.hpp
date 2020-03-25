#ifndef breadthFirstSearch_hpp
#define breadthFirstSearch_hpp

#include <stdio.h>
#include "AdjacencyList.hpp"

namespace breadthFirst {
    template <typename T>
    void search(AdjacencyList graph, T start, T target);
}

#endif /* breadthFirstSearch_hpp */
