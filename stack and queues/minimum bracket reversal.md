Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. 
You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :
String S
Output Format :
Required count
Sample Input 1 :
{{{
Sample Output 1 :
-1
Sample Input 2 :
{{{{}}
Sample Output 2 :
1

```cpp

#include<bits/stdc++.h>
using namespace std;

int countBracketReversals(string input) {
    stack<char> st;
    int count = 0;
    if((input.length()%2)!=0){
        return -1;
    }
    
    for(int i=0;i<input.length();i++){
        if(input[i]=='{'){
            st.push(input[i]);
        }else{
            if(st.empty()){
                st.push(input[i]);
            }else if(st.empty()==0 && st.top()=='}'){
                st.push(input[i]);
            }else if(st.empty()==0 && st.top()=='{'){
                st.pop();
            }
        }
    }//mending unbalanced part 2 at a time
    while(st.empty()!=1){
        char c1=st.top();st.pop();
        char c2=st.top();st.pop();
        if(c1==c2){//like {{ or }}
            count+=1;
        }else{//like }{ P.S: {} cant be there as it is already balanced and will not reach this stack for unbalanced
            count+=2;
        }
    }
return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}

```
