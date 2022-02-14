```cpp
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;

    int a[n1];
    int b[n2];//temp arrays
    for(int i=0;i<n1;i++){
        a[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++){
        b[j]=arr[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=low;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }while(j<n2){
        arr[k]=b[j];
        k++;j++;
    }
}

void mergesort_help(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort_help(arr,low,mid);
        mergesort_help(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

void mergeSort(int input[], int size){
	// Write your code here
    mergesort_help(input,0,size-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

```
