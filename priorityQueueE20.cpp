#include<iostream>
#define MAX 10
using namespace std;

class Priority_Queue{
	
	private:
		string Queue[MAX];
		int PriorityVal[MAX];
		int front;
		int rear;

	public:
		
		Priority_Queue(){
			front = -1;
			rear = -1;
		}

		bool isEmpty() {	return front == -1;	}

		bool isFull(){	return rear == MAX-1;  }

		void Enqueue(string data, int priority){
			
			if( isFull()){
				cout<<"Queue is full !"<<endl;
			}
			if( isEmpty()){
				front = 0;
				rear = 0;
				Queue[front] = data;
				PriorityVal[front] = priority;
			}
			else{
				int i;
				rear++;
				for( i =rear-1 ; i>=front ; i--){
					if( PriorityVal[i] < priority){
						Queue[i+1] = Queue[i];
						PriorityVal[i+1] = PriorityVal[i];
					}
					else{
						Queue[i+1] = data;
						PriorityVal[i+1] = priority;
						break;
					}
				}
				Queue[i+1] = data;
				PriorityVal[i+1] = priority;
			}
		}

		string Dequeue(){
			
			if( isEmpty()){
				cout<<"Queue is Empty !"<<endl;
			}
			string data = Queue[front];
			if( front == rear ){
				front = -1;
				rear = -1;
			}
			else{
				front++;
			}
			return data;
		}
	
		int getPriority(){
			if( isEmpty()){
				return -1;
			}
			return PriorityVal[front];
		}
		
		void Display(){
			if(isEmpty()){
				cout<<"Queue is Empty !"<<endl;
			}
			else{
				cout<<"Queue is : \nNAME\tPRIORITY"<<endl;
				for( int i = front ; i <= rear ; i++){
					cout<<Queue[i]<<"\t"<<PriorityVal[i]<<endl;
				}
				cout<<endl;
			}
		}							
};

int main(){
	
	Priority_Queue p;
	int ch, priority;
	string name;
	cout<<"Priority : 0 for General CheckUp, 1 for Non Serious , 2 for Serious"<<endl;

	do{
		cout<<"\n----------: MENU :----------"<<endl;
		cout<<"1.Add Patient"<<endl;
		cout<<"2.Remove Patient"<<endl;
		cout<<"3.Display Queue"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"----------------------------"<<endl;
		cout<<"Enter your choice :";
		cin>>ch;
		cout<<endl;

		switch(ch){
			
			case 1:
				cout<<"Enter Patient name :";
				cin>>name;
				cout<<"Enter Priority of patient :";
				cin>>priority;
				p.Enqueue(name, priority);
				cout<<"PAtient added successfully !!"<<endl;
				break;

			case 2:
				priority = p.getPriority();
				name = p.Dequeue();
				cout<<"Patient "<<name<<" is removed !!"<<endl;
				break;

			case 3:
				p.Display();
				break;

			case 4:
				cout<<"Thank You !!"<<endl;
				break;

			default:
				cout<<"Invalid Choice"<<endl;
				break;	
		}
	}while( ch!=4);
	return 0;
}