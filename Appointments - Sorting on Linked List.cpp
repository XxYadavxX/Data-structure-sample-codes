/*
AIM:
Write C++ program for storing appointment schedule for day.
Appointments are booked randomly using linked list.
Set start and end time and min and max duration for visit slot.
Write functions for:
a) Display free slots 
b) Book appointment 
c) Cancel appointment (check validity, time bounds, availability etc.) 
d) Sort list based on time
e) Sort list based on time using pointer manipulation

INPUT: 
    1. Name of visitor
	2. hourOfDay, start and end time 
	3. min and max duration for visit slot

OUTPUT:
	a) Display free slots 
	b) Book appointment
	c) Cancel appointment (check validity, time bounds, availability etc.) 
	d) Sort list based on time
	e) Sort list based on time using pointer manipulation


*/
#include<iostream>
using namespace std;


typedef struct Appointment{
	struct Appointment *prev;
	int tokenID;
	string Name;
	int hourOfDay;
	int startTime;
	int endTime;
	int minDuration;
	int maxDuration;
	bool booked;
	struct Appointment *next;
}APPT;


class AppointmentSchedular{
	private:
		APPT *head,*tail;
		int countID;	
	public:
		AppointmentSchedular(){
			head=NULL;
			tail=NULL;
			countID=0;
		}
		
		
		void addFreeSlot(int hod,int stime,int etime, int min, int max){
			APPT *p;
			p=new APPT;
			p->prev=NULL;
			p->tokenID=++countID;
			p->Name="";
			p->hourOfDay=hod;
			p->startTime=stime;
			p->endTime=etime;
			p->minDuration=min;
			p->maxDuration=max;
			p->booked=false;
			p->next=NULL;
			
			if(head==NULL)
				head=tail=p;
			else{
				tail->next=p;
				p->prev=tail;
				tail=tail->next;
			}
		}
	
		
		void displayList(){
			APPT *cur;
			cur=head;
			cout<<"["<<head<<"]->\n";
			cout<<"\nID\tName\tHoday\tsTime\teTime\tminD\tmaxD\tBooked";
			while(cur != NULL){
				cout<<"\n"<<cur->tokenID<<"\t"<<cur->Name<<"\t"<<cur->hourOfDay<<"\t"<<cur->startTime<<"\t"<<cur->endTime<<"\t"<<cur->minDuration<<"\t"<<cur->maxDuration<<"\t"<<cur->booked;
				cur=cur->next;
			}
			cout<<"\n->NULL";
		}
		
		
		void bookAppointment(int id,string name){
			APPT *cur;
			cur=head;
			while(cur != NULL){
				if(cur->tokenID==id ){
					if(cur->booked ==0){
					cur->Name=name;
					cur->booked=true;
					}
					else
						cout<<"\nSlot already booked";
					break;
				}
				cur=cur->next;
			}
			if(cur == NULL)
				cout<<"\nNo slot "<<id<<" available";	
		}
		
		
		void sortList(){
			APPT *i,*j,*temp;
			temp=new APPT;
			
			for (i=head; i!=NULL; i=i->next){
				
				for (j=i->next;j!=NULL;j=j->next) {
					
					if (i->hourOfDay > j->hourOfDay){
						temp->tokenID=i->tokenID;
						temp->Name=i->Name;
						temp->hourOfDay=i->hourOfDay;
						temp->startTime=i->startTime;
						temp->endTime=i->endTime;
						temp->minDuration=i->minDuration;
						temp->maxDuration=i->maxDuration;
						temp->booked=i->booked;
						
						i->tokenID=j->tokenID;
						i->Name=j->Name;
						i->hourOfDay=j->hourOfDay;
						i->startTime=j->startTime;
						i->endTime=j->endTime;
						i->minDuration=j->minDuration;
						i->maxDuration=j->maxDuration;
						i->booked=j->booked;
						
						j->tokenID=temp->tokenID;
						j->Name=temp->Name;
						j->hourOfDay=temp->hourOfDay;
						j->startTime=temp->startTime;
						j->endTime=temp->endTime;
						j->minDuration=temp->minDuration;
						j->maxDuration=temp->maxDuration;
						j->booked=temp->booked;
						
					}
				}
			}			
		}
		
		
		void sortListPhysical(){
			
		}
};


int main(){
	int choice=0;
	string name;
	int hod;
	int stime;
	int etime;
	int min;
	int max;
	int id;
	AppointmentSchedular sch;
	while(choice != 6){
		cout<<"\n***************APPOINTMENT SCHEDULER*****************";
		cout<<"\n1. Add free slots";
		cout<<"\n2. Display free slots ";
		cout<<"\n3. Book appointment";
		cout<<"\n4. Sort list based on time";
		cout<<"\n5. Sort list based on time using pointer manipulation";
		cout<<"\n6. Exit Application";
		cout<<"\nWhat is your choice::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter hour of a day 24 hours format (0 to 23):";
				cin>>hod;
				cout<<"\nEnter start time of an hour:";
				cin>>stime;
				cout<<"\nEnter end time of an hour:";
				cin>>etime;
				cout<<"\nEnter minimum availability as minutes:";
				cin>>min;
				cout<<"\nEnter minimum availability as minutes:";
				cin>>max;
				sch.addFreeSlot(hod,stime,etime,min,max);
				break;
			case 2:
				sch.displayList();
				break;
			case 3:
				sch.displayList();
				cout<<"\nEnter slot number to be booked :";
				cin>>id;
				cout<<"\nEnter your Name :";
				cin>>name;
				sch.bookAppointment(id,name);
				break;
			case 4:
				sch.sortList();
				break;
			case 5:
				sch.sortListPhysical();
				break;
			case 6:
				cout<<"\nGood By!!";
				break;
			
		}
	}
	return 0;
}
