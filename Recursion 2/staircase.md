/*Staircase
Send Feedback
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :
Integer N
Output Format :
Integer W
Constraints :
1 <= N <= 30
Sample Input 1 :
4
Sample Output 1 :
7
Sample Input 2 :
5
Sample Output 2 :
13
*/

```cpp
#include <bits/stdc++.h>
using namespace std;

int staircase_help(int n,int step){
    if(n==step){
        return 1;
    }
    if(step>n){
        return 0;
    }
    return staircase_help(n,step+1)+staircase_help(n,step+2)+staircase_help(n,step+3);
    
}

int staircase(int n){
    int ans=staircase_help(n,0);
    return ans;
}

int main() {
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output <<endl;
}
```
