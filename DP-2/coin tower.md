Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . In one move player can remove 1 or X or Y coins from the tower . The person to make the last move wins the Game . Can you find out who wins the game ?
Input Format :
Contains three value N,X,Y as mentioned in the problem statement
Output Format :
A string containing the name of the winner like “Whis” or “Beerus” (without quotes)

```cpp
#include<bits/stdc++.h>
using namepsace std;

string findWinner(int n, int x, int y){
	 // To store results 
    int dp[n + 1]; 
  
    // Initial values 
    dp[0] = false; 
    dp[1] = true; 
  
    // Computing other values. 
    for (int i = 2; i <= n; i++){ 
        // If A losses any of i-1 or i-x or i-y game then he will definitely win game i 
        if (i - 1 >= 0 and !dp[i - 1]){
            dp[i] = true; 
        }else if (i - x >= 0 and !dp[i - x]){
            dp[i] = true; 
        }else if (i - y >= 0 and !dp[i - y]){
            dp[i] = true; 
        }else{//Else A loses game
            dp[i] = false; 
        }
    } 
    // If dp[n] is true then A will game otherwise  he losses 
    string s="Whis";
    if (dp[n]){
        s="Beerus";
        return s;
    }else{
        return s;
    }
}

int main(){
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}
```
