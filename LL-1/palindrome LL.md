Check if a given linked list is palindrome or not. Return true or false.  

```cpp
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(Node *head){
    //Write your code here
    Node* start=head;
    int arr[1000];
    int index=0;
    if(head == NULL) {
        return true;
    }
    while(start!=NULL){
        arr[index]=start->data;
        start=start->next;
        index++;
    }
    
    int mid=(index)/2;
    int flag=1;
    for(int i=0,j=index-1;i<mid && j>=mid;i++,j--){
        if(arr[i]!=arr[j]){
            flag=0;
        }
    }
    if(flag==1){
        return true;
    }else{
        return false;
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

int main(){
	int t;
	cin >> t;

	while (t--){
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}
```
