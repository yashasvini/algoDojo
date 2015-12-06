//
//  main.cpp
//  IntervalEnclose-12.2.2
//
//  Created by yashasvi on 11/28/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


pair<int,int>findEnclosureInterval(const vector<int>& A,int value){
    int low=0,high=A.size()-1,index=-1;
    bool found_value=false;
    while(low<=high){
        int mid=(low+high)/2;
        if(A[mid]==value){
            found_value=true;
            index=mid;
            break;
        }
        else if(A[mid]>value){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    if(!found_value){
        return {-1,-1};
    }
    // check for value before and after the index at which it was found
  //  int l=index-1,r=index-1;
    int left=index,right=index;
    for(int j=index+1;j<=A.size()-1;j++){
        if(A[j]==value){
            right++;
        }
    }
    for(int i=index-1;i>=0;i--){
        if(A[i]==value){
            left--;
        }
    }
    
    if(A[left]==value &&A[right]==value){
        return {left,right};
    }
    if(A[left]==value && A[right]!=value){
        return {left,index};
    }
    else if(A[left]!=value && A[right]==value){
        return {index,right};
        }
    else {
        return {index,index};
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> A={1,2,2,4,5,6,6,6,9,10};
    pair<int,int> result = findEnclosureInterval(A,1);
    cout<<result.first<<":"<<result.second;
    return 0;
}
