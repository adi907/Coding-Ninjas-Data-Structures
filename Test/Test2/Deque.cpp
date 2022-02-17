#include<bits/stdc++.h>
using namespace std;

class Deque {
    int *data;
  	int front;
  	int rear;
    int SIZE;
    public:
    Deque(int total_size){
  	  front = -1;
  	  rear = -1;
      data=new int[total_size];
      SIZE=total_size;
  	}
    
    bool Full(){
  	  if((front==0 && rear==SIZE-1) || (front==rear+1))
  	    return(true);
  	  else 
  	    return(false);
  	}
  	
  	bool Empty(){
  	  if(front == -1)
  	    return(true);
  	  else
  	    return(false);
  	}
    
    void insertFront(int x){
  	   if(Full()){
         cout<<"-1"<<endl;
  	     return;
  	    }else{
  	      if(front==-1){
  	        front = 0;
  	        rear = 0;
  	        data[front] = x;
  	      }else if(front == 0){
  	        front = SIZE-1;
  	        data[front] = x;
  	      }else
  	        data[--front] = x;
  	   }
  	 }
    
    void insertRear(int x){
  	   if(Full()){
           cout<<"-1"<<endl;
  	     return;
  	    }else{
  	      if(front==-1){
  	        front = 0;
  	        rear = 0;
  	        data[front] = x;
  	      }else if(rear == SIZE-1){
  	        rear = 0;
  	        data[rear] = x;
  	      }else{
  	        data[++rear] = x;
  	      }
  	    }
  	  }
    
    void deleteFront(){
  	    if(Empty()){
            cout<<"-1"<<endl;
              return;
        }else{
  	      if(front == rear){
  	        front =-1;
  	        rear = -1;
  	      }else{
  	        if(front == SIZE-1)
  	          front = 0;
  	        else
  	          front++;
  	        }
  	    }
  	   }
    
    void deleteRear(){
  	     if(Empty()){
        	cout<<"-1"<<endl;
  	       return;
         }else{
  	       if(front == rear){
  	         front = -1;
  	         rear = -1;
  	        }
  	       else{
  	         if(rear == 0)
  	           rear = SIZE-1;
  	         else
  	           rear--;
  	        }
  	     }
  	}	
    
    int getFront(){
  		if(Empty()){
  	        return -1;
  	    }
  	return data[front];
  	}

  	int getRear(){
  		if(Empty()){
  		  return -1;
  		}
  	return data[rear];
  	}
    
};
