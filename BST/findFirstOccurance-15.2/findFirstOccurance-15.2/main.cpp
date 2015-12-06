//
//  main.cpp
//  findFirstOccurance-15.2
//
//  Created by yashasvi on 12/6/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>

using namespace std;


struct TreeNode{
    int data;
    shared_ptr<TreeNode> left,right;
    string name;
};

shared_ptr<TreeNode> AddNode(int data,string name){
    shared_ptr<TreeNode> newnode(new TreeNode);
    newnode->data = data;
    newnode->name=name;
    newnode->left=newnode->right=NULL;
    return newnode;
}


string FindFirstOccuranceKey(shared_ptr<TreeNode> node,int key,string isFound){
    if(node==nullptr){
        return "NOT FOUND";
    }
    if(!isFound.empty() && key!=node->data){
        return isFound;
    }
    if(key<node->data){
        return FindFirstOccuranceKey(node->left,key,"");
    }
    if(key>node->data){
        return FindFirstOccuranceKey(node->right,key,"");
    }
    
    if(node->data==key){
        return FindFirstOccuranceKey(node->left,key,node->name);
    }
    return "Not FOUND";
}


string FindFirstOccuranceKeyIterative(shared_ptr<TreeNode> node,int key){
    shared_ptr<TreeNode> firstSoFar=NULL,temp=node;
    if(!node){;
        return "NOT FOUND";
    }
    while(temp){
        if(temp->data<key){
            temp=temp->left;
        }
        else if(temp->data>key){
            temp=temp->right;
        }
        else if(temp->data==key){
            firstSoFar=temp;
            temp=temp->left;
        }
    }
    return firstSoFar->name;
    
}

void TEST(){
    shared_ptr<TreeNode> root=AddNode(108,"A");
    root->left=AddNode(108,"B");
    root->right=AddNode(285,"G");
    root->left->left=AddNode(-10,"C");
    root->left->right=AddNode(108,"F");
    root->left->left->left=AddNode(-14,"D");
    root->left->left->right=AddNode(2,"E");
    root->right->left=AddNode(243,"H");
    root->right->right=AddNode(285,"I");
    
//    cout<<FindFirstOccuranceKey(root,108,"");
    cout<<FindFirstOccuranceKeyIterative(root,108);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
