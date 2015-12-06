//
//  main.cpp
//  sumTheRootToLeafPath-10.5
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

int sumTheRootToLeafPathUtil(shared_ptr<BinaryTreeNode<int>> root,int partial_sum){
    if(root==nullptr){
        return 0;
    }
    
    partial_sum=partial_sum*10+root->data;
    // found the leaf
    if(root->left==NULL && root->right==NULL){
        return partial_sum;
    }
    
    //else,non leaf
    return (sumTheRootToLeafPathUtil(root->left, partial_sum)+sumTheRootToLeafPathUtil(root->right,partial_sum));
}



int sumTheRootToLeafPath(shared_ptr<BinaryTreeNode<int>> root){
    return sumTheRootToLeafPathUtil(root,0);
}


void TEST_SUM_OF_ALL_ROOT_TO_LEAF_PATH(){
    shared_ptr<BinaryTreeNode<int>> root =newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    root->left->left->left=newNode(8);
    root->left->left->right=newNode(9);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(2);
    cout<<"SUM IS:"<<sumTheRootToLeafPath(root);

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST_SUM_OF_ALL_ROOT_TO_LEAF_PATH();
    return 0;
}
