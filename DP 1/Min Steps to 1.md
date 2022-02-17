// brute force

```cpp

#include<bits/stdc++.h>
using namespace std;

int countMinStepsToOne(int n){
    if(n==1){
    	return 0;
    }
    int a=INT_MAX;
    int b=INT_MAX;
	int c=INT_MAX;
    
    a= countMinStepsToOne(n-1);
    
    if(n%2==0){
        b=countMinStepsToOne(n/2);
    }
    if(n%3==0){
        c=countMinStepsToOne(n/3);
    }
return  1+min(a,min(b,c));
}

int main(){
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}
```
