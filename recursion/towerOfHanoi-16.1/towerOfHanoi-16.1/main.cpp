//
//  main.cpp
//  towerOfHanoi-16.1
//
//  Created by yashasvi on 11/30/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <stack>
#include <array>

using namespace std;

const int MaxPegs=3;

void ComputeTowerOfHanoiHelper(array<stack<int>,MaxPegs>& pegs,int rings,int fromPeg,int toPeg, int usePeg){
    if(rings>0){
        ComputeTowerOfHanoiHelper(pegs,rings-1,fromPeg,usePeg,toPeg);
        pegs[toPeg].push(pegs[fromPeg].top());
        pegs[fromPeg].pop();
        cout<<"moving from "<<fromPeg<<"to"<<toPeg<<endl;
        ComputeTowerOfHanoiHelper(pegs,rings-1,usePeg,toPeg,fromPeg);
    }
}

void ComputeTowerOfHanoi(int rings){
    array<stack<int>,MaxPegs> pegs;
    for(int i=rings;i>=1;i--){
        pegs[0].push(i);
    }
    ComputeTowerOfHanoiHelper(pegs,rings,0,1,2);
}


void TEST(){
    ComputeTowerOfHanoi(5);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
