Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion. Return the answer.


```cpp
#include <bits/stdc++.h>
using namespace std;

double geometricSum(int k) {
    // Write your code here
    if(k==0){
        return 1;
    }
    return pow(0.5,(float)k)+geometricSum(k-1);
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
```
