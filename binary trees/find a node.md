Given a Binary Tree and an integer x, check if node with data x is present in the input binary tree or not. Return true or false.

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

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    vector<int> vec;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front=pendingNodes.front();
        if(front->data==x){
            return true;
        }
        vec.push_back(front->data);
        if(front->left!=NULL){
            if(front->left->data==x){
                return true;
            }
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL){
            if(front->right->data==x){
                return true;
            }
            pendingNodes.push(front->right);
        }
        pendingNodes.pop();
    }
return false;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}
```
