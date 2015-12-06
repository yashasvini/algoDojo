//
//  main.cpp
//  SymmetricTree-10.2
//
//  Created by yashasvi on 11/26/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>


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

bool isSymmetric(shared_ptr<BinaryTreeNode<int>>l,shared_ptr<BinaryTreeNode<int>>r){
    if(l==NULL && r==NULL){
        return true;
    }
    else if(l!=NULL && r!=NULL){
        return (l->data==r->data&&isSymmetric(l->left,r->right)&& isSymmetric(l->right,r->left));
    }
    return false;
}

bool isMirrored(shared_ptr<BinaryTreeNode<int>>root){
    if(root==NULL||isSymmetric(root->left,root->right)){
        return true;
    }
    return false;
}

void testRealMirror(){
    shared_ptr<BinaryTreeNode<int>> root =newNode(314);
    root->left=newNode(6);
    root->right=newNode(6);
    
    root->left->right=newNode(2);
    root->right->left=newNode(2);
    
    root->left->right->right=newNode(3);
    root->right->left->left=newNode(3);

    cout<<endl<<"TESTING REAL MIRRORS"<<endl;
    cout<<"Is tree mirrorred/symetric?"<<isMirrored(root);

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
   
    cout<<"Is tree mirrorred/symetric?"<<isMirrored(root);
    
    testRealMirror();
    
    return 0;
}
