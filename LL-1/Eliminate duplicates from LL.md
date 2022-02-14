```cpp
#include<bits/stdc++.h>
using namespace std;

Node* delete_node(Node* start,int pos){
    int count=0;
    Node* temp=start;
    Node* prev;
    if(pos<0){
        return start;
    }
    if(pos==0){
        Node* newhead=start->next;
        delete start;
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
}

Node *removeDuplicates(Node *head){
    if(head == NULL||head->next == NULL){
        return head;
    }
    Node *p=head->next,*q=head;
    while(p){
       if(p->data==q->data){
           q->next=p->next;
           Node *t=p;
           p=p->next;
          delete t;
      }else{
        q=q->next;
        p=p->next;
        }
    }
    return head;
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}
```
