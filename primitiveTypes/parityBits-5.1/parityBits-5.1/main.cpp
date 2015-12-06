//
//  main.cpp
//  parityBits-5.1
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
using namespace std;

bool parity(long unsigned x){
    long unsigned x1=1;
    x^=x>>32;
    x^=x>>16;
    x^=x>>8;
    x^=x>>4;
    x^=x>>2;
    x^=x>>1;
    return (x&x1);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    if(parity(2)){
        cout<<"odd parity";
    }
    else{
        cout<<"even parity";
    }
    return 0;
}
