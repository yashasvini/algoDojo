//
//  main.cpp
//  tailUnix-7.13
//
//  Created by yashasvi on 11/22/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void tail(const string &filename,int count){
    ifstream fileStrm;
    fileStrm.open(filename);
    fileStrm.seekg(0,ios::end);
    int num = fileStrm.tellg();
    fileStrm.clear();
    cout<<num<<endl;
    string line;
    //vector<string> output;
    string output;
    int lineCount=0;
  
    if(fileStrm.is_open()){
        
        cout<<fileStrm.tellg();
        for(int i=0;i<num;i++){
            fileStrm.seekg(-1-i,ios::end);
            char c = fileStrm.get();
            if(c=='\n'){
                lineCount++;
                if(lineCount==count){
                    break;
                }
            }
            output.push_back(c);
        }
        
    }
    fileStrm.close();
    reverse(output.begin(),output.end());
    cout<<output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s="/Users/yashasvi/test_code/tailUnix.cc";
    tail(s,5);
    return 0;
}
