```cpp
#include<bits/stdc++.h>
using namespace std;

Node *bubbleSort(Node *head){
    if(head==NULL){
        return head;
    }
    Node* i,*j;
    int temp;
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    return head;
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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}
```
