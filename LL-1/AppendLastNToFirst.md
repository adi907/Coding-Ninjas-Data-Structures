Given a linked list and an integer n, append the last n elements of the LL to front.

```cpp
#include<bits/stdc++.h>
using namespace std;

Node*appendLastNToFirst(Node *head, int n){
    if(head==NULL){
        return head;
    }
    Node* start=head;
    int length=1;
    
    while(start->next!=NULL){
        start=start->next;
        length++;
    }
    start->next=head;
    Node* temp=head;
    int curr=0;
    while(curr!=length-n){
        temp=temp->next;
        curr++;
    }
    Node* newnode=temp;
    curr=0;
    temp=head;
    while(curr!=length-n-1){
        curr++;
        temp=temp->next;
    }
    temp->next=NULL;
    return newnode;
}

class Node{
public:
	int data;
	Node *next;
	Node(int data){
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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
```
