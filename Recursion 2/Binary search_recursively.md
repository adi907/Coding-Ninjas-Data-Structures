// input - input array
// size - length of input array
// element - value to be searched

```cpp
#include<bits/stdc++.h>
using namespace std;

int helper(int a[],int s,int e, int i){
    if(s>e){
        return -1;
    }
    int mid= (s+e)/2;
    if(a[mid]==i){
        return mid;
    }
    if(a[mid]>i){ 
        return helper(a,s,mid-1,i);
     }
    if(a[mid]<i){
        return helper(a,mid+1,e,i);
    }
}

int binarySearch(int input[], int size, int element) {
    int start =0;
    int end= size -1;
    int ans =helper(input ,start,end,element);
return ans;
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++){ 
        cin >> input[i];;
    }
    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
```
