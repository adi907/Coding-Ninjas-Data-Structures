```cpp
#include<bits/stdc++.h>
using namespace std;

bool checkNumber(int input[], int size, int x) {
	if(size==0){
        return 0;
    }
    if(input[size-1]==x){
        return 1;
    }
    return checkNumber(input,size-1,x);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
```
