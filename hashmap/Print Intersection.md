Given two random integer arrays, print their intersection. 
That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.

```cpp
#include<bits/stdc++.h>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
 	unordered_map<int,int> ourMap;
    for(int i=0;i<n;i++){
        ourMap[arr1[i]]++;
    }

    for(int i=0;i<m;i++){
        if(ourMap[arr2[i]]>0){
            ourMap[arr2[i]]--;
            cout<<arr2[i]<<endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
```
