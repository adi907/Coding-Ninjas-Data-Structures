Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

```cpp
include<bits/stdc++.h>
using namespace std;

void replacePi(char input[]) {
	// Write your code here
	if(strlen(input)==0||strlen(input)==1){
        return;
    }
    if(input[0]=='p' && input[1]=='i'){
        //shift all by 2 ahead
        for(int i=strlen(input)-1;i>=0;i--){
            input[i+4]=input[i+2];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
        replacePi(input+4);
    }else{
        replacePi(input+1);
    }
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
```
