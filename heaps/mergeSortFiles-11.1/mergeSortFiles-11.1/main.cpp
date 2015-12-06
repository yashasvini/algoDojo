//
//  main.cpp
//  mergeSortFiles-11.1
//
//  Created by yashasvi on 11/26/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class myComparison{
public:
    bool operator()(int a,int b){
        return (a<b?a:b);
    }
};

vector<int>& MergeSortedArrays(vector<vector<int>>& sortedArrays){
    priority_queue<int,vector<int>,myComparison> heap;
    for(auto & iter:sortedArrays){
        heap.emplace(iter.begin(),iter.end());
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
