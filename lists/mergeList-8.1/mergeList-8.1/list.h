//
//  list.h
//  mergeList-8.1
//
//  Created by yashasvi on 11/23/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#ifndef mergeList_8_1_list_h
#define mergeList_8_1_list_h

template<typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

void addNode(shared_ptr<ListNode<int>> *l,int data){
    shared_ptr<ListNode<int>> node(new ListNode<int>);
    node->data=data;
    (*l)->next=node;
    *l=(*l)->next;
}

void deleteNode(shared_ptr<ListNode<int>>*head,int data){
    auto temp = *head;
    if(temp->data==data){
        //move the head
        *head=(*head)->next;
        return;
    }
    // start with 2nd node
    while(temp->next){
        if((temp->next->data)!=data){
            //move the temp ptr to next node
            temp=temp->next;
            continue;
        }
        temp->next=temp->next->next;
    }
}

void printList(shared_ptr<ListNode<int> > l){
    while(l){
        cout<<l->data<<" ";
        l=l->next;
    }
}


#endif
