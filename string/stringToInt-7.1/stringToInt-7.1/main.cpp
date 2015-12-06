//
//  main.cpp
//  stringToInt-7.1
//
//  Created by yashasvi on 11/22/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
using namespace std;

int stringToInt(string &s){
    int result=0;
    bool isNegative=false;
    if(s[0]=='-'){
        isNegative=true;
    }
    int i=0;
    if(isNegative){
        i=1;
    }
    for(;i<s.size();i++){
        int value = s[i]-'0';
        //result+=value;
        result=result*10+value;
    }
    if(isNegative){
        result=result*(-1);
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s="-200234";
    cout<<stringToInt(s);
    return 0;
}
