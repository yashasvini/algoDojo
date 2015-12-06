//
//  main.cpp
//  incrementArrayElement-6.2
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <array>
using namespace std;

void incrementLastElement(){
    array<int,4> arr={9,9,9,9};

    for(int j=arr.size()-1;j>=0;j--){
        if(arr[j]+1<10){
            arr[j]=arr[j]+1;
            break;
        }
        arr[j]=0;
    }
    
    if(arr[0]==0){
        //overflow
        array<int,5> arr_new;
        arr_new[0]=1;
        for(int i=0;i<arr.size();i++){
            arr_new[i+1]=arr[i];
        }
        for(int i=0;i<arr_new.size();i++){
            cout<<arr_new[i]<<" ";
            break;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    incrementLastElement();
    return 0;
}
