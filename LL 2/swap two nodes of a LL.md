Given a linked list, i & j, swap the nodes that are present at i & j position in the LL.
You need to swap the entire nodes, not just the data.

```cpp
#include<bits/stdc++.h>
using namespace std;

Node *swapNodes(Node *head, int i, int j){
    Node* prevx=NULL;
    Node* prevy=NULL;
    
    Node* nextx=NULL;
    Node* nexty=NULL;

    Node* start=head;
    int index=0;
    while(index!=i){
        index++;
        prevx=start;
        if(start->next!=NULL){
            nextx=start->next->next;
        }
        start=start->next;
    }
    Node* x=start;


    start=head;
    index=0;
    while(index!=j){
        index++;
        prevy=start;
        nexty=start->next->next;
        start=start->next;
    }
    Node* y=start;

    if(j-i==1){
        prevx->next=nextx;
        x->next=nextx->next;
        nextx->next=x;
        return head;
    }
    if(i==0){
        y->next=head->next;
        prevy->next=x;
        x->next=nexty;

        return y; 
    }else{
        prevx->next=y;
        y->next=nextx;
        prevy->next=x;
        x->next=nexty;
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
	int t;
	cin >> t;
	while (t--){
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
```
