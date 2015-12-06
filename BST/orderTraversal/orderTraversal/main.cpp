//
//  main.cpp
//  orderTraversal
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

void InorderTraversal(shared_ptr<TreeNode<int>> root){
    if(!root){
        return;
    }
    InorderTraversal(root->left);
    cout<<" "<<root->data<<" ";
    InorderTraversal(root->right);
}

void PreorderTraversal(shared_ptr<TreeNode<int>> root){
    if(!root){
        return;
    }
    cout<<" "<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
void PostorderTraversal(shared_ptr<TreeNode<int>> root){
    if(!root){
        return;
    }
    
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout<<" "<<root->data<<" ";
}


void TEST(){
    shared_ptr<TreeNode<int>> root=AddNode(19);
    root->left=AddNode(7);
    root->right=(AddNode(43));
    root->left->left=(AddNode(2));
    root->left->right = AddNode(10);
    root->right->left=(AddNode(23));
    root->right->right = AddNode(55);
    auto temp=root;
    InorderTraversal(temp);
    cout<<endl;
    temp=root;
    PreorderTraversal(temp);
    cout<<endl;
    temp=root;
    PostorderTraversal(temp);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
