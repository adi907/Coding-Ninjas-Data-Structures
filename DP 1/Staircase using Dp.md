A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).

```cpp
#include<bits/stdc++.h>
using namespace std;

long staircase(int n){
    long a[n+1];
     
    a[0]=1;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    
    for(int i=4 ;i<=n ;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    
return a[n];
}

int main(){
	int n;
	cin >> n;
	cout << staircase(n);
}
```
