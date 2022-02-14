Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).
Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.

```cpp
#include<bits/stdc++.h>
using namespace std;

Node* insert_start(Node *start,int info){
        Node *newnode=(Node*)malloc(sizeof(Node));
        newnode->data = info;
        newnode->next=start;
        return newnode;
}

void insert_pos(Node* start,int index,int info){
    int count=0;
    while(start!=NULL && count!=index-1){
        start=start->next;
        count++;
    }
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=info;
    newnode->next=start->next;
    start->next=newnode;
}


Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    Node* start1=head1;
    Node* start2=head2;
	
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    int k=0;

    Node* newhead;
    if((start1->data)<(start2->data)){
        newhead=start1;
        k++;
        start1=start1->next;
    }else{
        newhead=insert_start(head1,start2->data);
        start2=start2->next;
        k++;
    }

    while(start1!=NULL && start2!=NULL){
        if(start1->data<start2->data){
            start1=start1->next;
            k++;
        }else{
            insert_pos(newhead,k,start2->data);
            k++;
            start2=start2->next;
        }
    }

    while(start1!=NULL){
        k++;
        start1=start1->next;
    }
    while(start2!=NULL){
        insert_pos(newhead,k,start2->data);
        k++;
        start2=start2->next;
    }
return newhead;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
```
