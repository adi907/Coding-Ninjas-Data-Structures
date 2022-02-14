```cpp
#include<bits/stdc++.h>
using namespace std;

class Stack {
	// Define the data members
    Node* head;
	int size;
   public:
    Stack() {
        // Implement the Constructor
        size=0;
        head=NULL;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return(size==0);
    }

    void push(int element) {
        Node *newnode=new Node(element);
            if(head==NULL){
                head=newnode;
            }else{
                newnode->next=head;
                head=newnode;
            }
            size++;
    }

    int pop(){
        if(isEmpty()){
                return -1;
            }

            int val=head->data;
            Node *future=head->next;
            delete head;
            head=future;
            size--;
            return val;
    }

    int top() {
        if(isEmpty()){
                return -1;
            }
            return head->data;
    }
};

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
```
