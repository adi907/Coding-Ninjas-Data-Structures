Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Sample Input:
abb
Sample Output:
true

```cpp
#include<bits/stdc++.h>
using namespace std;

bool help_checkAB(char input[],int start){
    if(input[start]=='\0'){
        return true;
    }
    if(input[start]!='a'){
        return false;
    }
    if(input[start+1]!='\0' && input[start+2]!='\0'){
        if(input[start+1]=='b' && input[start+2]=='b'){
            return help_checkAB(input,start+3);
        }
    }
    	return help_checkAB(input,start+1);
}


bool checkAB(char input[]) {
	// Write your code here
	bool ans=help_checkAB(input,0);
    return ans;
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
```
