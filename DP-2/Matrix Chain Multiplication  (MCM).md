Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices 
i.e. determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.

```cpp
#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &dp,int *arr,int s,int e){
    if(e-s==1){
        return 0;
    }
    if(dp[s][e]){
        return dp[s][e];
    }
    int ans=INT_MAX;
    for(int k=s+1;k<e;k++){
        int temp=helper(dp,arr,s,k)+helper(dp,arr,k,e)+arr[s]*arr[k]*arr[e];
        ans=min(ans,temp);
    }
    dp[s][e]=ans;
    return ans;
}

int matrixChainMultiplication(int* arr, int n){
    vector <vector<int>> dp(n+1,vector<int>(n+1,0));
    int ans=helper(dp,arr,0,n);
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
```
