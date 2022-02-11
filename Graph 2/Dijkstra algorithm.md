Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.

```cpp

#include<bits/stdc++.h>
using namespace std;

int minVertex(int* weights,bool* visited,int n){
    int index;
    int key=INT_MAX;
    for(int i=0;i<n;i++){
        if(weights[i]<key && !visited[i]){
            key=weights[i];
            index=i;
        }
    }
return index;
}

void dijkstra(int** input,int* weights,bool* visited,int n){
    weights[0]=0;
    int v;
    for(int i=0;i<n;i++){
        v=minVertex(weights,visited,n);
        visited[v]=true;
        for(int j=0;j<n;j++){
            if(input[v][j]!=0 && !visited[j] && ((weights[v]+input[v][j])<weights[j])){
                
                weights[j]=weights[v]+input[v][j];
            }
        }
    }

    //print
    for(int i=0;i<n;i++){
        cout<<i<<" "<<weights[i]<<endl;
    }
}

int main() {
    int v,e;
    cin>>v>>e;

    int** input=new int*[v];
    int* weights=new int[v];
    bool* visited=new bool[v];

    for(int i=0;i<v;i++){
        input[i]=new int[v];
        weights[i]=INT_MAX;
        visited[i]=false;
        for(int j=0;j<v;j++){
            input[i][j]=0;
        }
    }

    int s,f,w;
    for(int i=0;i<e;i++){
        cin>>s>>f>>w;
        input[s][f]=w;
        input[f][s]=w;
    }

    dijkstra(input,weights,visited,v);

    delete[] visited;
    delete[] weights;
    for(int i=0;i<v;i++){
        delete[] input[i];
    }
    delete[] input;
return 0;
}

```
