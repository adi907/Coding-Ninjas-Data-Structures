Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf


```cpp
#include<bits/stdc++.h>
using namespace std;

string keypadArr[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    string input;
  	if(num==0||num==1){
        output[0]=="";
        return 1;
    }  
    int n=num%10;
    num/=10;
    int smalloutput_size=keypad(num,output);
    input=keypadArr[n];
    int ans_size=smalloutput_size*input.size();
    
    string temp_arr[ans_size];
    int k=0;
    for(int i=0;i<smalloutput_size;i++){
        for(int j=0;j<input.size();j++){
            temp_arr[k]=output[i]+input[j];//doubt
            k++;
        }
    }
    for(int i=0;i<ans_size;i++){
        output[i]=temp_arr[i];
    }
    return ans_size;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
```
