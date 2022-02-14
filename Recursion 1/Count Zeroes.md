Given an integer n, count and return the number of zeros that are present in the given integer using recursion.

```cpp
#include <bits/stdc++.h>
using namespace std;

int countZeros(int n) {
    // Write your code here
    static int ans = 0;
    if(n==0){
        return 1;
    }
    if(n%10==0){
        ans++;
    }
    countZeros(n/10);
return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
```
