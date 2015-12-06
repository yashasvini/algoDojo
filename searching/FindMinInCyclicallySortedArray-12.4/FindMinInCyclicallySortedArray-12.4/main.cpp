//
//  main.cpp
//  FindMinInCyclicallySortedArray-12.4
//
//  Created by yashasvi on 11/28/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int FindMinInCyclicSortedArray(const vector<int>& A){
    int min;
    int l=0,h=A.size()-1;
    int mid;
    while(l<h){
        mid=l+((h-l)/2);
        if(A[mid]>A[h]){
            l=mid+1;
        }
        else if(A[mid]<A[h]){
            h=mid;
        }
    }
    
    /* loop ends when l==h*/
    return l;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> A={5,4,3,2,1};
    cout<<FindMinInCyclicSortedArray(A);
    return 0;
}
