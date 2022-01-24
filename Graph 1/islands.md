An island is a small piece of land surrounded by water .
A group of islands is said to be connected if we can reach from any given island to any other island in the same group .
Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . 
Can you count the number of connected groups of islands.

```cpp

#include <bits/stdc++.h>
using namespace std;

void connectedComponents(int** edges,bool* visited,int n,int start){
    queue<int> pendingNodes;
    pendingNodes.push(start);

    while(!pendingNodes.empty()){
        int front=pendingNodes.front();
        pendingNodes.pop();

        for(int i=0;i<n;i++){
            if(edges[front][i]==1 && !visited[i]){
                visited[i]=true;
                pendingNodes.push(i);
            }
        }
        visited[front]=true;
    }
}

int islands(int** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            connectedComponents(edges,visited,n,i);
        }
    }
return count;
}

int main() {
    int n,e;
    cin>>n>>e;
    
    int** edges=new int*[n];
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        visited[i]=false;
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
    
    cout<<islands(edges,n);
    
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;    
}

```
