 /*
AIM:
Write program to implement a priority queue in C++ using an inorder list to store the items in the queue.
Create a class that includes the data items 
(which should be template) 
and the priority (which should be int). 
The inorder list should contain these objects
with operator <= overloaded so that the items with highest priority appear at the beginning of the list
(which will make it relatively easy to retrieve the highest item.)
INPUT: 
    1. Item information (Name, Priority)
	
OUTPUT:
	a) Add Item in Priority Queue
	b) Delete Item from Priority Queue
	c) Display Queue
	

*/
#include<iostream>
#define MAX 3
using namespace std;

template <class T>
class ITEM{
	public:
	T data;
	int priority;
	
	
	bool operator <=(ITEM& ob2){
			if (priority <= ob2.priority)
				return true;
			else
				return false; 			
		}
		
};

class Queue{
	private:
		ITEM<string> Q[MAX];
		int front,rear;
	public:
		Queue(){
			front=rear=-1;
		}
		
		
		bool isQueueEmpty(){
			if (front == -1)
				return true;
			else
				return false;
		}
		
		
		bool isQueueFull(){
			if (rear == MAX-1)
				return true;
			else
				return false;
		}
		
		
		void enQueue(ITEM<string> item){
				int i;
				ITEM<string> temp;
				if(! isQueueFull()){
					
					if(front == -1){
						front=rear=0;
						Q[rear]=item;
					}
					else
						Q[++rear]=item;
				
					
					for(i=rear;i>0;i--){
						if(Q[i]<=Q[i-1]){
							temp=Q[i];
							Q[i] = Q[i-1];
							Q[i-1]=temp;
						}
					}
				}
				else
					cout<<"\nQueue is full!!";
		}
		
		
		
		
		void dQueue(){
				int i;
				if(!isQueueEmpty()){
					
					if(front == rear){
						cout<<"\n"<<Q[front].data<<"  is deleted from Queue";
						front=rear=-1;
					}
					else{
						cout<<"\n"<<Q[front].data<<"  is deleted from Queue";
					}
					
					
					for (i=0;i<rear;i++)
						Q[i]=Q[i+1];
					
					rear--;
				}
				else
					cout<<"\nQueue is Empty!!";
		}
		
		
		void displayQueue(){
			int i;
			if(!isQueueEmpty()){
				cout<<"\nJob Queue is:\n";
				for (i=front;i<=rear; i++)
					cout<<"|"<<Q[i].data<<"-"<<Q[i].priority<<"| ";
			}
			else
				cout<<"\n Queue Empty!!";
		}	
};


int main(){
	int choice=0;
	ITEM<string> j;
	Queue obj ;
	while(choice != 4){
		cout<<"\n***************JOB QUEUE*****************";
		cout<<"\n1. Add Job in Queue";
		cout<<"\n2. Delete Job from Queue";
		cout<<"\n3. Display Job Queue";
		cout<<"\n4. Exit Application";
		cout<<"\nWhat is your choice::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter Item Name:";
				cin>>j.data;
				cout<<"\nEnter Job priority:";
				cin>>j.priority;
				obj.enQueue(j);
				break;
			case 2:
				obj.dQueue();
				break;
			case 3:
				obj.displayQueue();
				break;
			case 4:
				cout<<"\nGood By!!";
				break;
			
		}
	}
	return 0;
}
