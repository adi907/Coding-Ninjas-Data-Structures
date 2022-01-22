Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

```cpp

#include <bits/stdc++.h>
using namespace std;

vector<int>* connectedComponents(int** edges,bool* visited,int n,int start){
    vector<int>* answer=new vector<int>();

    queue<int> pendingNodes;
    pendingNodes.push(start);

    while(!pendingNodes.empty()){
        int front=pendingNodes.front();
        pendingNodes.pop();
        answer->push_back(front);

        for(int i=0;i<n;i++){
            if(edges[front][i]==1 && !visited[i]){
                visited[i]=true;
                pendingNodes.push(i);
            }
        }
        visited[front]=true;
    }
    return answer;
}

void allComponents(int** edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int>* output=connectedComponents(edges,visited,n,i);
            sort(output->begin(),output->end());
            for(int i=0;i<output->size();i++){
                cout<<(*output)[i]<<" ";
            }cout<<endl;
        }
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
    
    allComponents(edges,n);
    
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}

```
