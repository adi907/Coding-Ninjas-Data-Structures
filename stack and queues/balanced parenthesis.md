```cpp


#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string expression) {
    // Write your code here
    stack<char> s;
    char c;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='('||expression[i]=='{'){
            s.push(expression[i]);
        }
        if(expression[i]==')'||expression[i]=='}'){
            if(s.empty()){
                return false;
            }
            c=expression[i];
            if(c==')' && s.top()=='('){
                s.pop();
            }
            else if(c=='}' && s.top()=='{'){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }else{
        return false;
    }
}

int main() {
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}

```
