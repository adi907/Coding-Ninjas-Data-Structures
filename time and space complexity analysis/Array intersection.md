Given two random integer arrays, print their intersection. That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.

Input format :
Line 1 : Integer N, Array 1 Size
Line 2 : Array 1 elements (separated by space)
Line 3 : Integer M, Array 2 Size
Line 4 : Array 2 elements (separated by space)

Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2 
4 
3
```cpp
#include<bits/stdc++.h>
using namespace std;

void intersection(int *arr1, int *arr2, int n, int m) {
  vector<int> vec1;
  vector<int> vec2;
  for(int i=0;i<n;i++) {
    vec1.push_back(arr1[i]);
  }
  for(int i=0;i<m;i++) {
    vec2.push_back(arr2[i]);
  }
  sort(vec1.begin(),vec1.end());
  sort(vec2.begin(),vec2.end());    

  int k=0,x=0;
  while(k<n && x<m){
    if(vec1[k]<vec2[x]){
      k++;
    }
    else if(vec1[k]>vec2[x]){
      x++;
    }
    else{
      cout<<vec1[k]<<" ";
      k++;
      x++;
    }
  }
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

return 0;
}
```
