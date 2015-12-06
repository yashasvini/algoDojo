//
//  main.cpp
//  planningFishingTrip-17.4
//
//  Created by yashasvi on 12/1/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int planningFishingTrip(vector<vector<int>> fishPool){
    for(int i=0;i<fishPool.size();i++){
        for(int j=0;j<fishPool[i].size();j++){
            fishPool[i][j]+=max(fishPool[i-1][j],fishPool[i][j-1]);
        }
    }
    return fishPool.back().back();
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
