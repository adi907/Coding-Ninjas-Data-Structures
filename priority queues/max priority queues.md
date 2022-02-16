```cpp
#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

    public:
    // PriorityQueue() {
    //     // Implement the constructor here
    // }
    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return getSize()==0;
    }
    
    int getMax() {
        // Implement the getMax() function here
        if(pq.size()==0){
            return INT_MIN;
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
                
            if(pq[childIndex]>pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }else{
                break;
            }
            childIndex=parentIndex;
    	}
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(pq.size()==0){
            return INT_MIN;
        }
        int answer=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();//swap and pop

        //down heapify to reinstate hea order property
        int parentIndex=0;
        int leftChildIndex=(2*parentIndex)+1;
        int rightChildIndex=(2*parentIndex)+2;


        while(leftChildIndex<pq.size()){
            int minIndex=parentIndex;
            if(pq[leftChildIndex]>pq[minIndex]){
                minIndex=leftChildIndex;
            }
            if(pq[rightChildIndex]>pq[minIndex] && rightChildIndex<pq.size()){//check if it goes out of bounds
                minIndex=rightChildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }

            int temp=pq[minIndex];
            pq[minIndex]=pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex=minIndex;
            leftChildIndex=(2*parentIndex)+1;
            rightChildIndex=(2*parentIndex)+2;
        }
    return answer;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
```
