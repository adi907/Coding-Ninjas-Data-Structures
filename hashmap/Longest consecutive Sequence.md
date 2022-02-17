You are given with an array of integers that contain numbers in random order.
Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,bool> ourMap;
    unordered_map<int,int> indexMap;
    for(int i=0;i<n;i++){
		ourMap[arr[i]]=true;
        indexMap[arr[i]]=i;
	}

	int maxLength=0;
	int startc=0;
	int length;
	int start;
	for(int i=0;i<n;i++){
		if(ourMap[arr[i]]!=false){
			ourMap[arr[i]]=false;
			length=1;
			start=arr[i];
			//forward check(loop this)
			while(1){
				if(ourMap.count(start+1)>0){
					start++;
					length++;
					ourMap[start]=false;
				}
				else{
					break;
				}
			}

			start=arr[i];
			//backward check(loop this)
			while(1){
				if(ourMap.count(start-1)>0){
					length++;
					ourMap[start]=false;
					start--;
				}
				else{
					break;
				}
			}

			if(length>maxLength){
				maxLength=length;
                startc=start;
			}else if(length==maxLength){
				int a=indexMap[startc];
                int b=indexMap[start];
                if(b<a){
                    startc=start;
                }
			}
		}else{
			continue;
		}
	}

	vector<int> v;
	v.push_back(startc);
	v.push_back(startc+maxLength-1);
return v;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}

```
