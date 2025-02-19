Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word itself is a palindrome.
The function should return either true or false. You don't need to print anything.

```cpp
#include<bits/stdc++.h>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;
   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool search(string word){
        return search(root,word);
    }

    void add(string word) {
        if(add(root, word)) {
            this->count++;
        }
    }

   private:
    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        return add(child, word.substr(1));
    }

    bool search(TrieNode* root,string word){
        if(word.size()==0){
            return true;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL){
            return false;
        }
        return search(root->children[index],word.substr(1));
    }

   public:
    string reverse(string s){
        string ans;
        int n=s.length();
        for(int i=0,j=n-1;i<n && j>=0;i++,j--){
            ans.push_back(s[j]);
        }
    return ans;
    }

    void insertHelp(vector<string>words){
        for(int i=0;i<words.size();i++){
            int j=words[i].size();
            while(j>1){
                string s=words[i].substr(0,j);
                string send=reverse(s);
                add(send);
                j--;
            }
        }
    }
    
    bool isPalindromePair(vector<string> words) {
        // Write your code here
        insertHelp(words);//insert in reverse order(with permuations)
	
        for(int i=0;i<words.size();i++){//search normally(with permutations)
            int j=0;
            while(j<words[i].size()-1){
                if(search(words[i].substr(j))){
                    return true;
                }
                j++;
            }
        }
    return false;
    }
};

int main(){
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
    
return 0;
}
```
