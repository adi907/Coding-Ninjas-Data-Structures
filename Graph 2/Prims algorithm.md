Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.

```cpp

#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int* weight,bool* visited,int v){
    int index;
    int key=INT_MAX;
    for(int i=0;i<v;i++){
        if(weight[i]<key && visited[i]!=true){
            key=weight[i];
            index=i;
        }
    };
return index;
}

void prims(int** input,int* weights,int* parent,bool* visited,int n){
    int cycles=0;
    int v;
    while(cycles!=n){
        v=findMinVertex(weights,visited,n);
        visited[v]=true;

        for(int i=0;i<n;i++){
            if(input[v][i]!=0 && input[v][i]<weights[i] && visited[i]!=true){
                weights[i]=input[v][i];
                parent[i]=v;
            }
        }
        cycles++;
    }
    
    for(int i = 1; i < n; i++){
		if(parent[i] < i){
			cout << parent[i] << " " << i << " " << weights[i] << endl;
		}else{
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int v,e;
    cin>>v>>e;

    int** input=new int*[v];
    bool* visited=new bool[v];
    int* weights=new int[v];
    int* parents=new int[v];

    for(int i=0;i<v;i++){
        input[i]=new int[v];
        visited[i]=false;
        weights[i]=INT_MAX;
        parents[i]=-1;
        for(int j=0;j<v;j++){
            input[i][j]=0;
        }
    }
    weights[0]=0;

    for(int i=0;i<v;i++){
        int f,e,w;
        cin>>f>>e>>w;
        input[f][e]=w;
        input[e][f]=w;
    }

    prims(input,weights,parents,visited,v);
 
    delete[] weights;
    delete[] parents;
    delete[] visited;
    for(int i=0;i<v;i++){
            delete[] input[i];
    }
    delete[] input;
return 0;
}

```
