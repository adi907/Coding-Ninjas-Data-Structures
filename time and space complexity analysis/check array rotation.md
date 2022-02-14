Given an integer array, which is sorted (in increasing order) and
has been rotated by some number k in clockwise direction. Find and return the k.

```cpp

#include<bits/stdc++.h>
using namespace std;

int arrayRotateCheck(int *input, int size){
	int ans=INT_MAX;
    int pos=0;
    for(int i=0;i<size;i++){
        if(input[i]<ans){
            ans=input[i];
            pos=i;
        }
    }
return pos;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++){
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}
```
