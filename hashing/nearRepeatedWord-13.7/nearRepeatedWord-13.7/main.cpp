//
//  main.cpp
//  nearRepeatedWord-13.7
//
//  Created by yashasvi on 11/29/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int FindNearestRepeatedIndex(const vector<string>& paragraph)
{
    unordered_map<string,int > word_to_latest_index;
    int nearest_repeated_distance = 	numeric_limits<int>::max();
    for(int i=0;i<paragraph.size();i++){
        auto latest_equal_word = word_to_latest_index.find(paragraph[i]);
        if(latest_equal_word!=word_to_latest_index.end()){
            nearest_repeated_distance =min(nearest_repeated_distance,i- latest_equal_word->second);
        }
        word_to_latest_index[paragraph[i]]=i;
    }
    return nearest_repeated_distance;
}
           

void TEST_CASE(){
    vector<string> input={"All","work","no","play","makes","for","no","work","no","fun","no","results"};
    int result = FindNearestRepeatedIndex(input);
    cout<<result;
}
           
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST_CASE();
    return 0;
}
