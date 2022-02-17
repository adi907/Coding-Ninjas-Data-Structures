You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Take difference as absolute.

```cpp
#include <bits/stdc++.h>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int,int> ourMap;
	for(int i=0;i<n;i++){
		ourMap[arr[i]]++;
	}

	int count=0;
	for(int i=0;i<n;i++){
		int key1=arr[i]-k;
		int key2=arr[i]+k;

		if(key1!=key2){
			if(ourMap.count(key1)>0){
				count+=(ourMap[key1])*(ourMap[arr[i]]);
			}
			if(ourMap.count(key2)>0){
				count+=(ourMap[key2])*(ourMap[arr[i]]);
			}
		}else{
			count+=((ourMap[key1])*(ourMap[key1]-1))/2;
		}

		ourMap.erase(arr[i]);
	}
return count;
    
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
```
