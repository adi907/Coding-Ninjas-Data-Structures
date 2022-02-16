Given a binary tree, write code to create a separate linked list for each level.
You need to return the array which contains head of each level linked list.

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9

```cpp
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> v;
	if(root==NULL){
       v.push_back(NULL) ;
    return v;
    } 
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    Node<int> *head=NULL;
    Node<int> *tail =head;

    while(pendingNodes.size()!=0){ 
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        
        if(front==NULL){
            tail->next=NULL;
        
            if(pendingNodes.size()==0){
                break;
            }
            pendingNodes.push(NULL);
        
            head=NULL;
            tail=NULL;
        }else{  
            Node <int> *n=new Node<int> (front->data);
            if(head==NULL){
                head=tail=n;
                v.push_back(head);
            }else{
               tail->next=n;
               tail=n;
            }
            if(front->left){
             	pendingNodes.push(front->left);   
            }
            if(front->right){
             	pendingNodes.push(front->right);   
            }
        }
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}
```
