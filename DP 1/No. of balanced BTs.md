Given an integer h, find the possible number of balanced binary trees of height h. 
You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.

```cpp
#include<bits/stdc++.h>
using namespace std;

int balancedBTs(int h){
	if(h<=1) return 1;
    
    int x= balancedBTs(h-1);
    int y =balancedBTs(h-2);
    int mod = (int)(pow(10,9) + 7);
    
    int temp1=(int) (((long)(x)*x)%mod);
     int temp2=(int) ((2*(long)(x)*y)%mod);

    int ans = (temp1 +temp2 ) %mod;
    
    return ans;   
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
```
