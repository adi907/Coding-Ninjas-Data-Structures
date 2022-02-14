Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line.
You can print triplets in any order, just be careful about the order of elements in a triple

```cpp
#include <bits/stdc++.h> 
using namespace std;

int tripletSum(int *arr, int n, int num){
    sort(arr,arr+n);
    int result = 0;
    for(int i=0;i<n-2;i++){
        int low = i+1;
    	int high = n-1;
    	while(low<high){
   			if(arr[low]+arr[high] > num - arr[i]){
    			high--;
       		}
    		else if(arr[low]+arr[high] < num - arr[i]){
        		low++;
    		}else{
                int dupcount = 1;
       			int dupidx= low+1;
       			while(dupidx<high && arr[dupidx]==arr[low]){
       			    dupidx++;
       			    dupcount++;
       			}
       			result+=dupcount;
       			high--;
        	}     
    	}
    }
return result;
}

int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}
```
