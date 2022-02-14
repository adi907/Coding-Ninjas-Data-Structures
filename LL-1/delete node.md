Given a linked list and a position i, delete the node of ith position from Linked List iteratively.
If position i is greater than length of LL, then you should return the same LL without any change.
Indexing starts from 0. You don't need to print the elements, just delete the node and return the head of updated LL.

```cpp
#include<bits/stdc++.h>
using namespace std;

Node *deleteNode(Node *start, int pos){
    int count=0;
    Node* temp=start;
    Node* prev;
    if(start==NULL){
        return start;
    }
    if(pos==0){
        Node* newhead=start->next;
        delete(start);
        return newhead;
    }
    while(temp!=NULL && count!=pos){
        prev=temp;
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        prev->next=temp->next;
        delete temp;
    }
    return start;
}//does not pass 1 test case

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}
```
