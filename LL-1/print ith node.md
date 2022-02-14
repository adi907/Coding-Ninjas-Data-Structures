Given a linked list and a position i, print the node at ith position.
If position i is greater than length of LL, then don't print anything.

```cpp
#include<bits/stdc++.h>
using namespace std;

void printIthNode(Node *head, int i){
    //Write your code here
    int count=0;
    Node* start=head;
    if(i<0){
        cout<<endl;
        return;
    }
    while(start!=NULL){
        if(i==count){
            cout<<start->data<<endl;
            return;
        }
        start=start->next;
        count++;
    }
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
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}
```
