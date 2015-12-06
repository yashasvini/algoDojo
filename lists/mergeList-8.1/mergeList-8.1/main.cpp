//
//  main.cpp
//  mergeList-8.1
//
//  Created by yashasvi on 11/23/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
using namespace std;
#include "list.h"


void Append(shared_ptr<ListNode<int>> *node,shared_ptr<ListNode<int> >*tail){
    (*tail)->next=*node;
    // increment tail
    *tail=*node;
    // increment ptr to first list
    *node = (*node)->next;
}


shared_ptr<ListNode<int> > mergeSortedList(shared_ptr<ListNode<int> > l1,shared_ptr<ListNode<int> > l2){
    shared_ptr<ListNode<int>> dummyNext(new ListNode<int>);
    auto tail = dummyNext;
    while(l1 && l2){
        Append(l1->data <= l2->data? &l1 : &l2, &tail);
    }
    tail->next=l1?l1:l2;
    return dummyNext->next;
}

shared_ptr<ListNode<int> > RecursiveReverseList(shared_ptr<ListNode<int>> head){
    shared_ptr<ListNode<int>> first;
    shared_ptr<ListNode<int>> rest;
    first=head;
    rest=head->next;
    if(first==NULL || rest==NULL){
        return head;
    }
    rest = RecursiveReverseList(rest);
    // for: eg 1->2->3->4
    // becomes: 1->2<-3<-4
    // you need to to end of revserved list ,i.e 2 and add 1 to it
    // so first->next(2)->next(1)=1
    // 1->next = null: new end of list
    
    first->next->next=first;
    first->next=NULL;
    return rest;
}


shared_ptr<ListNode<int> > RightShiftList(shared_ptr<ListNode<int>> head,int k){
    if(!head){
        return head;
    }
    //find the length of the list
    auto tail=head;
    int n=0;
    while(tail->next){
        n++;
        tail=tail->next;
    }
    k=k%n;
    if(k==0){
        return head;
    }
    tail->next=head;// make a cycle

    auto new_tail=tail;
    int steps_to_new_head=n-k;
        while(steps_to_new_head--){
        new_tail=new_tail->next;
    }
    auto new_head=new_tail->next;
    new_tail->next=NULL;// break the cycle
    return new_head;
}

shared_ptr<ListNode<int> > IterativeReverseList(shared_ptr<ListNode<int>> head){
    shared_ptr<ListNode<int>> prev=NULL;
    shared_ptr<ListNode<int>> current=head;
    shared_ptr<ListNode<int>> next;
  

    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}



shared_ptr<ListNode<int>> ReverseSubList(shared_ptr<ListNode<int>> head,int f,int l){
    int f_count=0;
    shared_ptr<ListNode<int>> current=head;
    if(head==NULL){
        return head;
    }
    while(current){
        if( f_count==f){
            break;
        }
        current= current->next;
        f_count++;
    }
    cout<<"here fcount"<<f_count<<endl;
    shared_ptr<ListNode<int>> prev=NULL;
    shared_ptr<ListNode<int>> next;
    while(f_count++<l){
       
        next=current->next;
        prev=current;
        current->next=prev;
        current=next;
      
    }
    
    head->next=prev;
    return head;
}

shared_ptr<ListNode<int>> DeleteDuplicateSortedList(shared_ptr<ListNode<int>> head){
    auto iter =head;
        while(iter){
       auto next_distinct=iter->next;
        // find the next distinct node
        while(next_distinct && next_distinct->data==iter->data){
            
            next_distinct=next_distinct->next;
        }
        iter->next=next_distinct;
        iter=next_distinct;
       
    }
    return head;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    shared_ptr<ListNode<int>> l1Head(new ListNode<int>);
    auto temp=l1Head;
    l1Head->data=10;
    addNode(&temp, 12);
    addNode(&temp, 14);
    addNode(&temp, 16);
    temp->next=NULL;
    printList(l1Head);
    shared_ptr<ListNode<int>> l2Head(new ListNode<int>);
    auto temp2=l2Head;
    temp2->data=11;
    addNode(&temp2, 13);
    addNode(&temp2, 15);
    addNode(&temp2, 17);
    temp2->next=NULL;
    printList(l2Head);
    shared_ptr<ListNode<int> > result = mergeSortedList(l1Head,l2Head);
    cout<<endl;
    printList(result);
    deleteNode(&result,15);
    cout<<endl;
    printList(result);
    shared_ptr<ListNode<int>> reverseHead = RecursiveReverseList(result);
    cout<<endl;
    printList(reverseHead);
    
    cout<<endl<<"Reversing using iteration"<<endl;
    shared_ptr<ListNode<int>> reverseHeadItr = IterativeReverseList(reverseHead);
    
    printList(reverseHeadItr);
    
   /* cout<<endl<<"Reversing subset from 2 to 5 elements"<<endl;
    shared_ptr<ListNode<int>> reverseSublist = ReverseSubList(reverseHeadItr,2,5);
    printList(reverseSublist);*/
    shared_ptr<ListNode<int>> sortedList(new ListNode<int>);
    sortedList->data=2;
    auto temp_sort=sortedList;
    addNode(&temp_sort,2);
    addNode(&temp_sort,4);
    addNode(&temp_sort,4);
    addNode(&temp_sort,6);
    addNode(&temp_sort,8);
    addNode(&temp_sort,10);
    addNode(&temp_sort,10);
    cout<<endl;
    printList(sortedList);
    auto temp_sort1 = DeleteDuplicateSortedList(sortedList);
    cout<<endl;
    printList(temp_sort1);
    cout<<endl;
    shared_ptr<ListNode<int>> temp_shift1=RightShiftList(temp_sort1,2);
    cout<<endl;
    printList(temp_shift1);
    return 0;
}
