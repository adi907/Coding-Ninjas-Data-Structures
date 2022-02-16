Given a BST, convert it into a sorted linked list. Return the head of LL.

```cpp
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

Node<int>* helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        return NULL;
    }
    
    Node<int>* centre=new Node<int>(root->data);
    Node<int>* lhead=helper(root->left);
    Node<int>* rhead=helper(root->right);

    if(lhead==NULL && rhead==NULL){
        return centre;
    }
    if(lhead!=NULL && rhead==NULL){
        Node<int>* lhead2=lhead;
        while(lhead2->next!=NULL){
            lhead2=lhead2->next;
        }
        lhead2->next=centre;
    return lhead;
    }
    if(lhead==NULL && rhead!=NULL){
        centre->next=rhead;
        return centre;
    }
    if(lhead!=NULL && rhead!=NULL){
        Node<int>* lhead2=lhead;
        while(lhead2->next!=NULL){
            lhead2=lhead2->next;
        }
        lhead2->next=centre;
        centre->next=rhead;
    return lhead;
    }
    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return helper(root);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
```
