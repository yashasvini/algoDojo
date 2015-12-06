//
//  main.cpp
//  checkBalancedBT-10.1
//
//  Created by yashasvi on 11/26/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


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
int height(shared_ptr<BinaryTreeNode<int>> root)
{
    if (root==NULL){
        return 0;
    }
    else
    {
        /* compute the height of each subtree */
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

pair<bool,int> checkIfTreeIsBalanced(shared_ptr<BinaryTreeNode<int>> root){
    //base case
    if(root==NULL){
        return (pair<bool,int>(true,0));
    }
    pair<bool,int> leftCheck= checkIfTreeIsBalanced(root->left);
    if(!leftCheck.first){
        return pair<bool,int>(false,-1);
    }
    pair<bool,int> rightCheck= checkIfTreeIsBalanced(root->right);
    if(!rightCheck.first){
        return pair<bool,int>(false,-1);
    }
    
    bool isBalanced = abs(leftCheck.second-rightCheck.second)<=1?1:0;
    int height = max(leftCheck.second,rightCheck.second)+1;
    return pair<bool,int>(isBalanced,height);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
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
     root->left->right->right->right->right=newNode(13);
    //root->right->left->left=newNode(12);
    //root->right->left->right=newNode(13);
    pair<bool,int> result = checkIfTreeIsBalanced(root);
    cout<<"result is"<<result.first<<":"<<result.second;
    
    return 0;
}
