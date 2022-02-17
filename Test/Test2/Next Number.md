Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).

```cpp
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


Node* NextLargeNumber(Node *head){
    head = reverse_node(head); 
    head = addOneUtil(head); 
return reverse_node(head); 
}
 
Node* reverse_node(Node* start){
    Node* current=start;
    Node* bwd=NULL;
    Node* fwd=NULL;
    while(current!=NULL){
        fwd=current->next;
        current->next=bwd;
        bwd=current;
        current=fwd;
    }
return bwd;
}

Node *addOneUtil(Node *head) {  
    Node* res = head; 
    Node *temp, *prev = NULL; 
  
    int carry = 1, sum; 
  
    while (head != NULL){ 
        sum = carry + head->data; 
        carry = (sum >= 10)? 1 : 0; 
        sum = sum % 10; 
        head->data = sum; 
        temp = head; 
        head = head->next; 
    } 
    if (carry > 0){ 
        temp->next = new Node(carry); 
    }
return res; 
}

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

int main(){
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}
```
