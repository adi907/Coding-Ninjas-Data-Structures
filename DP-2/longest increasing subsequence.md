Given an array with N elements,
you need to find the length of the longest subsequence of a given sequence such that 
all elements of the subsequence are sorted in strictly increasing order.

```cpp
#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n){
	int dp[n];
    //dp[i] stores length of lis ending till here
    // if arr[i+1] is greater the some arr[0.....i] add to that length and store for the max 
	dp[0] = 1;
	for (int i = 1; i < n ; i++){
		int ans = 0;
		for (int  j = i - 1 ; j >= 0 ; j--){
			if (arr[j] < arr[i]){
				ans = max(dp[j], ans);
			}
		}
		dp[i] = ans + 1;
	}
	int res = 0;
	for (int i = 0 ; i < n ; i++){
		res = max(dp[i], res);
    }
return res;
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
```
