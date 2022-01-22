Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.

```cpp

#include <iostream>
using namespace std;

bool hasPath(int** edges,bool* visited, int n, int start,int end){
    if(start==end){
        return true;
    }
    visited[start]=true;

    for(int i=0;i<n;i++){
        if(i==start){
            continue;
        }
        if(edges[start][i]==1 && !visited[i]){
            if(hasPath(edges,visited,n,i,end)){
                return true;
            }
        }
    }
return false;
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

    for(int i=0;i<e;i++){//input all the e edges
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    int start,end;
    cin>>start>>end;
    
    if(hasPath(edges,visited,n,start,end)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;

return 0;
}

```
