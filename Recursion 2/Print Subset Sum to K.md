Given an array A and an integer K, print all subsets of A which sum to K.

```cpp
#include <bits/stdc++.h>
using namespace std;

void helper(int input[],int size,int key,int ans[],int m){
    int sum;
    if(size==0){
        sum=0;
        for(int i=0;i<m;i++){
            sum+=ans[i];
        }
        if(sum==key){
            for(int i=0;i<m;i++){
                cout<<ans[i]<<" ";
            }cout<<endl;
        }
        return;
    }

    helper(input+1,size-1,key,ans,m);
    ans[m]=input[0];
    helper(input+1,size-1,key,ans,m+1);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int ans[100];
    helper(input,size,k,ans,0);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
```
