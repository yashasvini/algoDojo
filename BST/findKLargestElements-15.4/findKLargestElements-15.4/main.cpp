//
//  main.cpp
//  findKLargestElements-15.4
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


void ReverseInorderTraversalUtil(shared_ptr<TreeNode<int>> root,int num,int& covered){
    
    if(!root ){
        return;
    }
    if(covered<=num){
        ReverseInorderTraversalUtil(root->right,num,covered);
    }
    if(covered<=num){
        cout<<" "<<root->data<<" ";
        covered++;
        ReverseInorderTraversalUtil(root->left,num,covered);
    }
}

void ReverseInorderTraversal(shared_ptr<TreeNode<int>> root,int num){
    int covered=1;
    return ReverseInorderTraversalUtil(root,num,covered);
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
    ReverseInorderTraversal(temp,3);
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
