//
//  main.cpp
//  countCombinations-17.1
//
//  Created by yashasvi on 11/30/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int CountCombinations(int k,vector<int> &score_ways){
    vector<int> combinations(k+1,0);
    combinations[0]=1;
    for(const int &score: score_ways){
        cout<<"for score:"<<score<<endl;
        for(int j=score;j<=k;++j){
            combinations[j]+=combinations[j-score];
            cout<<j<<":"<<combinations[j]<<",";
        }
        
        cout<<endl;
    }
    return combinations[k];
}


void TEST(){
    vector<int> score_ways={2,3,7};
    int result = CountCombinations(12,score_ways);
    cout<<result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
