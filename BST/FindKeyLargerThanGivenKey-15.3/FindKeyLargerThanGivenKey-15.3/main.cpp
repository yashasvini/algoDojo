//
//  main.cpp
//  FindKeyLargerThanGivenKey-15.3
//
//  Created by yashasvi on 12/6/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename t>
struct TreeNode{
    t data;
    shared_ptr<TreeNode> left,right;
};

shared_ptr<TreeNode<int>> AddNode(int data){
    shared_ptr<TreeNode<int>> newnode(new TreeNode<int>);
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

shared_ptr<TreeNode<int>> FindKeyLargerThanGivenKey(shared_ptr<TreeNode<int>> node,int key){
    if(node==NULL){
        return NULL;
    }
    auto temp=node;
    shared_ptr<TreeNode<int>> firstSoFar;
    while(temp){
        if(temp->data>key){
            firstSoFar=temp;
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return firstSoFar;
}

void TEST(){
    shared_ptr<TreeNode<int>> root=AddNode(19);
    root->left=AddNode(7);
    root->right=(AddNode(43));
    root->left->left=(AddNode(2));
    root->left->right = AddNode(10);
    root->right->left=(AddNode(23));
    root->right->right = AddNode(55);
    auto result = FindKeyLargerThanGivenKey(root,23);
    if(result){
        cout<<result->data;
    }
    else {
        cout<<"Key not found";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
