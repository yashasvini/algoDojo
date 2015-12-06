//
//  main.cpp
//  swapBits-5.2
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
using namespace std;

void swapBits(){
    int x,y;
    cin>>x;
    cin>>y;
    int num;
    
    cin>>num;
    bitset<64> binary(num);
    cout<<binary<<endl;
    if((num>>x&1)!=(num>>y&1)){
        int bitmask=1<<x|1<<y;
        num = num^bitmask;
    }
    cout<<num<<endl;
    bitset<64> binary2(num);
    cout<<binary2;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    swapBits();
    return 0;
}
