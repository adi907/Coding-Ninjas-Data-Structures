Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. 
In the sum, data of node itself and data of immediate children is to be taken.

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

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
	TreeNode<int>* ans=root;
	int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=(root->children[i])->data;
    }
    
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* childmax = maxSumNode(root->children[i]);
        int smallsum=childmax->data;
        for(int j=0;j<childmax->children.size();j++){
            smallsum+=(childmax->children[j])->data;
        }

        if(smallsum>=sum){
            ans=childmax;
            sum=smallsum;
        }
    }
return ans;  
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}

```
