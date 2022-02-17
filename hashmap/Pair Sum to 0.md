Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. 
You can print pairs in any order, just be careful about the order of elements in a pair.

```cpp
#include<bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n) {
    unordered_map<int,int> ourMap;
    int count=0;
    for(int i=0;i<n;i++){
        if(ourMap.count(-(arr[i]))>0){
            int freq=ourMap[-(arr[i])];
            count+=freq;
        }
        ourMap[arr[i]]++;
    }
return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
```
