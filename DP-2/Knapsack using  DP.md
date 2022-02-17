```cpp
#include<bits/stdc++.h>
using namespace std;

int knapsack(int* wt, int* values, int n, int W){   
    int dp[n+1][W+1];
	for(int i =0 ; i<=n ;i++){ 
    	for(int j=0 ;j<=W ;j++){
 			if( i==0 || j== 0){
 				dp[i][j]=0;
            }else{
            	if(wt[i-1]>j){
 		  	         dp[i][j] = dp[i-1][j];
                }else{
					dp[i][j]= max( values[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]); 
 			    }
			}
        }
	}
return dp[n][W];
}

int main(){
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}
```
