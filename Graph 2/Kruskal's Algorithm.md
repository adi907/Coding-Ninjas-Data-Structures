Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.

```cpp

#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int start;
        int end;
        int weight;

        edge(){}
        edge(int start,int dest,int wt){
            this->start=start;
            this->end=dest;
            this->weight=wt;
        }
};

bool compareEdge(edge e1,edge e2){
    return (e1.weight<e2.weight);
}

bool isSafe(edge curr,int* parent){
    int pl=curr.start;
    int pr=curr.end;

    while(pl!=parent[pl]){
        pl=parent[pl];
    }
    while(pr!=parent[pr]){
        pr=parent[pr];
    }

    if(pl==pr){
        return false;//if both parents same=not safe(will make cycle)
    }else{
        parent[pl]=parent[pr];//update parent_array by putting other now connected parent at their position {not children}
        return true;
    }
}

void Kruskal(edge* input,int v,int e){
    edge* output=new edge[v-1];    
    int *parent=new int[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }

    int count=0;
    int i=0;
    edge curr;
    while(count!=v-1){
        curr=input[i];

        if(isSafe(curr,parent)){
            output[count]=curr;
            count++;
        }
        i++;
    }

    edge present;
    for(int i=0;i<v-1;i++){//sort the output before printing(smaller edge vertex first)
        present=output[i];
        int temp;
        if(present.start>present.end){
            temp=present.start;
            present.start=present.end;
            present.end=temp;
        }
        output[i]=present;
    }

    for(int i=0;i<v-1;i++){//print
        cout<<output[i].start<<" "<<output[i].end<<" "<<output[i].weight<<endl;
    }

delete[] parent;
delete[] output;
}


int main(){
    int v,e;
    cin>>v>>e;

    edge* input=new edge[e];

    int s,f,w;
    for(int i=0;i<e;i++){
        cin>>s>>f>>w;
        input[i]=edge(s,f,w);
    }

    sort(input,input+e,compareEdge);

    Kruskal(input,v,e);

delete[] input;
return 0;
}
```
