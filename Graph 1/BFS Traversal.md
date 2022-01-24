Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well

```cpp

#include<bits/stdc++.h>
using namespace std;

void print(int** edges,int n,int sv,bool* visited){
    queue<int> pendingVertices;

    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty()){
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0;i<n;i++){
            if(i==currentVertex){
                continue;
            }
            if(edges[currentVertex][i]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
}

void bfs(int** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            print(edges,n,i,visited);
        }
    }
delete[] visited;
}

int main(){


    int n,e;
    cin>>n;
    cin>>e;
    

    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){//input all the e edges
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    bfs(edges,n);

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;

return 0;
}

```
