```cpp
#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        int leftChild=1,rightChild=2;
            int smallestIndex=0;
            int minIndex;
			
        	int answer=pq[0];
            pq[0]=pq[pq.size()-1];
        	
            pq.pop_back();

            while(leftChild<pq.size()){
                if(pq[leftChild]<pq[rightChild]){
                    minIndex=leftChild;
                }else{//check if it goes out of bounds
                     minIndex=rightChild;
                }

                if(pq[smallestIndex]>pq[minIndex]){
                    int temp=pq[smallestIndex];
                    pq[smallestIndex]=pq[minIndex];
                    pq[minIndex]=temp;
                }else{
                    break;
                }
                    smallestIndex=minIndex;
                    leftChild=(2*minIndex)+1;
                    rightChild=(2*minIndex)+2;
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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
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
