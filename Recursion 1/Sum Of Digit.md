Write a recursive function that returns the sum of the digits of a given integer.

```cpp
#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    // Write your code here
    if(n==0){
        return 0;
    }
    return (n%10)+ sumOfDigits(n/10);
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
```
