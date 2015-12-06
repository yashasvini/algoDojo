//
//  main.cpp
//  LCA-10.3
//
//  Created by yashasvi on 11/26/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*Lowest common ancestor*/

template <typename t>
struct BinaryTreeNode{
    t data;
    std::shared_ptr<BinaryTreeNode<t>> left;
    std::shared_ptr<BinaryTreeNode<t>> right;
};

std::shared_ptr<BinaryTreeNode<int>>newNode(int data)
{
    shared_ptr<BinaryTreeNode<int>>node(new BinaryTreeNode<int>);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

pair<int,shared_ptr<BinaryTreeNode<int>>> LCAHelper(shared_ptr<BinaryTreeNode<int>> root,shared_ptr<BinaryTreeNode<int>> node0,shared_ptr<BinaryTreeNode<int>> node1){
    if(root==NULL){
        return pair<int,shared_ptr<BinaryTreeNode<int>>>(0,nullptr);
    }
    int leftCount = LCAHelper(root->left,node0,node1).first;
    if(leftCount==2){
        return pair<int,shared_ptr<BinaryTreeNode<int>>>(2,root->left);
    }
    int rightCount = LCAHelper(root->right,node0,node1).first;
    if(rightCount==2){
        return pair<int,shared_ptr<BinaryTreeNode<int>>>(2,root->right);
    }
    int maxCount = leftCount+rightCount+(root==node0||root==node1);
    return pair<int,shared_ptr<BinaryTreeNode<int>>>(maxCount,root);
    
}
shared_ptr<BinaryTreeNode<int>> LCA(shared_ptr<BinaryTreeNode<int>> root, shared_ptr<BinaryTreeNode<int>> node0,shared_ptr<BinaryTreeNode<int>>node1){
    if(root==NULL){
        return nullptr;
    }
    return LCAHelper(root,node0,node1).second;
}


void TEST_LCA(){
    shared_ptr<BinaryTreeNode<int>> root =newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    root->left->left->left=newNode(8);
    root->left->left->right=newNode(9);
    root->left->right->left=newNode(10);
    root->left->right->right=newNode(11);
    root->left->right->right->right=newNode(12);
    root->right->right->right=newNode(13);
    cout<<"LOWEST COMMON ANCESTOR IS:"<<LCA(root,root->left->left->left,root->right->right)->data;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST_LCA();
    return 0;
}
