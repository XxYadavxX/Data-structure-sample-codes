 /*
AIM:
Write C++ program for simulating job queue.
Write functions to add job and delete job from queue.

INPUT: 
    1. Job information (ID & Name)
	
OUTPUT:
	a) Add Job in Queue
	b) Delete Job from Queue
	c) Display Queue
	

*/
#include<iostream>
#define MAX 3
using namespace std;

typedef struct Job{
	int ID;
	string name;
	
}JOB;


class Queue{
	private:
		JOB Q[MAX];
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
		
		
		void enQueue(JOB j){
				if(! isQueueFull()){

					if(front == -1){
						front=rear=0;
						Q[rear]=j;
					}
					else
						Q[++rear]=j;
				}
				else
					cout<<"\nQueue is full!!";
		}
		
		
		void dQueue(){
				
				if(!isQueueEmpty()){
					
					if(front == rear){
						cout<<"\n"<<Q[front].ID<<"  is deleted from Queue";
						front=rear=-1;
					}
					else{
						cout<<"\n"<<Q[front].ID<<"  is deleted from Queue";
						front++;
					}	
				}
				else
					cout<<"\nQueue is Empty!!";
		}
		
		
		void displayQueue(){
			int i;
			if(!isQueueEmpty()){
				cout<<"\nJob Queue is:\n";
				for (i=front;i<=rear; i++)
					cout<<"|"<<Q[i].ID<<"-"<<Q[i].name<<"| ";
			}
			else
				cout<<"\n Queue Empty!!";
		}
};


int main(){
	int choice=0;
	JOB j;
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
				cout<<"\nEnter Job ID:";
				cin>>j.ID;
				cout<<"\nEnter Job Name:";
				cin>>j.name;
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
