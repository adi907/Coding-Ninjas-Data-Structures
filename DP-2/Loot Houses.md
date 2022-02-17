A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

```cpp

#include<bits/stdc++.h>
using namespace std;

int getmaxmoney(int arr[], int n, int*  dp){
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    
    for(int i=2 ;i< n ;i++){
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
	}
return dp[n-1];
}

int maxMoneyLooted(int arr[], int n){
	int  dp[n];
return getmaxmoney(arr,n, dp);
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}
```
