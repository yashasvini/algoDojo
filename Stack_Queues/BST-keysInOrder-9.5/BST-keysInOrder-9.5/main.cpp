//
//  main.cpp
//  BST-keysInOrder-9.5
//
//  Created by yashasvi on 11/25/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename t>
struct BSTNode{
    t data;
    std::shared_ptr<BSTNode<t>> left;
    std::shared_ptr<BSTNode<t>> right;
};

vector<int> BSTInSortedOrder(shared_ptr<BSTNode<int>> &tree){
    stack<const BSTNode<int>*> s;
    vector<int> result;
     const auto *curr=tree.get();
    while(!s.empty()||curr){
        if(curr){
            s.push(curr);
            curr=curr->left.get();
        }
        else{
            curr=s.top();
            s.pop();
            result.push_back(curr->data);
            curr=curr->right.get();
        }
    }
    
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
