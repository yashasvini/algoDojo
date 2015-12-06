//
//  main.cpp
//  deleteDuplicatesInSortedArray-6.6
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int deleteDuplicatesInSortedArray(vector<int> &input){
    int writeIndex=1;
    for(int i=1;i<input.size();i++){
        if(input[writeIndex-1]!=input[i]){
            input[writeIndex++]=input[i];
        }
    }
    return writeIndex;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> input={2,3,5,5,7,11,11,11,13};
    int lastIndex=deleteDuplicatesInSortedArray(input);
    cout<<lastIndex<<endl;
    for(int i=0;i<input.size();i++){
        cout<<input[i]<<" ";
    }
    return 0;
}
