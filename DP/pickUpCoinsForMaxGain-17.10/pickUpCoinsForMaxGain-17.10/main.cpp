//
//  main.cpp
//  pickUpCoinsForMaxGain-17.10
//
//  Created by yashasvi on 12/3/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>

#include <vector>
#include <numeric>

using namespace std;


int PickUpCoinsHelper(vector<int> &C,int a,int b,vector<vector<int>> &T){
    if(a>b){
        return 0;// base case, coin index cross over, done with parsing both sides of the coins
    }
    
    T[a][b]=max(C[a]+min(PickUpCoinsHelper(C,a+2,b,T),
                         PickUpCoinsHelper(C,a+1,b-1,T)),
                (C[b]+min(PickUpCoinsHelper(C,a+1,b-1,T),
                          PickUpCoinsHelper(C,a,b-2,T))));
    return T[a][b];
}
int PickUpCoins(vector<int> & C){
    vector<vector<int>> T(C.size(),vector<int>(C.size(),-1));
    return PickUpCoinsHelper(C,0,C.size()-1,T);
}

void TEST(){
    vector<int> C={25,5,10,5,10,5,10,25,1,25,1,25,1,25,5,10};
    int sum= accumulate(C.begin(),C.end(),0);
    cout<<"sum is"<<sum<<endl;
    cout<<PickUpCoins(C);
}
                

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
