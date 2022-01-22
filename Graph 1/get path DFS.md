Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.


```cpp
#include <iostream>
#include<vector>
using namespace std;

vector<int>* getPath(int** edges,bool* visited,int n,int start, int end){
    visited[start]=true;
    vector<int>* output=new vector<int>();
    if(start==end){
        output->push_back(start);
        return output;
    }

    for(int i=0;i<n;i++){
        if(edges[start][i]==1 && !visited[i]){
            output=getPath(edges,visited,n,i,end);
            if(output!=NULL){
                output->push_back(start);
                return output;
            }
        }
    }
    return NULL;
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
    int start,end;
    cin>>start>>end;
    
    vector<int>* vec=getPath(edges,visited,n,start,end);
    if(vec!=NULL){
        for(int i=0;i<vec->size();i++){
            cout<<(*vec)[i]<<" ";
        }
    }
    else{
        return 0;
    }
    
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;  
}

```
