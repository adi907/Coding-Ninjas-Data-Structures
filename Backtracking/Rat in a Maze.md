```cpp
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr,int** solArr,int x,int y,int n){
    if(x<n && y<n && x>=0 && y>=0 && arr[x][y]==1 && solArr[x][y]==0){
        return true;
    }
return false;
}

void ratMaze(int* arr[],int x,int y,int n,int* solArr[]){
	if(x==n-1 && y==n-1){
		if(isSafe(arr,solArr,x,y,n)){
			solArr[x][y] = 1;
			for(int i=0;i<n;i++){
            	for(int j=0;j<n;j++){
                    cout<<solArr[i][j]<<" ";
                }
            }cout<<endl;
            solArr[x][y]=0;
		}
	return;
	}

    if(isSafe(arr,solArr,x,y,n)){
        solArr[x][y]=1;

        ratMaze(arr,x+1,y,n,solArr);
        ratMaze(arr,x-1,y,n,solArr);
        ratMaze(arr,x,y+1,n,solArr);
        ratMaze(arr,x,y-1,n,solArr);
            
        solArr[x][y]=0;
    }
return;
}

int main(){
    int n;
    cin>>n;

    int** arr=new int*[n];
    int** solArr=new int*[n];
    
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        solArr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            solArr[i][j]=0;
        }
    }

    ratMaze(arr,0,0,n,solArr);
    
return 0;
}
```
