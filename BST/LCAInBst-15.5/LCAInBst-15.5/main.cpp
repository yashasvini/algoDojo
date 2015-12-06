//
//  main.cpp
//  LCAInBst-15.5
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

shared_ptr<TreeNode<int>> LCA(shared_ptr<TreeNode<int>> tree,shared_ptr<TreeNode<int>> node1,shared_ptr<TreeNode<int>> node2){
    
    if(tree->data > node1->data && tree->data< node2->data){
        return tree;
    }
    if(tree->data > node1->data && tree->data > node2->data){
        return LCA(tree->left,node1,node2);
    }
    if(tree->data < node1->data && tree->data < node2->data){
        return LCA(tree->right,node1,node2);
    }
    return NULL;
}
void TEST(){
    shared_ptr<TreeNode<int>> root=AddNode(19);
    root->left=AddNode(7);
    root->right=(AddNode(43));
    root->left->left=(AddNode(2));
    root->left->right = AddNode(10);
    root->right->left=(AddNode(23));
    root->right->right = AddNode(55);
    root->left->left->left=AddNode(-10);
    auto result = LCA(root,root->left->left->left,root->left->right);
    if(result){
        cout<<result->data;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
