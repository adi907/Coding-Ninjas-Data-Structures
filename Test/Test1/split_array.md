```cpp
#include<bits/stdc++.h>
using namespace std;

bool split_help(int input[],int n,int start,int sum1,int sum2){
    if(start==n){
        return(sum1==sum2);
    }
    if(input[start]%5==0){
        sum1+=input[start];
        return split_help(input, n, start+1,sum1,sum2);
    }else if(input[start]%3==0){
        sum2+=input[start];
        return split_help(input,n,start+1,sum1,sum2);
    }else{
        return split_help(input,n,start+1,sum1+input[start],sum2)|| split_help(input,n,start+1,sum1,sum2+input[start]);
    }
}

bool splitArray(int *input, int size) {
    return split_help(input,size,0,0,0);
}

int main() {
	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
return 0;
}
```
