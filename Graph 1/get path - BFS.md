Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.

```cpp

#include <bits/stdc++.h>
using namespace std;

void getPath(int** edges,bool* visited,int n,int start, int end){
    queue<int> pendingNodes;
    unordered_map<int,int> ourMap;
    pendingNodes.push(start);

    while(!pendingNodes.empty()){
        int front=pendingNodes.front();
        if(front==end){
            int key=front;
            while(key!=start){
                cout<<key<<" ";
                key=ourMap[key];
            }
            cout<<key;
            break;
        }

        for(int i=0;i<n;i++){
            if(!visited[i] && edges[front][i]==1){
                visited[i]=true;
                pendingNodes.push(i);
                ourMap[i]=front;
            }
        }
        visited[front]=true;
        pendingNodes.pop();
    }

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

    getPath(edges,visited,n,start,end);
    
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}

```
