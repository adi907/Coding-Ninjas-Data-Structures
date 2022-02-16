You are given a stream of n integers. For every ith integer, 
add it to the running list of integers and print the resulting median (of the list till now).
Print the only integer part of median.

Input Format :
Line 1 : An integer N denoting the number of integers in the stream
Line 2 : N integers which are separated by spaces
Output Format :
After each new integer is added to the list print the updated median on a new line
Input Constraints
1 <= n <= 10^5
1 <= Ai <= 10^5
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6
4
2
2
3
4

Sample Output explanation :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

```cpp
#include<bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n){
    if(n==0){
        return;
    }
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;

    max.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        if(arr[i]<max.top()){
            max.push(arr[i]);
            if(max.size()-min.size()>1){
                min.push(max.top());
                max.pop();
            }
        }else{
            min.push(arr[i]);
            if(min.size()-max.size()>1){
                max.push(min.top());
                min.pop();
            }
        }

        int size1=max.size();
        int size2=min.size();
        if((size1+size2)%2==0){
            cout<<(min.top()+max.top())/2<<" ";
        }else{
            if(size1>size2){
                cout<<max.top()<<" ";
            }else{
                cout<<min.top()<<" ";
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
```
