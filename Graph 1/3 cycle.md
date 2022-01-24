Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , 
then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.

```cpp

#include <bits/stdc++.h>
using namespace std;

int cycle(int** edges,int n){
    int count=0; 
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]){
                for(int k=0;k<n;k++){
                    if(edges[j][k] && edges[i][k]){
                        count++;
                    }
                }
            }
        }
    }
    return (count/6);
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
    
    cout<<cycle(edges,n);
    
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
}

```
