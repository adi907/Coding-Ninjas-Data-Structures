Given a NxM matrix containing Uppercase English Alphabets only.
Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.

```cpp

#include<bits/stdc++.h>

bool helper(string s,int i ,int j,int n,int m,bool visited[][1000],vector<vector<char>> &board){ 
    bool ans;
    if(i<0||j<0||i>=n||j>=m||visited[i][j]==1){
        return false;
    }

    if(board[i][j]==s[0] && s.size()==1){
        return true;
    }
    if (board[i][j]!=s[0]){
        return false;
    }else{
        visited[i][j]=1;
        ans=helper(s.substr(1),i-1,j-1,n,m,visited,board)||helper(s.substr(1),i-1,j,n,m,visited,board)||helper(s.substr(1),i-1,j+1,n,m,visited,board)||helper(s.substr(1),i,j-1,n,m,visited,board)||helper(s.substr(1),i,j+1,n,m,visited,board)||helper(s.substr(1),i+1,j-1,n,m,visited,board)||helper(s.substr(1),i+1,j,n,m,visited,board)||helper(s.substr(1),i+1,j+1,n,m,visited,board);
    }
    visited[i][j]=0;
return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m){ 
    bool visited[n][1000]={0};
    bool ans;
    string s="CODINGNINJA";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==s[0]){
                if(helper(s,i,j,n,m,visited,board)){
                   return true;
                }
            }  
        }
    }
return false;
}

```
