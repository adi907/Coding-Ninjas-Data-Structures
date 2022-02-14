```cpp
#include<bits/stdc++.h>
using namespace std;

int helper(Node* start,int key,int pos){
    if(start==NULL){
        return -1;
    }
    if(start->data==key){
        return pos;
    }
    return helper(start->next,key,pos+1);
}

int findNodeRec(Node *head, int n){
    return helper(head,n,0);
}

class Node{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput(){
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1){
		Node *newNode = new Node(data);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}
}
```
