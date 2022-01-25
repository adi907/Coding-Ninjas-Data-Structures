Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.

```cpp

#include<bits/stdc++.h>
using namespace std;

bool hasCycle(vector<vector<char>> &board, int n, int m, int i, int j,bool** &visited, char ch) {
	int up=0, down=0, left=0, right=0;
    if(i-1>=0){
        up = (int)visited[i-1][j];
    }
    if(i+1<n){
        down = (int)visited[i+1][j];
    }
    if(j-1>=0){
        left = (int)board[i][j-1];
    }
    if(j+1<m){
        right = (int)board[i][j+1];
    }

    if((up+down+left+right) == 2){//base case for chain formation
        return true;
    }
    
    bool found = false;
    // check up 
    if(i-1>=0 && board[i-1][j]==ch && !visited[i-1][j]){
        visited[i-1][j] = true;
        if(hasCycle(board,n,m,i-1,j,visited,ch)){
            found = true;
        }else{
            board[i-1][j] = false;
        }
    }
    // check left
    if(j-1>=0 && board[i][j-1]==ch && !visited[i][j-1]){
        visited[i][j-1] = true;
        if(hasCycle(board,n,m,i,j-1,visited,ch)){
            found = true;
        }else{
            board[i][j-1] = false;
        }
    }
    // check right
    if(i+1<n && board[i+1][j]==ch && !visited[i+1][j]){
        visited[i+1][j] = true;
        if(hasCycle(board,n,m,i+1,j,visited,ch)){
            found = true; 
        }else{
            board[i+1][j] = false;
        }
    }
    // check down
    if(j+1 <m && board[i][j+1]==ch && !visited[i][j+1]){
        visited[i][j+1] = true;
        if(hasCycle(board, n, m, i, j+1, visited, ch)){
            found = true;
        }else{
            board[i][j+1] = false;
        }
    }
    return found;
}

bool hasCycle(vector<vector<char> > &board, int n, int m) {
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(hasCycle(board,n,m,i,j, visited,board[i][j])){
                return true;
            }
        }
    }
return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}

```
