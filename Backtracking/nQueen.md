```cpp
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** arr,int n,int row,int col){
    // Same Column
    for(int i=row-1;i>=0;i--){
      if(arr[i][col] == 1){
        return false;
      }
    }
    //Upper Left Diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
      if(arr[i][j] ==1){
        return false;
      }
    }
    // Upper Right Diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
      if(arr[i][j] == 1){
        return false;
      }
    }
return true;
}

void nQueen(int **arr,int n,int row){
    if(row==n){//base case:print the array and return
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << arr[i][j] << " ";
            }
        }cout<<endl;
    return;   
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,n,row,col)){
            arr[row][col] = 1;
            nQueen(arr,n,row+1);
            arr[row][col] = 0;
        }
    }
return;
}

int main(){
    int n;
    cin>>n;

    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    nQueen(arr,n,0);

return 0;
}
```
