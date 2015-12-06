//
//  main.cpp
//  BFSTree
//
//  Created by yashasvi on 12/6/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename t>
struct TreeNode{
    t data;
    shared_ptr<TreeNode> left,right;
};

void BFS(shared_ptr<TreeNode<int>> & node){
    shared_ptr<TreeNode<int>> temp=node;
    queue<shared_ptr<TreeNode<int>>> q;
    if(node->data == NULL){
        return;
    }
    
    q.push(temp);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}

shared_ptr<TreeNode<int>> AddNode(int data){
    shared_ptr<TreeNode<int>> newnode(new TreeNode<int>);
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void TEST(){
    shared_ptr<TreeNode<int>> root=AddNode(19);
    root->left=AddNode(7);
    root->right=(AddNode(43));
    root->left->left=(AddNode(2));
    root->left->right = AddNode(10);
    root->right->left=(AddNode(23));
    root->right->right = AddNode(55);
    BFS(root);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
