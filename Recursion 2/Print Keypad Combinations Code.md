```cpp
#include<bits/stdc++.h>
using namespace std;

string keypadArr[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printKeypad(int num,string output=""){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    int a=num%10;
    string code=keypadArr[a];
    for(int i=0;i<code.length();i++){
        printKeypad(num/10,code[i]+output);
    } 
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
```
