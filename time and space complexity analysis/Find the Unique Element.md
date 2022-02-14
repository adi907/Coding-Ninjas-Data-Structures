Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
You need to find and return that number which is unique in the array.

```cpp
#include<bits/stdc++.h>
using namespace std;

int findUnique(int *arr, int n) {
    int result=0;
	for(int i=0; i<n; i++){
        result=result^arr[i];
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}
```
