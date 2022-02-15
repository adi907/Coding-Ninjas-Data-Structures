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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {    
	TreeNode<int> *max=new TreeNode<int>(INT_MIN);
    queue<TreeNode<int>*> pn;
    pn.push(root);
    
    while(pn.size()!=0){
        TreeNode<int>* front=pn.front();
        pn.pop();
        if(front->data > max->data)
           max=front;
            
        for(int i=0;i<front->children.size();i++){
            pn.push(front->children[i]);
        }
    }
return max;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root){

    TreeNode<int> *max=new TreeNode<int>(root->data);
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *child=maxDataNode(root->children[i]);
        if(child->data > max->data)
              max=child;
    }
return max;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }
}
```
