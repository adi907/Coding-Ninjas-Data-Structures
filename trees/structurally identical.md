Given two Generic trees, return true if they are structurally identical
i.e. they are made of nodes with the same values arranged in the same way.

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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    queue<TreeNode<int>*> p1;vector<int>v1;
    queue<TreeNode<int>*> p2;vector<int>v2;

    p1.push(root1);
    p2.push(root2);

    while(p1.size()!=0){
        TreeNode<int>* front=p1.front();
        v1.push_back(front->data);
        p1.pop();
        for(int i=0;i<front->children.size();i++){
            p1.push(front->children[i]);
        }
    }
    while(p2.size()!=0){
        TreeNode<int>* front=p2.front();
        v2.push_back(front->data);
        p2.pop();
        for(int i=0;i<front->children.size();i++){
            p2.push(front->children[i]);
        }
    }

    if(v1.size()!=v2.size()){
        return false;
    }

    for(int i=0;i<v1.size();i++){
        if(v1[i]!=v2[i]){
            return false;
        }
    }
return true;
}

int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}

```
