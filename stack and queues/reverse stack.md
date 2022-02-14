```cpp

#include<bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    int arr[1000];
    int val;
    int i=0;
    while(!input.empty()) {
        val=input.top();
        input.pop();
        arr[i]=val;
        i++;
    }  
    for(int j=0;j<i;j++){
        input.push(arr[j]);
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}

```
