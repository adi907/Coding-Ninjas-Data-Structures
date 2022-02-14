  Assume that the value of a = 1, b = 2, c = 3, ... , z = 26.
  You are given a numeric string S. 
  Write a program to return the list of all possible codes that can be generated from the given string.
  
  1123
Sample Output:
aabc
kbc
alc
aaw
kw

```cpp
#include<bits/stdc++.h>
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

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
```
