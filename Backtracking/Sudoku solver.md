```cpp
#include<bits/stdc++.h>
using namespace std;
#define N 9

bool findEmptyLocation(int** grid,int& row,int& col){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
return false;
}

bool isSafe(int** grid,int row,int col,int data){
//check row wise,column wise and square wise
    for(int i=0;i<N;i++){
        if(grid[row][i]==data){
            return false;
        }
    }
    for(int i=0;i<N;i++){
        if(grid[i][col]==data){
            return false;
        }
    }

    int rowstart=(3*(row/3));
    int colstart=(3*(col/3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[rowstart+i][colstart+j]==data){
                return false;
            }
        }
    }
return true;
}

bool solveSudoku(int** grid){
    int row,col;
    if(!findEmptyLocation(grid,row,col)){
        return true;
    }

    for(int i=1;i<=9;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col]=i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col]=0;//see if this line makes any changes
        }
    }
    return false;
}

int main(){

    int** grid=new int*[N];
    for(int i=0;i<N;i++){
        grid[i]=new int[N];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }

    solveSudoku(grid);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }cout<<endl;
    }
    
return 0;
}
```
