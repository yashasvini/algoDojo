//
//  main.cpp
//  dutchNationalFlag-6.1
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void threeWayPartition(){
    vector<int> arr={3,2,1,1,2,3,3,2,2,1,3,1};
    //here pivot is 2
    int pivot=2;
    int small =0;
    int large=arr.size()-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<pivot){
            swap(arr[i], arr[small]);
            small++;
        }
    }
    for(int j=arr.size()-1;j>=0;j--){
        if(arr[j]>pivot){
            swap(arr[j],arr[large]);
            large--;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    threeWayPartition();
    return 0;
}
