Given a binary tree and a number k,
 print out all root to leaf paths where the sum of all nodes value is same as the given number k.
 
```cpp

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k,vector<int> path){
    if(root==NULL){
        return;
    }
    
    path.push_back(root->data);
    k=k-root->data;
    
    if(root->left==NULL && root->right==NULL){
        if(k==0){
            for(int i=0;i<path.size();i++){
                cout<< path[i]<<" ";
            }cout<<endl;
        }
        path.pop_back();
        return;
    }
    rootToLeafPathsSumToK(root->left,k,path);    
    rootToLeafPathsSumToK(root->right,k,path);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> v;
    rootToLeafPathsSumToK(root,k,v);
return;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}
```
