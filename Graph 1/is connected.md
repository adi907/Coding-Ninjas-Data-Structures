Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.

```cpp

#include <bits/stdc++.h>
using namespace std;

void dfs(int** edges,bool* visited,int n,int start){
    visited[start]=true;
    for(int i=0;i<n;i++){
        if(edges[start][i]==1 && !visited[i]){
            dfs(edges,visited,n,i);
        }
    }      
}

bool isConnected(int** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    dfs(edges,visited,n,0);
    
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            return false;
        }
    }
return true; 
}

int main() {
    int n,e;
    cin>>n>>e;
    
    int** edges=new int*[n];
    
    for(int i=0;i<n;i++){
		edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    if(isConnected(edges,n)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    
return 0;
}

```
