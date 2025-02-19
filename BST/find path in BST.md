Given a BST and an integer k. Find and return the path from the node with data k and root 
(if a node with data k is present in given BST). Return null otherwise.
Assume that BST contains all unique elements.

```cpp

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

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

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    if(root==NULL){
       return NULL;
    }
    if(root->data==data){
       vector<int>* v=new vector<int>();
       v->push_back(data);
    return v;
    }

    vector<int>* vec;
    if(root->data>data){
        vec=getPath(root->left,data);
        if(vec!=NULL){
            vec->push_back(root->data);
            return vec;
        }
    }else{
        vec=getPath(root->right,data);
        if(vec!=NULL){
            vec->push_back(root->data);
            return vec;
        }
    }
    return NULL;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}
```
