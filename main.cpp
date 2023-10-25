#include <iostream>
#include "segment.h"
#include "fenwick.h"

int main() {
    std::vector<int> a ={0,1,3,5,-2,3};
    SegmentTree segmentTree(a);
    std::cout<<segmentTree.sum(2,4)<<std::endl;
    FenwickTree fenwickTree(a);
    fenwickTree.print();
    std::cout<<fenwickTree.sum(3,4)<<std::endl;
    std::vector<std::vector<int>> b = {{0,1,2},{1,2,3},{2,3,4}};
    FenwickTree2D fenwickTree2D(b);
    std::cout<<fenwickTree2D.sum(1,2);
    return 0;
}
