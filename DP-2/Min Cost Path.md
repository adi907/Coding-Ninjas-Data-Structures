Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.

```cpp

#include<bits/stdc++.h>
using namespace std;

int mincostpath(int **input, int m, int n,int sr,int sc){
    if(sr==m-1 && sc==n-1){
        return input[sr][sc];
    }
    int x,y,z;
    x=y=z=INT_MAX;
    
    if(sr<m-1){
    	x= mincostpath(input,m,n,sr+1,sc); //down
    }
    if(sc<n-1){
    	y=mincostpath(input,m,n,sr,sc+1);//right
    }
    if(sr<m-1 && sc<n-1){
    	z=mincostpath(input,m,n,sr+1,sc+1); //diagonal
    }    
return input[sr][sc]+ min(x,min(y,z));
}

int minCostPath(int **input, int m, int n){
return mincostpath(input,m,n,0,0);    
}

int main(){
	int **arr, n, m;
   
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++){
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}
```
