You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W

```cpp
#include <bits/stdc++.h>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int i, j, x, y; 
  
    // We need n+1 rows as the table is constructed in bottom up manner using the base case 0 value case (n = 0) 
    int table[value + 1][numDenominations]; 
      
    // Fill the enteries for 0 value case (n = 0) 
    for (i = 0; i < numDenominations; i++){
        table[0][i] = 1; 
    }
  
    // Fill rest of the table entries in bottom up manner  
    for (i = 1; i < value + 1; i++){ 
        for (j = 0; j < numDenominations; j++){ 
            // Count of solutions including S[j] 
            x = (i-denominations[j] >= 0) ? table[i - denominations[j]][j] : 0; 
            // Count of solutions excluding S[j] 
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            // total count 
            table[i][j] = x + y; 
        } 
    } 
return table[value][numDenominations - 1]; 
}

int main(){
	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++){
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}
```
