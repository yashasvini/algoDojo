//
//  main.cpp
//  taverse2DArray-17.3
//
//  Created by yashasvi on 12/1/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int Traverse2DArray(int row,int col){
    int result[row][col];
    for(int i=0;i<row;i++){
        result[i][0]=1;
    }
    for(int j=0;j<col;j++){
        result[0][j]=1;
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            result[i][j]=result[i-1][j]+result[i][j-1];
        }
    }
    return result[row-1][col-1];
}


// obsatacle matrix is filled iwth true where there are obstacles
int Traverse2DArrayWithObstacles(int row,int col,vector<vector<bool>>& B){
    vector<vector<int>> result (row,vector<int>(col,0));
    if(B[0][0]){
        return 0;
    }
    result[0][0]=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(B[i][j]==false){// no obstacle
                result[i][j]+=(i==0?0:result[i-1][j])+(j==0?0:result[i][j-1]);
            }
        }
    }
    return result.back().back();
}

void TEST(){
    cout<<Traverse2DArray(5,5)<<endl;
    vector<vector<bool>> B(5,vector<bool>(5,false));
    cout<<Traverse2DArrayWithObstacles(5,5,B);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TEST();
    return 0;
}
