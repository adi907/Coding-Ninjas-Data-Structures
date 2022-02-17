```cpp
#include<bits/stdc++.h>
using namespace std;

bool check_helper(char large[],char small[],int m,int n){
    if(n==0){
        return true;
    }
    if(m==0){
        return false;
    }
    if(large[0]==small[0]){
        check_helper(large+1,small+1,m-1,n-1);
    }else{
        check_helper(large+1,small,m-1,n);
    }
}

bool checksequenece(char large[] , char*small) {
	int m=strlen(large);
    int n=strlen(small);
    bool result=check_helper(large,small,m,n);
return result;  
}

int main(){
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x){
		cout<<"true";
	}else{
		cout<<"false";
    }
}
```
