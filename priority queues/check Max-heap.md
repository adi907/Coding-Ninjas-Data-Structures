Given an array of integers, check whether it represents max-heap or not.
Return true or false.

```cpp
#include<bits/stdc++.h>
using namespace std;

bool checkMaxHeap(int arr[],int size,int parentIndex){
    int leftChildIndex=(2*parentIndex)+1;
    int rightChildIndex=(2*parentIndex)+2;
    if(size<leftChildIndex){
        return true;
    }
    
    if(arr[parentIndex]<arr[leftChildIndex]){
        return false;
    }
    
    if(rightChildIndex<size && arr[parentIndex]<arr[rightChildIndex]){
    		return false;
    }
    bool ans=(checkMaxHeap(arr,size,leftChildIndex) && checkMaxHeap(arr,size,rightChildIndex));
        
return ans;
}

bool isMaxHeap(int arr[], int n) {
    return checkMaxHeap(arr,n,0);
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}
```
