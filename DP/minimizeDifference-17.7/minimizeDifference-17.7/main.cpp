//
//  main.cpp
//  minimizeDifference-17.7
//
//  Created by yashasvi on 12/3/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;


int minimizeDifference(vector<int>&A){
    int sum = accumulate(A.begin(),A.end(),0);
    unordered_set<int> is_ok;
    is_ok.emplace(0);
    
    
    for(auto item:A){
        for(int j=sum/2;j>=item;j--){
            if(is_ok.find(j-item)==is_ok.end()){
                is_ok.emplace(j);
                }
        }
    }
    
    
    for(int j=sum/2;j>0;j--){
        if(is_ok.find(j)!=is_ok.end()){
            return ((sum-j)-j);
        }
    }
    return sum;
}


void TEST(){
    vector<int> A={3,1,1,2,2,1,5};
    cout<<minimizeDifference(A);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
