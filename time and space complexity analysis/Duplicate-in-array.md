```cpp

#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int *arr, int n){
    //Write your code here
    int sum=0;
    int sum2=0;
    for(int i=0;i<n-1;i++){
		sum+=i;
    }
    for(int i=0;i<n;i++){
		sum2+=arr[i];
    }
    return sum2-sum;
}

int main(){
	int t;
	cin >> t;
	
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}
```
