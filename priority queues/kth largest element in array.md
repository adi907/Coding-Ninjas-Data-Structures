Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Try to do this question in less than O(nlogn) time

```cpp
#include<bits/stdc++.h>
using namepsace std;

int kthLargest(int* arr, int n, int k) {
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    
    int count=0;
    int ans;
    while(count!=k && !pq.empty()){
        ans=pq.top();
        count++;
        pq.pop();
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}
```
