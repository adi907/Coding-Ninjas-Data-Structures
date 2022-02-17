A thief robbing a store and can carry a maximal weight of W into his knapsack.
There are N items and ith item weigh wi and is value vi. What is the maximum value V, that thief can take ?

```cpp
#include<bits/stdc++.h>
using namespace std;

int knapsack(int weights[],int values[],int num,int W){
    if(num==0||W==0){
        return 0;
    }
    if(weights[num-1]>W){
        return knapsack(weights,values,num-1,W);
    }
    return max(knapsack(weights,values,num-1,W-weights[num-1])+values[num-1], knapsack(weights,values,num-1,W));
}

int main(){
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}
```
