Given a linked list, find and return the length of input LL. Do it iteratively.

```cpp
#include<bits/stdc++.h>
using namespace std;

int length(Node *head){
    //Write your code here
    Node* start=head;
    int result=0;
    while(start!=NULL){
        result++;
        start=start->next;
    }
    return result;
}

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    cout << length(head);
    return 0;
}
```
