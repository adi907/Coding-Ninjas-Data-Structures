Given a linked list, find and return the midpoint.

```cpp
#include<bits/stdc++.h>
using namespace std;

Node *midPoint(Node *head){
    if(head==NULL){
        return head;
    }
    int length=0;
    Node* start=head;
    while(start!=NULL){
        length++;
        start=start->next;
    }
    int target;
    if(length%2==0){
        target=(length/2)-1;
    }else{
        target=length/2;
    }
    start=head;
    int index=0;
    while(index!=target){
        start=start->next;
        index++;
    }
    return start;
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
		Node *newnode = new Node(data);
		if (head == NULL){
			head = newnode;
			tail = newnode;
		}else{
			tail->next = newnode;
			tail = newnode;
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
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}
```
