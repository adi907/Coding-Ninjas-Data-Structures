```cpp
#include<bits/stdc++.h>
using namespace std;

int findNode(Node *head, int n){
    // Write your code here.
    int result=0;
    while(head!=NULL){
        if(head->data==n){
            return result;
        }
        result++;
        head=head->next;
    }
    if(head==NULL){
        return -1;
    }
}

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

int main(){
	int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}
```
