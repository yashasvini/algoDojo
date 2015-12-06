//
//  main.cpp
//  closestIntWithWeight-5.4
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>

using namespace std;

void closestIntWithWeight(){
    int num;
    cin>>num;
    bitset<32> binary(num);
    cout<<endl<<binary<<endl;
    for(int i=0;i<32;i++){
        if(((num>>i)& 1)!=((num>>(i+1))&1)){
            // swap them using bitmask
            int bitmask=(1<<i)|(1<<(i+1));
            num^=bitmask;
            break;
        }
    }
    bitset<32> binary1(num);
    cout<<num<<endl<<binary1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    closestIntWithWeight();
    return 0;
}
