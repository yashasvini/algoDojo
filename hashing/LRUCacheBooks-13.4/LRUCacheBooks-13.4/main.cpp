//
//  main.cpp
//  LRUCacheBooks-13.4
//
//  Created by yashasvi on 11/28/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

/* implement a LRU cache*/

typedef int ISBN;
typedef int PRICE;

template <size_t capacity>
class LRUCache{
public:
    bool Lookup(ISBN isbn,PRICE &price){
        auto it=isbn_price_table_.find(isbn);
        if(it==isbn_price_table_.end()){
            return false;
        }
        price=it->second.second;
        MoveToFront(isbn, it);
        return true;
    }
    void Insert(ISBN isbn,PRICE price){
        // check if item is present hash table
        auto it=isbn_price_table_.find(isbn);
        if(it!=isbn_price_table_.end()){
            // already present
            MoveToFront(isbn,it);
        }
        else {
            if(isbn_price_table_.size()==capacity){
                //remove least used entry from cache and queue
                isbn_price_table_.erase(lru_queue_.back());
                lru_queue_.pop_back();
            }
                // add new item into cache and queue
            lru_queue_.push_front(isbn);
            isbn_price_table_[isbn]={lru_queue_.begin(),price};
        }
    }
        
        
    bool Remove(ISBN isbn){
        auto it=isbn_price_table_.find(isbn);
        if(it!=isbn_price_table_.end()){
            list<int> ::iterator itr;
           // *itr=isbn;
            auto queueItr = lru_queue_.erase(it->second.first);
         // auto queueItr = lru_queue_.erase(itr);
         //   isbn_price_table_.erase(it);
            return true;
        }
        return false;

    }
    private:
        typedef unordered_map<ISBN,pair<list<ISBN>::iterator,PRICE>> Table;
        list<ISBN> lru_queue_;
        Table isbn_price_table_;
        void MoveToFront(int isbn,const Table::iterator& it){
            lru_queue_.erase(it->second.first);
            lru_queue_.push_front(isbn);
            it->second.first=lru_queue_.begin();
        }
};


void TEST_LRU_CACHE(){
    LRUCache<5> testCache;
    testCache.Insert(111,1);
    testCache.Insert(222,2);
    testCache.Insert(333,3);
    testCache.Insert(444,4);
    testCache.Insert(555,5);
    int price;
    bool found = testCache.Lookup(333, price);
    if(found){
        cout<<"Price is "<<price<<endl;
    }
   testCache.Insert(666,6);
    found = testCache.Lookup(111, price);
    if(found){
        cout<<"Now Price is"<<price;
    }
    else{
        cout<<"cache miss"<<endl;
    }
    
    testCache.Remove(222);
    testCache.Insert(111,1);
    found = testCache.Lookup(111, price);
    if(found){
        cout<<"Now Price is"<<price;
    }
    else{
        cout<<"cache miss"<<endl;
    }


    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST_LRU_CACHE();

    return 0;
}
