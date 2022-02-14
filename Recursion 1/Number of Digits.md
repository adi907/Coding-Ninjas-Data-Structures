```cpp
#include<bits/stdc++.h>
using namespace std;

int count(int n){
    int smallAns;
    if(n == 0){
        return 0;
    }
    smallAns = 1+count(n / 10);
    return smallAns;
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}
```
