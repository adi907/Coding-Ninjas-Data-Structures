Given a generic tree, 
find and return the node with second largest value in given tree. 
Return NULL if no node with required value is present.

//approach 1 is to find max and replace it by -infinty ans then again find the max
but this change the given tree

// other approach can be to ask func to bring max and second max
// total cases needed to be handled

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

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;
    vector<int>vec;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        vec.push_back(front->data);
        pendingNodes.pop();
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }

    sort(vec.begin(),vec.end());
    
    vector<int>::iterator ip;
  
    int n=vec.size();
    ip = unique(vec.begin(), vec.begin()+n);
    vec.resize(distance(vec.begin(), ip));

    n=vec.size();
    int key=vec[n-2];
    TreeNode<int>* ans=NULL;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        if(front->data==key){
            ans=front;
        }
        pendingNodes.pop();
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
return ans;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}

```
