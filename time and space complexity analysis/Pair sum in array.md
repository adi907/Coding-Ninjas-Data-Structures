Given a random integer array A and a number x. Find and print the pair of elements in the array which sum to x.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, 5) print "5 6". There is no constraint that out of 5 pairs which have to be printed in 1st line.
You can print pairs in any order, just be careful about the order of elements in a pair.

```cpp
#include <bits/stdc++.h> 
using namespace std;

int count_same(vector<int>vec,int x){//x is the position
  int ans=1;
  while(vec[x]==vec[x+1]){
    ans++;
    x++;
  }
return ans;
}

int count_same_down(vector<int>vec,int x){//x is the position
  int ans=1;
  while(vec[x]==vec[x-1]){
    ans++;
    x--;
  }
return ans;
}

int pairSum(int *arr, int n, int num){
	//Write your code here
    int a,b,x;
	//Write your code here
  vector<int>vec;
  int result=0;
  for(int i=0;i<n;i++){
    vec.push_back(arr[i]);
  }  
  sort(vec.begin(), vec.end());
  int low=0,high=n-1;

  while(high>low){
    if(vec[low]+vec[high]>num){
      high--;
    }
    else if(vec[low]+vec[high]<num){
      low++;
    }else{
      if(vec[low]==vec[high]){
        
        x=count_same(vec,low);
        result+=(x*(x-1))/2;
        low+=x;
      }else{
        a=count_same(vec,low);
        b=count_same_down(vec,high);
        result+=a*b;
        low+=a;
        high-=b;
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
	pairSum(input,size,x);
		
	return 0;
}
```
