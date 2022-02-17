Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

```cpp
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n){
	unordered_map<int,int> ourMap;

    int length=0;
    int sum=0;
    
	for(int i=0;i<n;i++){
		sum+=arr[i];
        
        if(arr[i]==0 && length==0){
            length=1;
        }
         
        if(sum==0){
            length= i+1;
        }
        if(ourMap.count(sum)>0){
            length=max(length,i-ourMap[sum]);
        }else{
        	ourMap[sum]=i;
        }
	}  
return length;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
```
