```cpp

#include <bits/stdc++.h>
using namespace std;

void swap(int arr[],int x,int y){
    int temp=arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}

int partition(int arr[],int l,int r){
    int i=l-1;
    int pivot=arr[r];
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }//position all elements smaller than pivot before it
    swap(arr,i+1,r);//all elements before pivot are smaller and all after are greater
    return i+1;
}

void quickSort(int arr[],int l,int r){
	if(l<r){
        int pi=partition(arr,l,r);

        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

void quickSort(int input[], int size) {
	quickSort(input, 0, size - 1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}

```
