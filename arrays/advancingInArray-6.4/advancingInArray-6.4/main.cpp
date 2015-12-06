//
//  main.cpp
//  advancingInArray-6.4
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;

bool CanReachEnd(const vector<int>& max_advance_steps) {
    int furthest_reach_so_far = 0, last_index = max_advance_steps.size() - 1;
    for (int i = 0;
         i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i) {
        furthest_reach_so_far =
        max(furthest_reach_so_far, max_advance_steps[i] + i);
    }
    return furthest_reach_so_far >= last_index;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> board={3,3,1,0,2,0,1};
    if(CanReachEnd(board)){
        cout<<"can be won";
    }
    else{
        cout<<"no";
    }
    
    return 0;
}
