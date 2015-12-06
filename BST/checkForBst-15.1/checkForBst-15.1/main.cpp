//
//  main.cpp
//  checkForBst-15.1
//
//  Created by yashasvi on 11/30/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

template <typename t>
struct node{
    t data;
    shared_ptr<node> left,right;
};

shared_ptr<node<int>> NewNode(int data){
    shared_ptr<node<int>> n(new node<int>);
    n->data=data;
    n->left=nullptr;
    n->right=nullptr;
    return n;
}

bool IsTreeInRange(shared_ptr<node<int>> tree,int min,int max){
    if(tree==nullptr){
        return true;
    }
    else if(tree->data < min || tree->data > max){
        return false;
    }
    return (IsTreeInRange(tree->left,min,tree->data) && IsTreeInRange(tree->right,tree->data,max));
    
}
bool CheckIfTreeIsBst(shared_ptr<node<int>> root){
    return IsTreeInRange(root,numeric_limits<int>::min(),numeric_limits<int>::max());
    
}


// The above solution always explores the left sub tree first,
// if we want to find out if a right tree at a lower depth is violating?

//using a queue and do a bfs.

struct QueueEntry{
    shared_ptr<node<int>> treeNode;
    int lowerBound,upperBound;
};

bool CheckIfTreeIsBstUsingBfs(shared_ptr<node<int>> root){
    queue<QueueEntry> bfsQ;
    bfsQ.push(QueueEntry{root,numeric_limits<int>::min(),numeric_limits<int>::max()});
    
   while(!bfsQ.empty()){
        if(bfsQ.front().treeNode.get()){
            if(bfsQ.front().treeNode.get()->data < bfsQ.front().lowerBound ||
               bfsQ.front().treeNode.get()->data > bfsQ.front().upperBound){
                return false;
            }
            bfsQ.push(QueueEntry{bfsQ.front().treeNode->left,bfsQ.front().lowerBound,bfsQ.front().treeNode.get()->data});
            bfsQ.push(QueueEntry{bfsQ.front().treeNode->right,bfsQ.front().treeNode.get()->data,bfsQ.front().upperBound});
        }
        bfsQ.pop();
    }
    return true;
}

void TEST_FAILURE(){
    cout<<"TEST_FAILURE():";
    shared_ptr<node<int>> root= NewNode(10);
    shared_ptr<node<int>> root2=root;
    root->left=NewNode(9);
    root->right=NewNode(11);
    root->left->left=NewNode(8);
    root->left->right=NewNode(15);
    root->right->left=NewNode(4);
    root->right->right=NewNode(21);
    if(CheckIfTreeIsBst(root)){
        cout<<"TEST PASS";
    }
    else {
        cout<<"TEST FAILED";
    }
    cout<<endl;
    if(CheckIfTreeIsBstUsingBfs(root2)){
        cout<<"TEST PASS";
    }
    else {
        cout<<"TEST FAILED";
    }
}

void TEST_SUCCESS(){
    cout<<"TEST_SUCCESS():";
    shared_ptr<node<int>> root= NewNode(10);
    shared_ptr<node<int>> root2=root;
    root->left=NewNode(5);
    root->right=NewNode(18);
    root->left->left=NewNode(3);
    root->left->right=NewNode(8);
    root->right->left=NewNode(12);
    root->right->right=NewNode(21);
   if(CheckIfTreeIsBst(root2)){
        cout<<"TEST PASS";
    }
    else {
        cout<<"TEST FAILED";
    }   
    cout<<endl;
    if(CheckIfTreeIsBstUsingBfs(root)){
        cout<<"TEST PASS";
    }
    else {
        cout<<"TEST FAILED";
    }


}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST_SUCCESS();
    TEST_FAILURE();
    return 0;
}
