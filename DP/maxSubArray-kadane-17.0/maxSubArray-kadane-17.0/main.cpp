//
//  main.cpp
//  maxSubArray-kadane-17.0
//
//  Created by yashasvi on 11/30/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/* Think in terms of DP
 Solving subproblems
 */

pair<int,int>findMaxSubArray(vector<int> A){
    pair<int,int> range(0,0);
    int min_idx=-1,min_sum=0,max_sum=0,curr_sum=0;
    for(int i=0;i<A.size();i++){
        curr_sum+=A[i];
        if(curr_sum<min_sum){
            min_sum=curr_sum;
            min_idx=i;
        }
        if(curr_sum-min_sum> max_sum){
            max_sum = curr_sum + min_sum;
            range = {min_idx+1,i+1};
        }
    }
    return range;
}

void TEST(){
    vector<int> A={904,40,523,12,-335,-385,-124,481,-31};
    
    pair<int,int> range = findMaxSubArray(A);
    cout<<"Range is"<<range.first<<":"<<range.second;
    
    vector<int> B={1,-3,5,-2,9,-8,-6,4,-100,100};
    range = findMaxSubArray(B);
    cout<<"Range is"<<range.first<<":"<<range.second;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
