Check if a given String S is palindrome or not (using recursion). Return true or false.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(char input[]) {
    static int back=1;
    int len=0;
	while(input[len]!='\0'){
        len++;
    }
    if(back>=len){
        return true;
    }

    if(input[0]!=input[len-back]){
        return false;
    }
    back++;
    checkPalindrome(input+1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
```
