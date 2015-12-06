//
//  main.cpp
//  numberPalindrome-5.10
//
//  Created by yashasvi on 11/21/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

void checkPalindrome(){
    long long unsigned num;
    cin>>num;
    long long unsigned loopCount=floor(log10(num))+1;
    long long unsigned mask=pow(10,loopCount-1);
    for(long long unsigned i=0;i<loopCount/2;i++){
        long long unsigned msb=num/mask;
        long long unsigned lsb=num%10;
        if (msb!=lsb){
            cout<<"not palindrome";
            return;
        }
        num=num%(mask);
        num=num/10;
        mask=mask/100;
    }
    cout<<"palindrome";
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    checkPalindrome();
    return 0;
}
