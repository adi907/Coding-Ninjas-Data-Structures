Given a string, find and print all the possible permutations of the input string.


```cpp    
#include <bits/stdc++.h>
using namespace std;

void helper(string input,string output){
    if(input.size()==0){
        cout<<output<<endl;
    }
    
    for(int i=0;i<input.size();i++){
        helper(input.substr(0,i)+input.substr(i+1),output+input[i]);
    } 
}

void printPermutations(string input){
    string ans="";
    helper(input,ans);
}

int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
```
