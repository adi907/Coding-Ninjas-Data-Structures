```cpp
#include<bits/stdc++.h>
using namespace std;

void printReverse(Node *head){
    //Write your code here
    Node* start=head;
    int arr[1000];
    int index=0;
    if(head == NULL) {
        return;
    }
    while(start!=NULL){
        arr[index]=start->data;
        start=start->next;
        index++;
    }
    for(int i=index-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
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
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
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
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}
```
