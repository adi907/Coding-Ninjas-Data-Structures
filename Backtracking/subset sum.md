```cpp
#include<bits/stdc++.h>
using namespace std;

int subsetSum(int arr[], int size, int index,int sum, int count){
    if (index==size){
        if (sum == 0) {
            count++;
        }
        return count;
    }
    return subsetSum(arr,size,index+1,sum-arr[index],count)+subsetSum(arr,size,index+1,sum,count);
}

int main(){
    int t;
    cin>>t;

    while(t--){
    	int n,key;
    	cin>>n>>key;
	
    	int* arr=new int[n];
    	for(int i=0;i<n;i++){
    	    cin>>arr[i];
    	}
      
    	cout<<subsetSum(arr,n,0,key,0)<<endl;
    	
    	delete[] arr;
    }
    
return 0;
}
```
