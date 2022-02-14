```cpp
#include<bits/stdc++.h>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
    static int result=0;
    static int index=0;
	if(size==0){
        return result;
    }
    if(input[0]==x){
        result++;
        output[result-1]=index;
    }
    index++;
    return allIndexes(input+1,size-1,x,output);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    delete [] output;
}
