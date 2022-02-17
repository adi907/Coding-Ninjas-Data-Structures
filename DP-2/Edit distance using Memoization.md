```cpp
#include<bits/stdc++.h>
using namespace std;

//via Memoiztion
int editDistance_mem(string s1, string s2, int **output) {
	int m = s1.size();
	int n = s2.size();
	
	if(s1.size() == 0 || s2.size() == 0) {
		return max(s1.size(), s2.size());
	}

	// Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;
	if(s1[0] == s2[0]) {
		ans = editDistance_mem(s1.substr(1), s2.substr(1), output);
	}else{
		// Insert
		int x = editDistance_mem(s1.substr(1), s2, output) + 1;
		// Delete
		int y = editDistance_mem(s1, s2.substr(1), output) + 1;
		// Replace
		int z = editDistance_mem(s1.substr(1), s2.substr(1), output) + 1;

		ans =  min(x, min(y, z));
	}

	// Save the ans
	output[m][n] = ans;

	// Return the ans
return ans;
}

int editDistance(string s1, string s2){

    int m = s1.size();
    int n = s2.size();
    int **ans = new int*[m+1];
    for(int i = 0; i <= m; i++) {
        ans[i] = new int[n+1];
        for(int j = 0; j <= n; j++) {
            ans[i][j] = -1;
        }
    }
    
return editDistance_mem(s1, s2, ans);
}


int main(){
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}
```
