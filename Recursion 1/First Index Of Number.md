
```cpp
#include<bits/stdc++.h>
using namespace std;

int firstIndex(int input[], int size, int x) {
    static int result=-1;
	if(size==0){
        return result;
    }
    if(input[size-1]==x){
         result=size-1;
    }
    return firstIndex(input,size-1,x);
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
    
    cout << firstIndex(input, n, x) << endl;

}
```
