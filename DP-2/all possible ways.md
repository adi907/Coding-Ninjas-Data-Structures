Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2 
Hence, answer is 1.

```cpp
#include<bits/stdc++.h>
using namepsace std;

int helper(int x,int n,int curNo,int *dp){
    if(x<0){
        return 0;
    }
    if(x==0){
        return 1;
    }

    int ans=0;

    for(int i=curNo;pow(i,n)<=x;i++){
            ans+=helper(x-pow(i,n),n,i+1,dp);
    }
    dp[x]=ans;
    return ans;    
}

int getAllWays(int x, int n) {
    int dp[100000];
    for(int i=0;i<100000;i++){
        dp[i]=-1;
    }
    return helper(x,n,1,dp);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}
```
