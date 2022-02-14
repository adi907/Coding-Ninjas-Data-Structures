Given a string mathematical expression, return true if redundant brackets are present in the expression. 
Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.

Sample Input 1:
((a + b)) 
Sample Output 1:
true
Sample Input 2:
(a+b) 
Sample Output 2:
false

// in current code test cases like  }{}{}{}{}{ fails
// see soln for other aproach

```cpp

#include<bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string str) {
	stack<char> st;
    for(int i=0;i<str.length();i++){
        if (str[i]== ')'){
            char top = st.top();
            st.pop();
            
            bool flag = true;
            while (!st.empty() && top != '(') {
                if (top == '+' || top == '-' ||top == '*' || top == '/'){
                    flag = false;
                }
                top = st.top();
                st.pop();
            }
            // If operators not found
            if (flag == true){
                return true;
            }
        }else{
            st.push(str[i]);
        }
    }
return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}

```
