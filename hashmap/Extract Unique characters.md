Given a string, you need to remove all the duplicates. 
That means, the output string should contain each character only once. The respective order of characters should remain same.

```cpp
#include<bits/stdc++.h>
using namespace std;

string uniqueChar(string str) {
    unordered_map<char,int> ourMap;
	string output;

	for(int i=0;i<str.length();i++){
		if(ourMap.count(str[i])==0){
			output.push_back(str[i]);
			ourMap[str[i]]++;
		}
	}
return output;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
```
