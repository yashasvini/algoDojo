//
//  main.cpp
//  partitionProblem
//
//  Created by yashasvi on 12/2/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
 
*/


bool findPartition(vector<int> &A){
    int sum = accumulate(A.begin(),A.end(),0);
    vector<vector<bool>> part(sum/2+1,vector<bool>(A.size()+1,0));
    
    if(sum%2!=0){
        return false;
    }
    
    for(int i=0;i<=sum/2;i++){
        part[i][0]=true;
    }
    
    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=A.size();j++){
            part[i][j]=part[i][j-1];
            if(i > A[j-1]){
                part[i][j]=part[i][j]||part[i-A[j]][j-1];
            }
        }
    }
    return part[sum/2][A.size()];
}


void TEST(){
    vector<int> A={3,1,1,2,2,1};
    cout<<findPartition(A);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
