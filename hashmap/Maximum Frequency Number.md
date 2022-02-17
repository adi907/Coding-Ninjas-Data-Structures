You are given an array of integers that contain numbers in random order. 
Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

```cpp
#include<bits/stdc++.h>
using namespace std;

int highestFrequency(int arr[], int n) {
    unordered_map<int,int> ourMap;
    for(int i=0;i<n;i++){
        if(ourMap.count(arr[i])==0){
            ourMap[arr[i]]=1;
        }else{
            int key=ourMap[arr[i]]+1;
            ourMap[arr[i]]=key;
        }
    }

    int ans;
    int max_Count=-1;
    for(int i=0;i<n;i++){
        int count=ourMap[arr[i]];
        if(count>max_Count){
            max_Count=count;
            ans=arr[i];
        }
    }
return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
```
