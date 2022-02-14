Given a string, compute recursively a new string where all 'x' chars have been removed.
Sample Input 1 :
xaxb
Sample Output 1:
ab

```cpp
#include<bits/stdc++.h>
using namespace std;

void removeX(char input[]) {
    if(strlen(input)==0){
        return;
    }
    char c=input[0];
    if(c=='x'){
        //remove
        for(int i=0;i<strlen(input)-1;i++){
            input[i]=input[i+1];
        }
        input[strlen(input)-1]='\0';
        removeX(input);
    }else{
        removeX(input+1);
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
```
