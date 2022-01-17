```cpp

#include<bits/stdc++.h>
using namespace std;
#define N 10

bool isValidHorizontal(char** grid,int row, int col, string word){
	if(10 - col < word.length()){
		return false;
    }
 
	for (int i = 0, j = col; i < word.length(); ++i,j++){
		if (grid[row][j] != '-' && grid[row][j] != word[i]){
			return false;
		}
	}
 
	return true;
}
 
bool isValidVertical(char** grid,int row, int col, string word){
 
	if(10 - row < word.length()){
		return false;
    }
 
	for (int i = row, j = 0; j < word.length(); ++i,j++){
		if (grid[i][col] != '-' && grid[i][col] != word[j]){
			return false;
		}
	}
return true;
}
 
void setHorizontal(char** grid,int row, int col, string word, bool state[]){
	for (int i = 0, j = col; i < word.size(); ++i, j++){
		if (grid[row][j] != '+'){
			if(grid[row][j] == word[i]){
				state[i] = false;
            }else{
				state[i] = true;
            }
			grid[row][j] = word[i];
		}
	}
}
 
void setVertical(char** grid,int row, int col, string word, bool state[]){
	for (int i = 0, j = row; i < word.size(); ++i, j++){
		if (grid[j][col] != '+'){
 
			if(grid[j][col] == word[i]){
				state[i] = false;
            }else{
				state[i] = true;
            }
			grid[j][col] = word[i];
		}
	}
}
 
void resetHorizontal(char**grid,int row, int col, bool state[], int size){
	for (int i = 0, j = col; i < size; ++i,j++){
		if(state[i] == true){
			grid[row][j] = '-';
        }
	}
	return;
}
 
void resetVertical(char**grid,int row, int col, bool state[], int size){
	for (int i = 0, j = row; i < size; ++i,j++){
		if(state[i] == true){
			grid[j][col] = '-';
        }
	}
	return;
}
 
void set_value(bool helper[],int len ){
	for(int i=0;i<len;i++){
		helper[i] = false;
	}
}
 
 
bool crossWordHelper(char** grid,vector<string> input, int index){
	if(index == input.size()){
		for(int i =0; i<N; i++){
			for(int j=0; j<N; j++){
				cout << grid[i][j] ;
			}cout << endl;
		}
		return true;
	}
 
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(grid[i][j] == '-' || grid[i][j] == input[index][0]){
				int length = input[index].size();
				bool state[length];
				set_value(state,length);
 
				if(isValidHorizontal(grid,i, j, input[index])){
					setHorizontal(grid,i, j, input[index], state);
					if(crossWordHelper(grid,input, index+1)){
						return true;
					}
					resetHorizontal(grid,i, j, state, length);
				}
 
				if(isValidVertical(grid,i, j, input[index])){
					setVertical(grid,i, j, input[index], state);
					if(crossWordHelper(grid,input, index+1)){
						return true;
					}
					resetVertical(grid,i, j, state, length);
				}
			}
		}
	}
	return false;
}

void crossword_solver(char** grid,vector<string>input){
    bool res=crossWordHelper(grid,input,0);
    if(!res){
        cout<<"no solution exists"<<endl;
    }
    return;
}

int main(){
    char** grid=new char*[N];
    for(int i=0;i<N;i++){
        grid[i]=new char[N];
    }

	for(int i=0;i<N;i++){
		for(int j = 0; j < N; j++){
			cin>>grid[i][j];
		}
	}
 
	char s[200];
	cin >> s;
 
    vector<string> words;
	string word ="";

	for (int i=0; s[i]!='\0';++i){
		if(s[i] ==';'){
			words.push_back(word);
			word ="";
		}else{
            word+=s[i];
		}
	}words.push_back(word);

	crossword_solver(grid,words);

return 0;
}
```
