Sort a given linked list using Merge Sort.  

```cpp
#include<bits/stdc++.h>
using namespace std;

Node *middle(Node *head) {
    Node *mid = head;
    Node *tail = head->next;
   
    while((mid->next != NULL) && (tail!=NULL && tail->next!=NULL)) {
        mid = mid->next;
        tail = tail->next->next;
    }
    return mid;
}

Node* mergeSortedList(Node* head1, Node* head2){
    Node* newHead = NULL;
    Node *tail=NULL;
   
    if (head1->data <= head2->data) {
        newHead = head1;
        head1=head1->next;
    }else{
        newHead = head2;
        head2=head2->next;
    }
    tail=newHead;
   
    while(head1!=NULL && head2!=NULL){
        if (head1->data <= head2->data){
        	tail->next = head1;
        	head1=head1->next;
    	}else{
        	tail->next = head2;
        	head2=head2->next;
    	}
    	tail=tail->next;
    }
    if(head1!=NULL){
        tail->next=head1;
    }
    if(head2!=NULL){
        tail->next=head2;
    }
return newHead;
}

Node* mergeSort(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* mid;
    mid=middle(head);
    Node* head2=mid->next;
    mid->next=NULL;
    Node *newHead = mergeSortedList(mergeSort(head),mergeSort(head2));
return newHead;
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
```
