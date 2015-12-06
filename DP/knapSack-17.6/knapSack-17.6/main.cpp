//
//  main.cpp
//  knapSack-17.6
//
//  Created by yashasvi on 12/2/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

struct Item{
    int weight,value;
};

int KnapSack(vector<Item> &items,int w){
    vector<int> result(w+1,0);
    for(int i=0;i<items.size();i++){
        for(int j=w;j>=items[i].weight;j--){
            result[j]=max(result[j],result[j-items[i].weight]+items[i].value);
        }
    }
    return result[w];
}

int knapSack(vector<Item> &items,int w)
{
    vector<vector<int>> result(items.size(),w,0);
}
void TEST(){
    vector<Item> items;
    items.push_back(Item{65,20});
    items.push_back(Item{35,8});
    items.push_back(Item{245,60});
    items.push_back(Item{195,65});
    items.push_back(Item{55,50});
    items.push_back(Item{150,70});
    items.push_back(Item{275,85});
    items.push_back(Item{155,25});
    items.push_back(Item{120,30});
    items.push_back(Item{320,65});
    items.push_back(Item{75,75});
    items.push_back(Item{40,10});
    items.push_back(Item{200,95});
    
    items.push_back(Item{100,50});
    items.push_back(Item{220,40});
    items.push_back(Item{99,10});
    
    int w=130;
    cout<<KnapSack(items,w);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
