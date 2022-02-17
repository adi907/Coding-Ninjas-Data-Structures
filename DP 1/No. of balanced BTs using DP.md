```cpp
#include<bits/stdc++.h>
using namespace std;

int balancedBTs(int h){
    int dp[h+1];
    
    dp[0]=1;
    dp[1]=1;
    
    int mod = (int) (pow(10,9)+ 7);
    for(int i=2 ;i<=h; i++){
        dp[i]=(int)(((long)(dp[i-1])*dp[i-1] )%mod + (2*(long)(dp[i-1])*dp[i-2])%mod) % mod;
    }
        
return dp[h];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
```
