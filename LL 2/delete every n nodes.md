Delete every N nodes
Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, 
continue the same until end of the linked list. 
That is, in the given linked list you need to delete N nodes after every M nodes.



```cpp
#include<bits/stdc++.h>
using namespace std;

Node* delete_start(Node* start){
    Node *x;
    x=start->next;
    free(start);
    return x;
}


Node *skipMdeleteN(Node *head, int M, int N){
    Node* start=head;
    Node* newhead=head;
    if(M==0){
        newhead=NULL;
        return newhead;
    }
    while(start!=NULL){
        for(int i=0;i<M-1;i++){
            if(start->next==NULL){
                return newhead;
            }
            start=start->next;
        }
        for(int i=0;i<N;i++){
            if(start->next==NULL){
                return newhead;
            }
            start->next=delete_start(start->next);
        }
        start=start->next;
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
```
