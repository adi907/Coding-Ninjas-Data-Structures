Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not.
If yes, return true, return false otherwise.
Duplicate elements should be in right subtree.

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

bool helper(BinaryTreeNode<int> *root,int k1,int k2){
    if(root==NULL){
        return true;
    }
    int p=root->data;
    if(p<k1||p>k2){
        return false;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    else{
        return (helper(root->left,k1,p) && helper(root->right,p,k2));
    }
}

bool isBST(BinaryTreeNode<int> *root) {
   return helper(root,INT_MIN,INT_MAX); 
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}
```
