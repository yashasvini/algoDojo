//
//  main.cpp
//  RandomSubset-6.12
//
//  Created by yashasvi on 11/30/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void GenerateRandomSubset(vector<int>& A,int k){
    // initialize the seed
   
    
    for(int i=0;i<k;i++){
        int index =rand()%A.size();
        swap(A[i],A[index]);
    }
}



void TEST(int num){
    cout<<"count"<<num<<endl;
    vector<int> input={3,7,5,11,13,15};
    GenerateRandomSubset(input,3);
    for(int i=0;i<3;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}

void TEST_CASE(){
    for(int i=0;i<25;i++){
        TEST(i);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
     srand(time(0));
    TEST_CASE();
    return 0;
}
