Given a Binary tree, find the largest BST subtree. 
That is, you need to find the BST with maximum height in the given binary tree.

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

class Pair{
	public:
		int minimum;
		int maximum;
		bool bst;
		int height;
};

Pair BST(BinaryTreeNode<int> *root){
    if(root==NULL){
    	Pair obj;
    	obj.minimum =INT_MAX;
    	obj.maximum = INT_MIN;
    	obj.bst = true;
    	obj.height=0;
    return obj;
    }
    
    Pair left= BST(root->left);
    Pair right =BST(root->right);
    
    int minimum=min(root->data,min(left.minimum,right.minimum));
    int maximum=max(root->data,max(left.maximum,right.maximum));
    bool  isBSTfinal=(root->data >left.maximum) && (root->data < right.minimum) && left.bst && right.bst;
   
    Pair obj;
    obj.minimum=minimum;
    obj.maximum=maximum;
    obj.bst=isBSTfinal;
    if(isBSTfinal){
        obj.height= 1+max(left.height,right.height);
    }else{
        obj.height= max(left.height,right.height);
    }
    return obj;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return BST(root).height;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
```
