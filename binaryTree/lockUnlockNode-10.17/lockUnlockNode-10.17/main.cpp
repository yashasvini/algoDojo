//
//  main.cpp
//  lockUnlockNode-10.17
//
//  Created by yashasvi on 11/26/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


template <typename t>
class BinaryTreeNode{
public:
    t data;
    std::shared_ptr<BinaryTreeNode<t>> left;
    std::shared_ptr<BinaryTreeNode<t>> right;
    std::shared_ptr<BinaryTreeNode<t>> parent;
    bool _locked=false;
    int _numOfDescendents;
public:
    
    bool isLocked(){return _locked;}
    bool lock(){
        if(_numOfDescendents>0 || _locked==true){
            return false;
        }
        for(shared_ptr<BinaryTreeNode> iter = this->parent;iter!=NULL;iter=iter->parent){
            if(iter->_numOfDescendents!=0){
                return false;
            }
        }
        _locked=true;
         for(shared_ptr<BinaryTreeNode> iter = this->parent;iter!=NULL;iter=iter->parent){
             iter->_numOfDescendents++;
         }
        return true;
        
    }
    void unlock(){
        if(isLocked()==false){
            cout<<"Already unlocked"<<endl;
            return;
        }
        _locked=false;
        for(shared_ptr<BinaryTreeNode> iter = this->parent;iter!=NULL;iter=iter->parent){
            cout<<"data of parent"<<iter->data;
            cout<<endl;
            iter->_numOfDescendents--;
        }
    }
};

std::shared_ptr<BinaryTreeNode<int>>newNode(int data)
{
    shared_ptr<BinaryTreeNode<int>>node(new BinaryTreeNode<int>);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent=NULL;
    return(node);
}

void TEST_LOCK_UNLOCK_NODE(){
    
    shared_ptr<BinaryTreeNode<int>> root=newNode(1);
     //root->parent=NULL;
    
    root->left=newNode(2);
    root->left->parent=root;
    
    root->right=newNode(3);
    root->right->parent=root;
    
    root->left->left=newNode(4);
    root->left->left->parent=root->left;
    
    root->left->right=newNode(5);
    root->left->right->parent=root->left;
    
    root->right->left=newNode(6);
    root->right->left->parent=root->right;

    root->right->right=newNode(7);
    root->right->right->parent=root->right;
    
    root->left->left->left=newNode(8);
    root->left->left->left->parent=root->left->left;
    
    root->left->left->right=newNode(9);
    root->left->left->right->parent=root->left->right;
    
    root->left->right->left=newNode(10);
    root->left->right->left->parent=root->left->right;
    
    root->left->right->right=newNode(11);
    root->left->right->right->parent=root->right->right;
    
    bool isLocked=root->lock();
    cout<<"LOCKED THE ROOT"<<isLocked<<endl;
    isLocked = root->left->left->left->isLocked();
    cout<<"LOCKED THE node"<<isLocked<<endl;
    root->unlock();
    cout<<"LOCKED THE node "<<root->left->left->left->lock()<<endl;
    cout<<"LOCKED THE node "<<root->left->lock()<<endl;
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST_LOCK_UNLOCK_NODE();
    return 0;
}