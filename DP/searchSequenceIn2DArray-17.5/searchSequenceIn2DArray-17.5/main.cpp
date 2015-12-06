//
//  main.cpp
//  searchSequenceIn2DArray-17.5
//
//  Created by yashasvi on 12/1/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/*
    |1 2 3 |
 A= |3 4 5 |
    |5 6 7 |
 
 S1={1,3,4,6} -- found
 S2={1,2,3,4} --- not found
 
 */


struct HashTuple{
    size_t operator()(const tuple<int,int,int> &t){
        return (hash<int>()(get<0>(t))^hash<int>()(get<1>(t))^hash<int>()(get<2>(t)));
    }
};


bool SearchSequenceIn2DArrayHelper(vector<vector<int>> &A,vector<int> &sequence,int i,int j,int len,unordered_set<tuple<int,int,int>,HashTuple> &cache){
    
    if(sequence.size()==len){
        return true;
    }
    
    if(i<0||i>=A.size()||j<0||j>A[i].size()||
       (cache.find({i,j,len})!=cache.end())){
        return false;
    }
    
    if((A[i][j]==sequence[len] &&
       SearchSequenceIn2DArrayHelper(A,sequence,i-1,j,len+1,cache)) ||
       SearchSequenceIn2DArrayHelper(A,sequence,i+1,j,len+1,cache) ||
       SearchSequenceIn2DArrayHelper(A,sequence,i,j-1,len+1,cache) ||
       SearchSequenceIn2DArrayHelper(A,sequence,i,j+1,len+1,cache))
    {
        return true;
    }
    
    cache.emplace(i,j,len);
    return false;
}


bool SearchSequenceIn2DArray(vector<vector<int>> &A,vector<int> &sequence){
    unordered_set<tuple<int,int,int>,HashTuple> cache;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            if(SearchSequenceIn2DArrayHelper(A,sequence,i,j,0,cache)){
                return true;
            }
        }
               
    }
    return false;
}


void TEST(){
    vector<vector<int>> A={{{1,2,3},{3,4,5},{5,6,7}}};
    vector<int> sequence1 ={1,2,3,4};
    vector<int> sequence2={1,3,4,6};
    cout<<SearchSequenceIn2DArray(A,sequence1)<<endl;
    cout<<SearchSequenceIn2DArray(A,sequence2);
}
            
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
