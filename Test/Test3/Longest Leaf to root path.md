Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.

```cpp
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput(){
    int rootData;

    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int height(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    
    return 1+ max(height(root->left),height(root->right));
}

vector<int>* longestPath(BinaryTreeNode<int>* root){
    if(root->left==NULL && root->right==NULL){
        vector<int> *ans = new vector<int>();
        ans->push_back(root->data);
    return ans;
    }
    int left=0;
    int right=0;
    if(root->left){
    	left=height(root->left);   
    }
    if(root->right){
       right=height(root->right);
    }
    
    if(left>right){
		vector<int>* l =longestPath(root->left);
        l->push_back(root->data);
        return l;
    }else{
        vector<int>* r =longestPath(root->right);
        r->push_back(root->data);
        return r;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
```
