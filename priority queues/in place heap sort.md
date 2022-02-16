Given an integer array of size n. Sort this array (in decreasing order) using heap sort

```cpp
#include<bits/stdc++.h>
using namespace std;

void heapSort(int arr[], int n) {
    // Write your code
    for(int i=1;i<n;i++){
        //up heapify-ing the array 1 by 1 to achieve H.O.P from start
        int childIndex=i;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(arr[childIndex]<arr[parentIndex]){
                int temp=arr[parentIndex];
                arr[parentIndex]=arr[childIndex];
                arr[childIndex]=temp;
            }
            childIndex=parentIndex;
        }
    }
    int size=n;
    while(size>1){
        //swapping first with last & reduce size variable
        int temp=arr[0];
        arr[0]=arr[size-1];
        arr[size-1]=temp;
        size--;

        //down heapify to reinstate H.O.P
        int parentIndex=0;
        int leftChildIndex=1;
        int rightChildIndex=2;
        int minIndex=parentIndex;

        while(leftChildIndex<size){
            if(arr[minIndex]>arr[leftChildIndex]){
                minIndex=leftChildIndex;
            }
            if(rightChildIndex<size && arr[minIndex]>arr[rightChildIndex]){
                minIndex=rightChildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }
            int temp2=arr[parentIndex];
            arr[parentIndex]=arr[minIndex];
            arr[minIndex]=temp2;

            parentIndex=minIndex;
            leftChildIndex=(2*parentIndex)+1;
            rightChildIndex=(2*parentIndex)+2;
        }
    }

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
```
