//
//  main.cpp
//  deleteKeyInArray-6.5
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


void printVector(vector<int> &input,int count){
    cout<<count<<":iterator::";
    for(int i=0;i<input.size();i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
int deleteKeyInArray( vector<int> &input,int key){
    int writeIndex=0;
    for(int i=0;i<input.size();i++){
        if(input[i]!=key){
            input[writeIndex++]=input[i];
        }
        printVector(input,i);
    }
    return writeIndex;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> input={5,3,7,11,2,3,13,5,7};
    int lastIndex = deleteKeyInArray(input,3);
    cout<<lastIndex<<endl;
    for(int i=0;i<input.size();i++){
        cout<<input[i]<<" ";
    }
    return 0;
}
