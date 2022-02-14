Given a string,
compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

```cpp
#include <bits/stdc++.h>
using namespace std;

void pairStar(char input[]) {
	if(strlen(input)==0){
        return;
    }
    if(input[0]==input[1]){
        //move all by 1
        for(int i=strlen(input);i>0;i--){
            input[i+1]=input[i];
        }  
        input[1]='*';
        pairStar(input+2);
    }else{
        pairStar(input+1);
    }
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
```
