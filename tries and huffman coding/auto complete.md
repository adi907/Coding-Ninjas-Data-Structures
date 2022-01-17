Givan n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.

```cpp
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
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

    bool insertWord(TrieNode *root, string word) {
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
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    void insertHelper(vector<string> input){
        for(int i=0;i<input.size();i++){
            insertWord(input[i]);
        }
    }

    TrieNode* ifExists(TrieNode* head,string word){
        if(word.size()==0){//base case
            return head;
        }
        int index=word[0]-'a';
        if(head->children[index]==NULL){
            return NULL;
        }
        return ifExists(head->children[index],word.substr(1));
    }

    void helper(TrieNode* head,string pattern,string output){
        if(head->isTerminal){
            cout<<pattern<<output<<endl;
        }

        TrieNode* child;
        for(int i=0;i<26;i++){
            child=head->children[i];
            if(child!=NULL){
                helper(child,pattern,output+child->data);
            }
        }
    return;
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        insertHelper(input);
        TrieNode* head=ifExists(root,pattern);

        if(head==NULL){
            return;
        }
        string output;
        helper(head,pattern,output);
    }
};
```
