Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.
Sample Input 1:
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2

```cpp
#include<bits/stdc++.h>
using namespace std;

void rotate(int *input, int d, int n){
    //Write your code here
     int temparr[100000];
  for(int i=0;i<d;i++){
    temparr[i]=input[i];
  }

  for(int i=0;i<n-d;i++){
    input[i]=input[i+d];
  }
  for(int i=n-d,j=0;i<n,j<d;i++,j++){
    input[i]=temparr[j];
  }
}

int main(){
	int t;
	cin >> t;
	
	while (t--){
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i){
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
```
