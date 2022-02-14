Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

```cpp
#include<bits/stdc++.h>
using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
    static int result=0;
	if(input[0]=='\0'){
        return 0;
    }
    double x;
    x=(int)input[0]-48;
    x=x*pow(10,strlen(input)-1)+stringToNumber(input+1);
    return (int)x;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
```
