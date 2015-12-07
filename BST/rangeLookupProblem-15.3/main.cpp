//
//  main.cpp
//  rangeLookupProblem-15.3
//
//  Created by yashasvi on 12/7/15.
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

shared_ptr<TreeNode<int>> AddNode(int data){
    shared_ptr<TreeNode<int>> newnode(new TreeNode<int>);
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void RangeLookupInBstUtil(shared_ptr<TreeNode<int>> node,pair<int,int> interval,vector<int> &result){
    if(node==nullptr){
        return;
    }
    if(node->data >= interval.first && node->data <= interval.second ){
        RangeLookupInBstUtil(node->left,interval,result);
        result.push_back(node->data);
        RangeLookupInBstUtil(node->right, interval, result);
    }
    else if (node->data < interval.first){
        RangeLookupInBstUtil(node->right,interval,result);
    }
    else{//(node->data > interva.second)
        RangeLookupInBstUtil(node->left,interval,result);
    }
}

vector<int> RangeLookupInBst(shared_ptr<TreeNode<int>> root,pair<int,int> interval){
    vector<int> result;
    RangeLookupInBstUtil(root,interval,result);
    return result;
}



void TEST(){
    shared_ptr<TreeNode<int>> root=AddNode(19);
    root->left=AddNode(7);
    root->right=(AddNode(43));
    root->left->left=(AddNode(2));
    root->left->right = AddNode(10);
    root->right->left=(AddNode(23));
    root->right->right = AddNode(55);
    auto result = RangeLookupInBst(root,pair<int,int>(5,45));
    for(auto iter:result){
        cout<<iter<<" ";
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
