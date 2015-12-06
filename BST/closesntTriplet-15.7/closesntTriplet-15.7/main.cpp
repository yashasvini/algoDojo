//
//  main.cpp
//  closesntTriplet-15.7
//
//  Created by yashasvi on 12/6/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template <typename t>

struct TreeNode{
    t data;
    shared_ptr<TreeNode> left,right;
};

shared_ptr<TreeNode<int>> AddNode(int data){
    shared_ptr<TreeNode<int>> newnode(new TreeNode<int>);
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct triplet{
    int a,b,c;
};

int findIndexOfSmallestThanKey(vector<int> &A,int i,int key){
    int low=i,high=A.size();
    int maxSoFar=i;
    int mid=0;
    while(low<=high){
         mid =low+high/2;
        if(A[mid]<key){
            maxSoFar=mid;
            //low=mid+1;
            break;
            }
        else{
            high=mid-1;
        }
        
        }
    return maxSoFar;
}

triplet FindClosestTriplet(vector<int> &A,vector<int> &B,vector<int> &C){
    int diff=numeric_limits<int>::max();
    triplet minValue;

    int i=0,j=0,k=0;
    while(i<A.size()&&j<B.size()&&k<C.size()){
        int minimum=min(A[i],min(B[j],C[k]));
        int maximum=max(A[i],max(B[j],C[k]));
        if(maximum-minimum<diff){
            diff=maximum-minimum;
            minValue.a=A[i];minValue.b=B[j];minValue.c=C[k];
        }
        if(diff==0){
            break;
        }
        // increment the array with least value;
        if(A[i]==minimum){
            int newIndex = findIndexOfSmallestThanKey(A,i,maximum);
            if(newIndex==i){
                i++;
            }
            cout<<A[i];
        }
        else if(B[j]==minimum)
        {
           int newIndex =findIndexOfSmallestThanKey(B,j,maximum);
            if(newIndex==j){
                j++;
            }
            cout<<B[j];
        }
        else{
            int newIndex =findIndexOfSmallestThanKey(C,k,maximum);
            if(newIndex==k){
                k++;
            }
            cout<<C[k];
        }
    }
    return minValue;
}



void TEST(){
    vector<int> A={5,10,15};
    vector<int> B={3,6,9,12,15};
    vector<int> C={8,16,24};
    auto result = FindClosestTriplet(A, B, C);
    
    cout<<result.a<<" "<<result.b<<" "<<result.c;
    
}

void TEST_findIndexOfSmallestThanKey(){
    vector<int> B={3,6,9,12,15,17,20};
    int key=20;
    auto result = findIndexOfSmallestThanKey(B, 0, key);
    cout<<B[result];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
   // TEST();
    TEST_findIndexOfSmallestThanKey();
    return 0;
}
