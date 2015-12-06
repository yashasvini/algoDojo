//
//  main.cpp
//  stringDictionaryMatch
//
//  Created by yashasvi on 12/5/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

// the idea is a dfs traversal

bool dfs(string s,int i,set<string> &dict){
    // check if the entire string is present in dict
    if(dict.find(s.substr(i))!=dict.end()){
        return true;
    }
    for(int j=i;j<s.length();j++){
        cout<<"substr: "<<s.substr(i,(j-i)+1)<<endl;
        if(dict.find(s.substr(i,(j-i)+1))!=dict.end()){
            if(dfs(s,j+1,dict)){
                return true;
            }
        }
    }
    return false;
}

bool stringBreak(string &s,set<string>& dict){
    return dfs(s,0,dict);
}

bool dfsWithDP(string s,int i,set<string> &dict,unordered_set<int> & memo){
    // check if the entire string is present in dict
    if(dict.find(s.substr(i))!=dict.end()){
        return true;
    }
    if(memo.find(i)!= memo.end()){
        return false;
    }
    for(int j=i;j<s.length();j++){
        cout<<"substr: "<<s.substr(i,(j-i)+1)<<endl;
        if(dict.find(s.substr(i,(j-i)+1))!=dict.end()){
            if(dfs(s,j+1,dict)){
                return true;
            }
        }
    }
    
    memo.emplace(i);
    return false;
}

bool stringBreakWithDP(string &s,set<string>& dict){
    unordered_set<int> memo;
    return dfsWithDP(s,0,dict,memo);
}



void TEST(){
    set<string> dict={"hello","wo","lr","d"};
    string s="helloworld";
    cout<<stringBreak(s,dict);
    set<string> dict1={"hello","wo","lr","d"};
    string s1="helloworld";
    cout<<stringBreak(s1,dict1);
    

}
               


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
