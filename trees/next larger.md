Given a generic tree and an integer n. 
Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.

```cpp

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    int keydata=x;
    TreeNode<int>*ans=NULL;

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        if(ans==NULL && (front->data)>keydata){
            ans=front;
        }
        else if(ans!=NULL && (front->data)>keydata){
            if(front->data<ans->data){
                ans=front;
            }
        }
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
return ans;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}


```
