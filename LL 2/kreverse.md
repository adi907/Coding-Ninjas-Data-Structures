Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.
Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.
You don't need to print the elements, just return the head of updated LL.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : k

Sample Input 1 :
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9


```cpp

#include<bits/stdc++.h>
using namespace std;

Node *kReverse(Node *head, int k){
    if (head==NULL){
        return NULL;
    }
    if(k==0){
        return head;
    }
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    while (current != NULL && count < k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL){
        head->next = kReverse(next, k);
    }
    return prev;
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
	int k;
	cin >> k;
	head = kReverse(head, k);
	print(head);
    }
return 0;
}

```
