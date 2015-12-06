//
//  main.cpp
//  MaxStack
//
//  Created by yashasvi on 11/25/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <stack>


using namespace std;



class MaxStackWithCache{
public:
    void Push(int val){
        cachedStack.push(pair<int,int>(val,max(val,(cachedStack.empty()?val:Max()))));
    }
    int Pop(){
        
        if(cachedStack.empty()){
            throw length_error("Max Stack Empty");
        }
        int popped_value=cachedStack.top().first;
        cachedStack.pop();
        return popped_value;
    }
    int Max(){
        int maxValue = cachedStack.top().second;
        return maxValue;
    }
private:
    
    stack<pair<int,int>> cachedStack;
};


class MaxStackWithOptimizedCache{
public:
    void Push(int val){
        realStack.push( val);
        if(maxCountStack.empty()){
            maxCountStack.push(pair<int,int>(val,1));
        }
        
        else if(maxCountStack.top().first==val){
            int &l=maxCountStack.top().second;
            l++;
        }
        else if(maxCountStack.top().first<val){
            maxCountStack.push(pair<int,int>(val,1));
        }
     // if lesser than top.first dont add into the maxCount Stack
        
    }
    int Pop(){
        if(realStack.empty()){
            throw length_error("Max Stack Empty");
        }
        
        int popped_value = realStack.top();
        realStack.pop();
        
        if(popped_value==maxCountStack.top().first){
            int &l=maxCountStack.top().second;
            l--;
            if (l==0){
                maxCountStack.pop();
            }
        }
        return popped_value;
    }
    int Max(){
        if(maxCountStack.empty()){
            throw length_error("MAx stack empty");
        }
        int maxValue =maxCountStack.top().first;
        return maxValue;
    }
    void printSizeMaxCountStack(){
        cout<<"Size is"<<maxCountStack.size()<<endl;
    }
private:
    stack<int> realStack;
    stack<pair<int,int>> maxCountStack;
    
};


void test_MaxStackWithOptimizedCache(){
    MaxStackWithOptimizedCache s;
    cout<<endl<<"TESTING MaxStackWithOptimizedCache"<<endl;
    s.Push(5);
    s.Push(10);
    s.Push(7);
    cout<<"Max value is:"<<s.Max();
    s.printSizeMaxCountStack();
    s.Push(11);
    s.Push(11);
    s.Push(4);
    cout<<"Max value now is:"<<s.Max();
    cout<<"Popped out"<<s.Pop();
    cout<<"Popped out"<<s.Pop();
    cout<<"Max value after popping is:"<<s.Max();
    s.printSizeMaxCountStack();
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    MaxStackWithCache s;
    s.Push(5);
    s.Push(10);
    s.Push(7);
    cout<<"Max value is:"<<s.Max();
    s.Push(11);
    s.Push(4);
    cout<<"Max value now is:"<<s.Max();
    cout<<"Popped out"<<s.Pop();
    cout<<"Popped out"<<s.Pop();
    cout<<"Max value after popping is:"<<s.Max();
    test_MaxStackWithOptimizedCache();
    return 0;
}
