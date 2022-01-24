Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. 
Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

```cpp

#include<bits/stdc++.h>
using namespace std;

int pieceSize(vector<vector<int>> &cake,bool** visited,int n,int i,int j){
    if(i<0 || j<0|| i>=n ||j>=n|| visited[i][j]||!cake[i][j]){
        return 0;
    }
    visited[i][j]=true;
    int count=1;
    count+=pieceSize(cake,visited,n,i-1,j)+pieceSize(cake,visited,n,i+1,j)+pieceSize(cake,visited,n,i,j-1)+pieceSize(cake,visited,n,i,j+1);

return (count);
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j]=false;
        }
    }

    int ans=0;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && cake[i][j]==1){
                count=pieceSize(cake,visited,n,i,j);
                if(count>ans){
                    ans=count;
                }
            }
        }
    }
return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}

```
