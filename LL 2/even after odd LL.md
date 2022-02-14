Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
Note: Input and Output has already managed for you. You don't need to print the elements, instead return the head of updated LL.

```cpp
#include<bits/stdc++.h>
using namespace std;

Node *evenAfterOdd(Node *head){
	Node* start=head;
    Node* oddhead=NULL;
    Node* evenhead=NULL;

    Node* odd_prev;
    Node* even_prev;
    while(start!=NULL){
        if((start->data)%2!=0){
            Node* newnode=new Node(start->data);
            newnode->next=NULL;
            if(oddhead==NULL){
                oddhead=newnode;
            }else{
                odd_prev->next=newnode;
            }
            odd_prev=newnode;
        }else{
            Node* newnode=new Node(start->data);
            newnode->next=NULL;
            if(evenhead==NULL){
                evenhead=newnode;
            }else{
                even_prev->next=newnode;
            }
            even_prev=newnode;
        }
        start=start->next;
    }
    if(oddhead==NULL){
        return evenhead;
    }
    
    Node* start2=oddhead;
    while(start2->next!=NULL){
        start2=start2->next;
    }
    start2->next=evenhead;
return oddhead;
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

void print(Node *head){
	Node *temp = head;
	while (temp != NULL){
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
		head = evenAfterOdd(head);
		print(head);
	}
return 0;
}
```
