Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= Length of String S <= 10^3
Sample Input :
aabccba
Sample Output :
abcba

```cpp
#include<bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	if(strlen(input)==0){
        return;
    }
    if(input[0]==input[1]){
        //move all back by 1
        for(int i=1;i<strlen(input);i++){
            input[i]=input[i+1];
        }
    removeConsecutiveDuplicates(input);   
    }else{
		removeConsecutiveDuplicates(input+1);
    }
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
```
