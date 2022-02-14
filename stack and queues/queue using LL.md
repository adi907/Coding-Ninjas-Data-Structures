```cpp
#include<bits/stdc++.h>
using namespace std;

class Queue {
	// Define the data members
    Node *head;
    Node *tail;
    int size;

   public:
    Queue() {
		// Implement the Constructor
        size=0;
		head=NULL;
        tail=NULL;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return (size==0);
	}

    void enqueue(int data) {
		// Implement the enqueue() function
        Node *newnode=new Node(data);
            newnode->next=NULL;
            if(head==NULL){
                head=newnode;
                tail=newnode;
            }else{
                tail->next=newnode;
                tail=newnode;
            }
            size++;
        
	}

    int dequeue() {
        // Implement the dequeue() function
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

    int front() {
        // Implement the front() function
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
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
```
